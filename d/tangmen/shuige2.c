//shuige2.c		�Ĵ����š�ͤ�ˮ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ͤ�ˮ��");
	set("long", @LONG
��������źС����ͤ�ˮ����������źС����Ϊһ�壬ͬ����
����ɫ�Ľ�����ˮ���ı��ϻ��Ÿ�ɫ��ɽˮ��棬��������ǰ������
�Ƹ��ˣ�
LONG);
	set("exits", ([
		"north" : __DIR__"lianyunge",
		"south" : __DIR__"shuige1",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}