//shandao2.c		�Ĵ����š���ɽɽ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������ͨ��ɽ����С�����涸�ޱȣ�һ��С�ľͻ�ˤ��ȥ������
�Ǹ������ƵĲ�����������д���Ұ�޵�˺ҧ��������ë���Ȼ����
����������ȫ���ע������Ұ��������
LONG);
	set("exits", ([
			"southwest" : __DIR__"shandao1",
			"eastup" : __DIR__"shandao3",
	]));
	set("area", "����");
	set("objects", ([__DIR__"npc/deer" : 1,__DIR__"npc/yetu" : 1,]));
	setup();
	replace_program(ROOM);
}