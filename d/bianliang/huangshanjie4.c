// huangshanjie4.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "������");
	set("long", @LONG
��νֳ�������壬ֻ����������������Ҵ�����ԭ���ֵ���������
����פ�Ǿ�Ӫ�����ڵأ���Ϊ�Ǿ�����������裬����û����ͨ���ո���
����ͣ������Ҳ����߿��ɡ�
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"north" : __DIR__"huangshanjie3",
		"south" : __DIR__"huangshanjie5",
		"west" : __DIR__"bingying1",
		"east" : __DIR__"bingying2",
	]));

	set("outdoors", "bianliang");
	set("area", "����");

	setup();

	replace_program(ROOM);
}