// Room: jzroad3.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����⣬��Ȼվ��һ�����ӣ�����ɭɭ�����ӱ��ϣ�ƾ��һ��ɷ����
�����ǵ�ɽ��·����������һƬɭ���ˡ�
LONG );
        set("exits", ([ 
            "west"   : __DIR__"shulin1",
            "eastup"  : __DIR__"jzroad4",
            "southwest" : __DIR__"jzroad2",
		]));
        set("objects", ([
		     "/d/feiyu/npc/chuwangong" : 1,
        ]));


        setup();
        replace_program(ROOM);
}

