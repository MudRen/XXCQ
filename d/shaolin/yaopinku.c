// Room: /d/shaolin/yaopinku.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ҩƷ��");
	set("long", @LONG
������ȫ��ɮ������ҩƷ�ĵط��������������Ź�ŨŨ��ҩζ����ǽ
��һ���Ÿ߼�������ҩ��ÿ��ҩ�����ϰٸ�װҩ��С���룬��������
����������ĸ��ֲ�ͷҩ��������ǽ�߷��Ÿ��޴�İ���ɫɼľҩ����
�����Ÿ����з���ӡǩ�Ĵ������һλ����ɮ��������æµ�ų���ҩƷ��
��ҩ������
LONG );
	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"fangjuku",
	]));

	set("objects",([
		__DIR__"npc/tiehui" : 1,
	]));

	setup();

	replace_program(ROOM);
}

