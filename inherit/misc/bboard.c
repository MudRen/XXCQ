// bboard.c
// colored by ReyGod in 1/10/1997

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit ITEM;
inherit F_SAVE;

void done_post(object me, mapping note, string text);
string replace_color(string, int);
void setup()
{
	string loc;
	string bname,bid;
	bname=query("name");
	bid=query("id");
	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	if(!query("board_id"))
		set("board_id","kedian_b");
	restore();
	if(!query("board_id"))
		set("board_id","kedian_b");
	set_name(bname,({ bid }));
	if(stringp(loc))
		set("location",loc);
}

void init()
{
	if(query("wiz_board"))//���������wiz_board����˵����Ҫ����
	{
		if(wiz_level(this_player())<wiz_level("(angel)"))//�������С��angel������ж��Ƿ�����Ȩ
		{
			if(!this_player()->query("wboard_readable"))
			//���δ����wboard_readable���Լ�δ��Ȩ���򲻿����Ķ�
			{
				write("��û�б���Ȩ������������԰档\n");
				return ;
			}
		}
	}
	add_action("do_post", "post");
	add_action("do_read", "read");
	add_action("do_discard", "discard");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;
	setup();
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ û���κ����� ]";

	if( this_player() ) {
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		return sprintf(HIC+"%s" +NOR+" [ %d �����ԣ�"+HIY+"%d"+NOR+" ��"+HIR+"δ��"+NOR+"]", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s [ %d ������ ]", ::short(), sizeof(notes));
}

string long()
{
	mapping *notes;
	int i, last_time_read;
	string msg;
	setup();
	notes = query("notes");
	msg = query("long");
	msg = msg + "���԰��ʹ�÷������ help board��\n";
	if( !pointerp(notes) || !sizeof(notes) ) return query("long");

	last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
	for(i=0; i<sizeof(notes); i++)
		msg += sprintf("%s[%2d]" NOR "  %-40s %12s (%s)\n",
			( notes[i]["time"] > last_time_read ? HIY: ""),
			i+1, notes[i]["title"], notes[i]["author"], ctime(notes[i]["time"])[0..15] );
	return msg;
}

int do_post(string arg)
{
	mapping note;
	if(!arg) return notify_fail("������ָ��һ�����⡣\n");
	
	note = allocate_mapping(4);
	note["title"] = replace_color(arg,1);
	note["author"] = this_player()->name(1);
	note["authorid"] = this_player()->query("id");
	note["time"] = time();
	this_player()->edit( (: done_post, this_player(), note :) );
	return 1;
}

// This is the callback function to process the string returned from the
// editor defined in F_EDIT of player object.
void done_post(object me, mapping note, string text)
{
	mapping *notes;

	note["msg"] = replace_color(text,1);
	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({ note });
	else
		notes += ({ note });

	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(notes) > BOARD_CAPACITY )
		notes = notes[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];

	set("notes", notes);
	tell_object(me, "������ϡ�\n");

	save();
	return;
}

int do_read(string arg)
{
	int num;
	mapping *notes, last_read_time;
	string myid;

	last_read_time = this_player()->query("board_last_read");
	myid = query("board_id");
	notes = query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("���԰���Ŀǰû���κ����ԡ�\n");

	if( !arg ) return notify_fail("ָ���ʽ��read <���Ա��>|new|next\n");
	if( arg=="new" || arg=="next" ) {
		if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
			num = 1;
		else
			for(num = 1; num<=sizeof(notes); num++)
				if( notes[num-1]["time"] > last_read_time[myid] ) break;
			
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("��Ҫ���ڼ������ԣ�\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("û���������ԡ�\n");
	num--;
	this_player()->start_more( sprintf(
"[%d] %-40s %s(%s)(%s)\n----------------------------------------------------------------------\n",
		num + 1, replace_color(notes[num]["title"],1), notes[num]["author"], notes[num]["authorid"],
		 ctime(notes[num]["time"])[0..9]) + replace_color(notes[num]["msg"],1), );

	// Keep track which post we were reading last time.
	if( !mapp(last_read_time) )
		this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
	else 
		if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
			last_read_time[myid] = notes[num]["time"];

	return 1;
}


int do_discard(string arg)
{
	mapping *notes;
	int num;

	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("ָ���ʽ��discard <���Ա��>\n");
	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("û���������ԡ�\n");
	num--;
	if( notes[num]["authorid"] != (string) this_player(1)->query("id")
	&&	(string)SECURITY_D->get_status(this_player(1)) != "(admin)" 
	&&      (string)SECURITY_D->get_status(this_player(1)) != "(hufa)"
	&&      (string)SECURITY_D->get_status(this_player(1)) != "(arch)")
		return notify_fail("������Բ�����д�ġ�\n");

	if(num == 0)
		notes = notes[num+1..sizeof(notes)-1];
	else
		notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
	set("notes", notes);
	save();
	write("ɾ���� " + (num+1) + " ������....Ok��\n");
	return 1;
}

string replace_color(string msg,int flag)
{
	msg = replace_string(msg, "$BLK$", flag?BLK:"");
	msg = replace_string(msg, "$RED$", flag?RED:"");
	msg = replace_string(msg, "$GRN$", flag?GRN:"");
	msg = replace_string(msg, "$YEL$", flag?YEL:"");
	msg = replace_string(msg, "$BLU$", flag?BLU:"");
	msg = replace_string(msg, "$MAG$", flag?MAG:"");
	msg = replace_string(msg, "$CYN$", flag?CYN:"");
	msg = replace_string(msg, "$WHT$", flag?WHT:"");
	msg = replace_string(msg, "$HIR$", flag?HIR:"");
	msg = replace_string(msg, "$HIG$", flag?HIG:"");
	msg = replace_string(msg, "$HIY$", flag?HIY:"");
	msg = replace_string(msg, "$HIB$", flag?HIB:"");
	msg = replace_string(msg, "$HIM$", flag?HIM:"");
	msg = replace_string(msg, "$HIC$", flag?HIC:"");
	msg = replace_string(msg, "$HIW$", flag?HIW:"");
	msg = replace_string(msg, "$NOR$", flag?NOR:"");
	msg = replace_string(msg, "$BLINK$", flag?BLINK:"");
	if(flag) msg+=NOR;
	return msg;
}
