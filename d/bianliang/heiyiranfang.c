// heiyiranfang.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "����Ⱦ��");
	set("long", @LONG
����Ⱦ�����Ƴ���Ԫʱ�ڽ���ģ����䴴ʼ��Ƚ���¶�������ֱ����
�����Ⱦ��������ʤ��ǰ����һ�߽������Ϳ�����ʮ�����ڴ�Ժ����ææ
µµ�������ġ�ϴ���ġ�Ⱦ���ġ������ĸ���æ�š���Ҫ���в�ҪȾ����
�������һ������ʧ���ġ�
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"east" : __DIR__"huangshanjie3",
	]));

	set("objects", ([
		__DIR__"npc/yiran" : 1,
	]));

	set("area", "����");

	setup();

	replace_program(ROOM);
}