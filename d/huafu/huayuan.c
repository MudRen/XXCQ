// huayuan.c ��԰
// mlf��ƣ�lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","��԰");
        set("long",
"�����ǻ�������Ļ�԰�����ڷ��ζ��������ڶ࣬�������ﲻ������
���滨��ݣ��ļ����������涷���������������ǻ����Ĵ��������Ͽ���
�������ϵ�������\n"
	);
	set("outdoors","huafu");
	set("exits",([
                "out" : __DIR__"menfang",
		"north" : __DIR__"dating",
		"southeast" : __DIR__"dongting",
		"west" : __DIR__"zaofang",
	]));
	set("valid_startroom",1);
	setup();
	replace_program(ROOM);
}
