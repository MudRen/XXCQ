// Room: jzroad4.c


inherit ROOM;

void create()
{
        set("short", "�ͱ�");
        set("long", @LONG
�������ͱڱߵ�С·�ϡ�һ�������ܵĴ��֣����ȴ�Ǽ���Ķ��ڡ�
ɽ������������Ҫ���������ȥ��
LONG );
        set("exits", ([ 
            "westdown" : __DIR__"jzroad3",
            "northup"  : __DIR__"houshan",
        ]));
        set("outdoors", "feiyu");

		setup();
        replace_program(ROOM);
}

