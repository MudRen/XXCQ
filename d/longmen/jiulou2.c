// Room: /city/zuixianlou2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "��¥����");
        set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������߳Ժ�
�������ס�����Ҳ������ٰ�ϲ�����ѳ�������վ��¥��������ֻ������
��������ǽ�Ϲ��ż۸�����(paizi)��
LONG );
        set("valid_startroom",1);
        set("item_desc", ([
                "paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
        ]));
        set("objects", ([
                __DIR__"npc/baobao" : 1,
        ]));
        set("exits", ([
                "down" : __DIR__"jiulou",
//              "east": __DIR__"zxlpath",
        ]));
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

