//ycailiao.c		�Ĵ����š����Ϸ�

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���Ϸ�");
	set("long", @LONG
���������Ŵ�������ҩ����ϵķ��䡣���Ű���������˫������
�����ַ�֮�⣬�������Ƹ���ҩ��Ĳ��ϣ��ǹ�����û��������ȡ��
�ģ�����ͨ��ҩ����ϣ�����Щ�����߳����ŵ�ʱ�򣬶��������ľ�
��������������һ����ʯС·��
LONG);
	set("exits", ([
			"northeast" : __DIR__"houroad2",
	]));
	set("objects", ([__DIR__"npc/yjiading" : 1,]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}