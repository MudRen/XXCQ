//wzlang2.c		�Ĵ����š�����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ƹ���������ȡ�����ϱ�ĵط��ְ�������࣬ԭ��
���������ŵ��������ڹ����ķ��ľ��ң�û���˸������ﳳ�֡�����
������ͨ����Ϣ�ң��򶫾ͻص�����������
LONG);
	set("exits", ([
			"east" : __DIR__"wzlang1",
			"west" : __DIR__"wzlang3",
			"north" : __DIR__"wselfroom2",
//			"north" : __DIR__"jingshi1",
//			"south" : __DIR__"jingshi2",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}