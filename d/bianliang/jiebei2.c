// baikudajie5.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�籮");
	set("long", @LONG
����տտ�����ǰֻ��һƬ���ߣ��������ڽ��ŵ�ʩ���У�������
��һ����ĺ�����籮������д�У���ǰ��ʩ�����ÿͻ�ͷ�����˸���
�֣����������������ǹ����ܼ౿С����������ֻ�ܻ�ͷ�ˡ�
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"west" : __DIR__"huangkudajie6",
	]));

	set("outdoors", "bianliang");

	set("area", "����");

	setup();

	replace_program(ROOM);
}