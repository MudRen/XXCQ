// xj2.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",GRN"С��"NOR);
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ�������������
long);
         set("ourdoors","����Ľ��");
         set("exits",([
             "north" : __DIR__"sq1",
             "east" : __DIR__"houyuan",
]));
	setup();
	replace_program(ROOM);
}
