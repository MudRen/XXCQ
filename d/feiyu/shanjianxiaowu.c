// Room: shanjianxianwu.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ɽ��С��");
        set ("long", @LONG
������һ��ɽ��С�壬����ǹ�ȥ��ɽ��ס�İɣ������������ս��ţ�
ɽ���Ƕ���ɽ����ȥ�ˣ�С�������һ�ˡ�ֻʣ��һЩ�ƾɵļҾ���Ʒ�ˡ�
�����������������Ʒ����㲻����Щ���޴����������ĸо���������һ����
ɽ��������������洵����,�������߱���ɽ���ˡ�
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        

        set("exits", ([
                "eastup" : __DIR__"shanlu2",
                "northwest" : __DIR__"shangu2",
        ]));
        setup();
        replace_program(ROOM);
}
