// Room: shangu2.c
//Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ��");
        set ("long", @LONG
����ĵ��ƱȽ�ƽ̹��������ƺ����ӿ���ˣ�����ȥ��ֻ��һ��
�������Ƶ�ɽ�嵲ס��������ߣ���ɽ���ﻹ�в��ٵ�С�����Ĵ����ߡ�
ɽ���������ţ����Ϸ�ȴ�ɿ���ɽ���һЩС�ݡ�
LONG);
        set("area","����");
        set("outdoors", "feiyu");

       

        set("exits", ([
                "northup" : __DIR__"shangu1",
                "southeast" : __DIR__"shanjianxiaowu",
        ]));
        setup();
        replace_program(ROOM);
}
