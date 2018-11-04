// Room: /welcome/yaopu.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"��ѩҩ��"NOR);
	set("long",
"����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С\n"+
"������ɢ�������ġ�һ��С���վ�ڹ�̨���к��Ź˿͡�ǽ������һ��\n"+
"���"+HIM"��guanggao��"NOR+"������Ӧ��������\n"
 );
	set("item_desc", ([
		"guanggao" : "�������"+HIC"list"NOR+"�鿴������۵�ҩƷ"+
			     "��"+HIC"buy"NOR+"��ҩƷ��\n"+
			     "���Ȿ�꼱��﹤������ɽ��������\n\n",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"nanlang2",
	]));
	set("no_fight", 1);
	setup();
}

void init()
{
           add_action("do_job","chong");
}
int do_job(string arg)
{
        object *inv;
        object me;
         int i, jingli;
	me = this_player();
	jingli = ( random(me->query("con"))/3 );
	inv = all_inventory(me);
	if (jingli <= 0)
		jingli = 5;

	if (me->query("jingli")<=10) {
	message_vision ("��û�������ˣ���ȥ��Ϣ��˯һ�°ɣ�"+HIC"(sleep)\n"NOR, me );
        return 1;
	}
	   //�ж��Ƿ�wield�˹���
	if( (string)(inv[i]->query("id"))=="shichu" && 
		(int) inv[i]->query("equipped") ) 
	{
		if( !arg || arg!="��ҩ" )
			{return notify_fail ("��Ҫ��ʲô��\n");
		}
		else {
			me->add_temp("wancheng", jingli);
			me->add("jingli", -jingli);
			me->add("combat_exp", jingli);
			me->add("potential", (jingli/2));
			message_vision ("$N����ʯ�����������Ų�ҩ��\n", me );
			if (me->query_temp("wancheng") >= 100)
			{
				me->set_temp("renwu",100);   //��100��ʾ�������
				return notify_fail (WHT"����Ի�ȥ�����ˣ�(ask moto about ok)\n"NOR);
				}
			}
	}
	else {
		return notify_fail ("�������ô����ҩ����ȭͷ����\n");
		}
        return 1;
}
int valid_leave(object me, string dir)
{
         if ( (dir == "east") &&
		(me->query("wancheng") >= 100) )
	{
		if ( !present("shichu", me) ) {return 1;}
			message_vision ("$N�������е�ʯ�ơ�\n", me);
			destruct(present("shichu", me));
	}
	return ::valid_leave(me, dir);
}
