// Room: ����
// Date: by godzilla 1999.11.18

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ӳݴ�����������ǰ߰ߣ������ܾͶ�û���������ˣ�
��������һ����ң����顾�����š���
LONG );
        set("outdoors", "tianyu");
	set("exits", ([
            "south" : "/d/xiangyang/tulu5",
		"north"  : __DIR__"qingshilu",
	]));
	setup();
	replace_program(ROOM);
}
