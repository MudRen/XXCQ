//hsxiaolu��c             ���ź�ɽ--��ʯС·

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
�����Ǻ�ɽС·��ֻ��һ��ͨ���������Ӳݴ�������ʱ����ϤϤ����
�Ĳ�������ż������һ��ֻС��������ǰ�ӹ���С·������������ǰ��ȥ
��ͨ����������ĺ�ɽ��
LONG);
	set("exits", ([
			"northeast" : __DIR__"hsxiaolu3",
			"northwest" : __FILE__,
//			"southwest" : __FILE__,
//			"west" : __FILE__,
//			"east" : __FILE__,
//			"south" : __FILE__,
			"north" : __FILE__,
			"southeast" : __DIR__"shandao3",
	]));
	set("outdoors","����");
	setup();
	replace_program(ROOM);
}
