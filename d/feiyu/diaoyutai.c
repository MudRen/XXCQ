// Room: daoyutai.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21

inherit ROOM;

void init();

void create()
{
	set("short", "����̨");
	set("long", @LONG
�߹����֣������ǰ��Ȼ�������������ﱻ��������̨����ž�����
Ϊ������һ��СϪ��Ϫ������һЩ���������ɣ�̨���Ѿ��м������ڴ�
���ˡ�����Ȥ�Ļ���Ҳ�������ԡ�ԶԶ����ȥ�������������е�ɽ�壬ʹ
�˸е��Ŀ�������
LONG
	);
       
	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"shulin",
	]));

	setup();
}

void init()
{
        object me = this_player();
        if (me->query_temp("feiyutask/given")) me->set_temp("di2mark", 1);
        return;
}
