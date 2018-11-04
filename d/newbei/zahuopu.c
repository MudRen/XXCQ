// Room: /welcome/zahuopu.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"�ӻ���"NOR);
	set("long",
"����һ��СС���ӻ��̣�����С�������һ�أ�����һЩ�ճ���Ʒ����\n"
"�ƹ������������һֻ�����ϣ��к��Ź������ˡ���˵˽������Ҳ��һЩ��\n"
"�صĶ�����ǽ������һ�Ź��"+HIM"��guanggao��"NOR+"������Ӧ��������\n"
 );
	set("item_desc", ([
		"guanggao" : "�������"+HIC"list"NOR+"�鿴������۵���ƷƷ"+
			     "��"+HIC"buy"NOR+"����Ʒ��\n"+
			     "���Ȿ�꼱��﹤������ɽ��������\n\n",
	]));
	set("exits", ([
		"west" : __DIR__"beilang2",
	]));
	set("objects", ([
		__DIR__"npc/yang": 1,
	]));
	set("no_fight", 1);
//	set("no_clean_up", 0);
	setup();
}

void init()
{
           add_action("do_job","kan");
}
int do_job(string arg)
{
        object *inv;
        object me;
         int i, jingli;

	me = this_player();
	jingli = ( random(me->query("dex"))/3 );
	inv = all_inventory(me);
	if (jingli <= 0)
		jingli = 5;

	if (me->query("jingli")<=10) {
	message_vision ("��û�������ˣ���ȥ��Ϣ��˯һ�°ɣ�"+HIC"(sleep)\n"NOR, me );
        return 1;
	}
	   //�ж��Ƿ�wield�˹���
	if( (string)(inv[i]->query("id"))=="chaidao" && 
		(int) inv[i]->query("equipped") ) 
	{
		if( !arg || arg!="��" )
			{return notify_fail ("��Ҫ��ʲô��\n");
		}
		else {
			me->add_temp("wancheng", jingli);
			me->add("jingli", -jingli);
			me->add("combat_exp", jingli);
			me->add("potential", (jingli/2));
			message_vision ("$N����񵶣���ľͷ������\n", me );
			if (me->query_temp("wancheng") >= 100)
			{
				me->set_temp("renwu",100);   //��100��ʾ�������
				return notify_fail (WHT"����Ի�ȥ�����ˣ�(ask moto about ok)\n"NOR);
				}
			}
	}
	else {
		return notify_fail ("�������ô������������\n");
		}
        return 1;
}

int valid_leave(object me, string dir)
{
         if ( (dir == "west") &&
		(me->query("wancheng") >= 100) )
	{
		if ( !present("chaidao", me) ) {return 1;}
			message_vision ("$N�������еĲ񵶡�\n", me);
		destruct(present("chaidao", me));
	}
	return ::valid_leave(me, dir);
}
