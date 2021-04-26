// message.c

#include <ansi.h>
#include <dbase.h>

#define MAX_MSG_BUFFER 500

nosave string *msg_buffer = ({});
nosave int written = 0;

// status of written
#define NONE		    0
#define PROMPT_WRITTEN	  1
#define COMMAND_RCVD	    2

// What's about flag variable: written ?
// After I written a prompt ">" on the screen, mabye the
// user has not input command but receive message. So the
// screen may be show as "> YOU ARE RECEIVE MESSAGE"
// that's bad! On this case, I want clear the "> ", so I
// define a flag variable. After I written the prompt I will
// set it, & when the user receive in a command he will call
// the function clear written to tell me that.

string prompt()
{
	object me;
	int env;
	string p;
	me=this_object();
	if (query("env/no_prompt") || !stringp(p = query("env/prompt")))
		return HIY+">"+NOR;
	p=clean_color(p);
	switch(lower_case(p))
	{
	case "time":
		p=(env=(int)me->query("env/time_format"))?(HIY"["+HIW+CHINESE_D->chinese_time(env,(string)localtime(time()))	+HIY"]"NOR):(HIC + ctime(time())[11..18]);
		break;
	case "date":
		p = HIC + ctime(time())[0..9];
		break;
	case "mud":
		p = HIC + NATURE_D->game_time();
		break;
	case "tell":
		if(!stringp(p=me->query_temp("reply")))
			p="��";
		else
			p=HIY"["+HIW+p+HIY"]"NOR;
		break;
	case "hp0":
		p = HIG + sprintf("%d/%d", query("jing"), query("qi"));
		break;
	case "hp1":
		p=HIW+"��:"+me->query("qi")+"|��:"+me->query("jingli");
		break;
	case "hp2":
		p=HIW+"��:"+me->query("qi")+"|��:"+me->query("jingli")+
			"|����:"+me->query("combat_exp")+"|Ǳ��:"+
			((int)me->query("potential") - (int)me->query("learned_points"));
		break;
	case "path":
		if (! wizardp(this_object()) || wiz_level(this_object()) < 3)
			break;
		p = HIC + query("cwd")[0..<2];
		break;
	default:
		break;
	}
	p += HIY "> " NOR;
	return p;
}

void receive_message(string msgclass, string msg)
{
	string subclass, *ch;
	msg = CONVERT_D->output(msg,this_object());
	if( !interactive(this_object()) ) {
		this_object()->relay_message(msgclass, msg);
		return;
	}

	if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 ) {
		switch(subclass) {
			case "channel":
				if( !pointerp(ch = query("channels"))
				||	member_array(msgclass, ch)==-1 )
					return;
				break;
			case "outdoor":
				if( !environment() || !environment()->query("outdoors") )
					return;
				break;
			case "system":
				break;
			default:
				error("Message: Invalid Subclass " + subclass + ".\n");
		}
	}

	if (query_temp("block_msg/all") || query_temp("block_msg/" + msgclass))
		return;

	if (in_input(this_object()) || in_edit(this_object()) ||
	    this_object()->is_attach_system() && msgclass != "system")
	{
		if (sizeof(msg_buffer) < MAX_MSG_BUFFER)
			msg_buffer += ({ msg });
	} else
	{
		if (written && ! this_object()->is_attach_system())
		{
			msg = ESC"[256D" ESC "[K" + msg +
			      (written == COMMAND_RCVD ? (written = NONE, "")
						       : prompt());
		}
		receive(msg);
	}
}

void clear_written()
{
	written = COMMAND_RCVD;
}

int is_waiting_command()
{
	return (written == PROMPT_WRITTEN);
}

void write_prompt()
{
	if( sizeof(msg_buffer) ) {
		receive(BOLD "[����ʱ�ݴ�ѶϢ]\n" NOR);
		for(int i = 0; i < sizeof(msg_buffer); i++)
			receive(msg_buffer[i]);
		msg_buffer = ({});
	}

	if (! living(this_object()))
		return;

	written = PROMPT_WRITTEN;
	if (this_object()->is_attach_system())
		receive(HIR "ִ����" NOR "> ");
	else
		receive(ESC "[256D" + prompt());
}

void receive_snoop(string msg)
{
	receive("%" + msg);
}
