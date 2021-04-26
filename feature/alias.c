// alias.c
// From ES2
// Modified for XKX by Xiang (12/15/95)

#include <ansi.h>
#define MAX_REPEAT 60
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10

mapping alias;
nosave int last_cmd;
nosave string *history, last_input;
int jinbi(object ob)
{
	//�ú�����ob�ؽ��գ�
	object room=find_object("/d/sroom/jianyu");
	if(!objectp(room))
		room=load_object("/d/sroom/jianyu");
	if(!objectp(room))
		return 0;
	if(ob->is_ghost())
		return 0;
	return ob->move(room);
}
string process_input(string str)
{
	string *args, cmd, argstr;
	int i, j;

	notify_fail("ʲô��\n");
	this_object()->clear_written();
	if (! living(this_object())) return "";

	// attach system ?
	if (this_object()->is_attach_system())
	{
		this_object()->detach_system();
		tell_object(this_object(), HIR "�û���ֹ�˵�ǰִ�еĽ��̡�\n" NOR);
	}

	if (str == "") return str;

	if (! wizardp(this_object()))
	{
		if (this_object()->reject_command())
		{
			message_vision(HIR"\n\nͻȻ�Ա����˴��һ����ԭ�����������ˡ�Сѩ������\n\n"NOR
	   	            HIW "ֻ��һ�Ŵ����������������$N���䵽�Ĵ����������ˣ���\n" NOR, this_object());
			this_object()->unconcious();
			this_object()->apply_condition("jianyu",20);
			call_out("jinbi",10,this_object());
			message_vision(HIW "ֻ��ɽèһ��ץס$N��Ѻ��������......\n\n" NOR, this_object());
			return "";
		}
	}
	//��ʷ������֣�������չ����
	if( str[0]=='!' ) {
		if( pointerp(history) && sizeof(history) ) {
			if( sscanf(str, "!%d", i) )
				str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
			else
				str = history[last_cmd];
		} else
			return "";
	} else {
		if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
		last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
		history[last_cmd] = str;
	}
	//alias������������֣�������չ����
	if (mapp(alias))
	{
		if (! undefinedp(alias[str]))
			return replace_string( alias[str], "$*", "" );

		if (sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]))
		{
			cmd = replace_string( alias[cmd], "$*", argstr );
			args = explode(argstr, " ");
			if( (j = sizeof(args)) )
				for(i=0; i<j; i++)
					cmd = replace_string(cmd, "$" + (i+1), args[i]);
			return cmd;
		}
	}

	return (string)ALIAS_D->process_global_alias(str);
}

int set_alias(string verb, string replace)
{
	if (! replace)
	{
		if (mapp(alias)) map_delete(alias, verb);
		return 1;
	}
	else
	{
		if (!mapp(alias)) alias = ([ verb:replace ]);
		else if (sizeof(alias) > MAX_ALIASES)
			return notify_fail("���趨�� alias ̫���ˣ�����ɾ��һЩ�����õġ�\n");
		else alias[verb] = replace;
		return 1;
	}
}

mapping query_all_alias()
{
	return alias;
}
