// Room: ��ʯ·
// Date: by godzilla 1999.11.18

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
һ������ʯ���ɵĴ�������������Ѿã��ּ��������޲����Ѿ�
��ÿӿ����ݣ�������ƽ�ˣ������Ӳݴ�����ֻ����������������ɨ
��Ҷ�����߾���ǰԺ�ˡ�
LONG );
        set("outdoors", "tianyu");
	set("exits", ([
	        "south" : __DIR__"damen", 
		"north"  : __DIR__"qianyuan",
	]));
	set("objects",([
	        __DIR__"npc/puren" : 1,
	        ]));
	setup();
	replace_program(ROOM);
}
