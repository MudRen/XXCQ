// zoulang4.c ����4
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"վ�������ϣ����������߼����߶�ȥ���ڶ�����һ����ӣ����洫
������߳�ȵ�������������ǻ����������������ζ����ĵ��Ӷ��ڴ˴���
ϰ�似��\n"
	);
	set("valid_startroom",1);
	set("outdoors","huafu");
	set("exits",([
		"west" : __DIR__"dating",
		"east" : __DIR__"liangong",
	]));
	setup();
	replace_program(ROOM);
}

	
