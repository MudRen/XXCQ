//houyuan.c		�Ĵ����š���Ժ

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
���������Ƹ��Ժ������徰�ĵ�԰����������һ�غ���������
��ˮ���۵����ƣ����ⷺ����׹ɺɺ����ѿ�ƾɣ������к���������
�ţ���Ҷһҡ�������Ƕ�һƬһƬ�ķָ��Ӱ������ͨ�����ŵ��ڷ�
�Ͷ�����
LONG);
	set("exits", ([
			"east" : __DIR__"houroad4",
			"north" : __DIR__"mishi",
	]));
	set("objects", ([__DIR__"npc/tangkun" : 1,]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}