// Room: yixiantian.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "һ����");
        set ("long", @LONG
�������Ͼ��Ƿ�����������֮һ��һ���족�ˡ����Ը��ʵ��ͱڼ�ֻ
��һ��խխ��С·���պÿ��Բ����ȥ�����ˡ�һ����ĳ����Ƿ�������
����ɭ�ϵĵط�������������һ����ʮ�������������û��ʧ�ع���
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        set("objects", ([
                __DIR__"npc/feiyudizi" : 2,
        ]));

        set("exits", ([
                "northwest" : __DIR__"shanlu1",
                "southdown" : __DIR__"yixiantiannei",
        ]));
        setup();
        replace_program(ROOM);
}
