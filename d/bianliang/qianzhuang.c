// Room: /city/qianzhuang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "Ǯׯ");
        set("long", @LONG
����һ�����ֺŵ�Ǯׯ���ϰ��Ǿ������������˸߼�Ѫ���ϰ壬��Ϊ
���ϰ��ۺ��ʵ�������ǲ�Ϊ��֪�ĺ�̨��û�˻ỳ��Ǯׯ������������
������������Ǻܺá�
LONG
        );
        set("valid_startroom", 1);
        set("no_fight", 1);

        set("exits", ([
                "east" : __DIR__"heibujie7",
        ]));

        set("objects", ([
                __DIR__"npc/gao" : 1
        ]));

        setup();
        replace_program(ROOM);
}


