// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��谵�������������ǳ����Ŀ�ǽ�Ĵ�������Ҳ��ʣ��ǽ�ϵ�
�Ǹ����ķ����ˡ������ĳ��ȴ�Լ����˯ʮ�����ˣ����������Ĺ�����
�Կ�������û�ж��ٿյ��ˡ���û��˼ϸ�۲죬æ���˸��ط�����������
LONG
	);

	set("no_fight", 1);

	set("sleep_room", 1);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"zoulang7",
	]));

	setup();
	replace_program(ROOM);
}