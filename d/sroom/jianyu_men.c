// Room: /d/gvmt/jianyu_do.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����Ǽ������ţ����ںڳ����ģ�������ɭ�ֲ�����ʱ����΢��
������������Լ���ƺ�����Ƥ�޿����������ֱ���������ͷ��
���ϱߵĴ�������ȥ��
LONG
	);
	set("exits",([
		"south":"/d/bianliang/guangming",
	]));
	set("objects",([
		__DIR__"npc/yuzu":1,
	]));
	setup();
	replace_program(ROOM);
}
