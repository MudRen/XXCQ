//wting.c		�Ĵ����š���ƫ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ƫ��");
	set("long", @LONG
���������Ƹ������ƫ����һЩ���ŵ���ϲ�������ﺣ����գ�
������̸�����ڰ������������Σ�����Ϫ����������ľ�дС���˵��
������Ư������λŮ���ӣ����������ǻ���ĬĬ��˼������Զ������
�ɡ�
LONG);
	set("exits", ([
			"east" : __DIR__"lianyunge",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}