// by ɽèADX @ snow 99-12-4

inherit ROOM;

void create ()
{
	set("short",  "�ٵ�");
	set("long",  @LONG
����һ��������ֱ�Ĺٵ�������·�棬����ݵ���ʮ���ۡ�����ͨ��
�����ǣ�������һ����Ҵ塣
LONG);
	set("exits",  ([
		"west"  :  __DIR__"guandao5",
        "south" : "/d/xiangyang/tulu6",
		"east"  :  __DIR__"guandao3",
                "north" : "/d/item/jianchang",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
