//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��®����");
        set ("long", @LONG
������佻���®�Ĵ��ſڣ������ǰ��һ�ȴ󳨵������ţ�͸����
���Կ���һ�����ֵ�Ӱ�ڣ������Ϸ����һ��ľ�ң����顲佻���®����
�������֡������������������������ݵ�ʯʨ�ӣ�һ��佻����ӳֽ���
���������Ž�®�İ�ȫ��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"enter" : __DIR__"qianroad1",
		"eastdown" : "/d/huayang/hhroad",
       ]));

        set("objects", ([
                 __DIR__"npc/zuyuan_q": 1,
	]));

        set("outdoors", "xiao");
        setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;

	if ((!(myfam = (mapping)me->query("family"))
		|| myfam["family_name"] != "佻�����" )
		&& dir == "enter")
	{
        	if(objectp(present("jia ding", environment(me))))
        		return notify_fail("�Ҷ�������ס��ǫ��˵����佻���®�����������������ڣ�\n���ǰ�ʦ�Ļ�"
				+ RANK_D->query_respect(me) +"�������ȥ�ɣ��������ûȤ��\n");
	}

	return ::valid_leave(me, dir);
}