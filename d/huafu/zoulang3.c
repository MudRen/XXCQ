// zoulang3.c ����3
// mlf��ƣ�lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"�������Ӵ��������������ȣ�վ�������ϣ���ֻ��������ϰϰ���細
¶����Զ��������������������˱ǡ��㲻�ɵ�ͣ�½Ų���ϸϸ�������
��լ��������\n"
	);
	set("valid_startroom",1);
	set("outdoors","huafu");
	set("exits",([
		"east" : __DIR__"dating",
		"west" : __DIR__"xiting",
	]));
	setup();
	replace_program(ROOM);
}
