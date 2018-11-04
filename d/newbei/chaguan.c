// Room: /welcome/chaguan.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"��ѩ���"NOR);
	set("long",
"��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ��\n"
"�ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ����������ƹʺ�ҥ�ԣ�\n"
"�����Ǹ������ڡ�ǽ������һ�Ź��"+HIC"(guanggao)\n"NOR
 );
	set("item_desc", ([
		"guanggao" : "�������"+HIC"list"NOR+"�鿴������۵���Ʒ"+
			     "��"+HIC"buy"NOR+"����Ʒ��\n"+
			     "���Ȿ�꼱��﹤������ɽ��������\n\n",
	]));
	set("no_fight", 1);
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"beilang1",
	]));
	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
	]));
	setup();
}

void init()
{
           add_action("do_job","shao");
}
int do_job(string arg)
{
        object *inv;
        object me;
         int i, jing;

	me = this_player();
	jing = ( random(me->query("dex"))/3 );
	inv = all_inventory(me);
	if (jing <= 0)
		jing = 5;

	if (me->query("jingli")<=10) {
	message_vision ("��û�������ˣ���ȥ��Ϣ��˯һ�°ɣ�"+HIC"(sleep)\n"NOR, me );
        return 1;
	}
	   //�ж��Ƿ�wield�˹���
     if( (string)(inv[i]->query("id"))=="shanzi" && 
		(int) inv[i]->query("equipped") ) 
	{
		if( !arg || arg!="ˮ" )
			{return notify_fail ("��Ҫ��ʲô��\n");
		}
		else {
			me->add_temp("wancheng", jing);
			me->add("jingli", -jing);
			me->add("combat_exp", jing);
			me->add("potential", (jing/3));
			message_vision ("$N�������ӣ���¯��������ȣ�����ˮ��\n", me );
			if (me->query_temp("wancheng") >= 100)
			{
				me->set_temp("renwu",100);   //��100��ʾ�������
				return notify_fail (WHT"ˮ�տ��ˣ�����Ի�ȥ�����ˣ�(ask moto about ok)\n"NOR);
				}
			}
	}
	else {
		return notify_fail ("�������ô�Ȼ����촵��\n");
}
         return 1;
 }

 int valid_leave(object me, string dir)
 {
         if ( (dir == "east") &&
                 (me->query("wancheng") >= 100) )
         {
                 if ( !present("shanzi", me) ) {return 1;}
                         message_vision ("$N�������е����ӡ�\n", me);
                         destruct(present("shanzi", me));
         }
         return ::valid_leave(me, dir);
 }

