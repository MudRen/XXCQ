// xj1.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",GRN"С��"NOR);
         set("long",@long
һ�����������ö���ʯ�̳ɵ�С��, ·������������, һ����ɽʯ��ľ
��׺�����С�������ʯ���ϣ�ž�žવķ�������������������ȥ������
С�������졣
long);
         set("ourdoors","����Ľ��");
         set("exits",([
             "west" : __DIR__"xs",
             "east" : __DIR__"xt",
]));
	setup();
	replace_program(ROOM);
}
