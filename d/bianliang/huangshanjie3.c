// huangshanjie3.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "������");
	set("long", @LONG
·���Ļ�������а�����ʷ�����ֺ��ˣ��ϵ���ٹ��ˡ�����������
�䣬ֻҪ��Ǯ����ϲ���������������������һ���裬ϴ��һ���ƣ����
·������һ����Ⱦ��������Ⱦ�Ĳ�ȫ��������
LONG);	
	set("valid_startroom",1);

	set("exits", ([
//		"north" : __DIR__"huangshanjie2",
		"north" : __DIR__"jiebei4",
		"south" : __DIR__"huangshanjie4",
		"west" : __DIR__"heiyiranfang",
		"east" : __DIR__"zaotang",
	]));

//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));

	set("outdoors", "bianliang");
	set("area", "����");

	setup();

	replace_program(ROOM);
}