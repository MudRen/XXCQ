// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "Ȯ����");
	set("long", @LONG
������˵��佻�����֮һ������С��װ����ȫ���ܺ������������Ტ
�ۣ�����ֻ���ǿ���ұ�����������ݡ�ʮ��������ĵ��ӱ��ű�����ǽ
����Ƭ����Ϣ����ȥ����͹����ĵ�����������ȥ��������һ�еľ���Ȯ
����鳤�����¡�
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"southyuan",
	]));

        set("objects", ([
		"/kungfu/class/huanhua/ruan" : 1,
	]));

	setup();
	replace_program(ROOM);
}