// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ɷ���");
	set("long", @LONG
�߽��ɷ��ã���ᷢ��������Ȼû�ж�ô�ĺ�����������͸��һ����
�¡����ţ����˸е����ʡ�ǡ�⣬ʮ���趡�㻨ʹ�ÿ����������ŵ�����
������ʮ����Ů��վ�����ԣ�һ����Ӣ�˲���������������ü��һ������
Ů��վ����ǰ�����Ź�����
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"east" : __DIR__"northyuan",
	]));

        set("objects", ([
		"/kungfu/class/huanhua/hua" : 1,
	]));

	setup();
	replace_program(ROOM);
}