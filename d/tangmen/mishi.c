//mishi.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "����");
	set("long", @LONG
����һ�����ҡ���˵���ŵİ����Ʒ��Լ���ҩ���������ղ�����
���������ʲô��û�У���֪�����Ƿ���ʵ����ʱ��һ����ζ����
�����������㣬���ǳ������������������ֻ��һ�ָо����ѵ�����
��ζ������������ľ�������������������������ŵĺ�Ժ��
LONG);	
	set("exits", ([
		"south" : __DIR__"houyuan",
	]));
	setup();
	replace_program(ROOM);
}