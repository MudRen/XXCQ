// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������Ϊ���ϰ��ĳ��ȱȺ������ĳ��ȸ����۵�ԭ��ɣ�����Ҳ����
������˾��������ھ����ȸе�������泩����Ϊ����ĺ��濪��������
�ĺɻ�����������Ľ������ǹ�������Ҵ�С����ڶ����¥�Ͽ���
���ĺ����ˡ�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"jqlang_1",
		"northwest" : __DIR__"jqlang_3",
		"south" : __DIR__"guanyu",
	]));

        set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}