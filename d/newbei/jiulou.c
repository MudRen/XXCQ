// Room: /welcome/jiulou.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"����¥"NOR);
	set("long",
"��Բ����������������¥����˵�����˲�֪�����˲�����������ѧʿ��\n"
"�ε��ˣ�������¥�Ļ�����޲����ڣ���ȻΪ�����ң�����һ�δ��麣�ڵ�\n"
"�ѻ����Ӵ�����¥��������¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ�����\n"
"�ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����������ǽ������һ�Ź��"+HIM"(guanggao)\n"NOR
 );
	set("item_desc", ([
		"guanggao" : "�������"+HIC"list"NOR+"�鿴������۵���Ʒ"+
			     "��"+HIC"buy"NOR+"����Ʒ��\n"+
			     "���Ȿ�꼱��﹤������ɽ��������\n\n",
	]));
	set("exits", ([
		"east" : __DIR__"nanlang1",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("no_fight", 1);
//	set("no_clean_up", 0);
	setup();
}

void init()
{
           add_action("do_job","qie");
}
int do_job(string arg)
{
        object *inv;
        object me;
         int i, jingli;

	me = this_player();
	jingli = ( random(me->query("str"))/3 );
	inv = all_inventory(me);
	if (jingli <= 0)
		jingli = 5;

	if (me->query("jingli")<=10) {
	message_vision ("��û�������ˣ���ȥ��Ϣ��˯һ�°ɣ�"+HIC"(sleep)\n"NOR, me );
        return 1;
	}
	   //�ж��Ƿ�wield�˹���
	if( (string)(inv[i]->query("id"))=="caidao" && 
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
			message_vision ("$N����˵����ڰ��������Ųˣ�\n", me );
			if (me->query_temp("wancheng") >= 100)
			{
				me->set_temp("renwu",100);   //��100��ʾ�������
				return notify_fail (WHT"����Ի�ȥ�����ˣ�(ask moto about ok)\n"NOR);
				}
			}
	}
	else {
		return notify_fail ("�������ô�вˣ����ֿ���\n");
		}
        return 1;
}

int valid_leave(object me, string dir)
{
         if ( (dir == "east") &&
		(me->query("wancheng") >= 100) )
	{
		if ( !present("caidao", me) ) {return 1;}
			message_vision ("$N�������еĲ˵���\n", me);
			destruct(present("caidao", me));
	}
	return ::valid_leave(me, dir);
}
