// Room: /city/chouduanhang.c
// YZC 1995/12/04 

#include YIZHAN
inherit ROOM;

void create()
{
	set("short", "��ɽ��վ");
	set("long", @LONG
����һ��������͵�С��������������ɽ������һ���ľ����洫
��������˻������̨��������ǰ����ȴû�����ں��档���������������
��һ��(gu che)�ɡ�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"shijie1",
	]));

	setup();
}
