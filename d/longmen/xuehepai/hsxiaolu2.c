//hsxiaolu��c             ���ź�ɽ--��ʯС·

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
�����Ǻ�ɽС·����·Խ��Խխ��ɽʯ������״��Ȯ�ݣ���ʯ���Ľ�
��ʹ��ʹ�ģ���ʱ��Զ������������Х������ͷƤ���飬С·����������
��ǰ��ȥ��ͨ����������ĺ�ɽ��
LONG);
	set("exits", ([
		"south" : __DIR__"hsxiaolu3",
		"west" : __DIR__"hsxiaolu4",
		"southeast" : __FILE__,
		"northeast" : __FILE__,
//		"southwest" : __FILE__,
//		"northwest" : __FILE__,
//		"east" : __FILE__,
//		"north" : __FILE__,
	]));
         set("outdoors","����");
	setup();
	replace_program(ROOM);
}
