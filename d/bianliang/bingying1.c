// bingying1.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "��Ӫ����");
	set("long", @LONG
�����������س�פ������˧Ӫ�أ������ľ�����פ���ڳ������ܡ���
֧���ӱ����������־���һ֧��ʵ����ȴ����ү���ױ������ﲻ�ɾ�����
�����뿪Ϊ�פ���ܱ���������ھ�Ӫ���档
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"east" : __DIR__"huangshanjie4",
		"west" : __DIR__"bingying11",
	]));

	set("objects", ([
		__DIR__"npc/bing1" : 1,
		__DIR__"npc/bing2" : 1,
	]));

	set("outdoors", "bianliang");
	set("area", "����");

	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if (dir == "west" ) 
	{
		if(objectp(present("shi bing", environment(me))))
			return notify_fail("ʿ����ǹ��ס��������Ҫ����������Ӫ����Ҳ�Ҵ�������\n");
	}

	return ::valid_leave(me, dir);
}