
inherit ROOM;

void create()
{
        set("short", "���ž�¥");
        set("long", @LONG
Ϊ�˷������ߵ����ӣ���֪��˭���⽨��һ����¥�����Ǻ����۹⡣
��������������Ⱥ��֪���������Ƕ�ô�ĺ����Щ���Ӷ����ȥ������
���οͶ��������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����������
LONG );
        set("valid_startroom",1);
        set("exits", ([
                "north" : __DIR__"xijie",
                "up" : __DIR__"jiulou2",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer2" : 1,
        ]));
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

