// Room: yixiantiannei2.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "һ������");
        set ("long", @LONG
��һ���족��Ȼ�����鴫�����������Ͽ����Ը��ʵ��ͱڼ�ֻ¶��һ
�����ߣ����Ե��ͱ��ϳ�������ֵ�ֲ��ں�ҹ��������צ����Լ����
���������ɽ�塣����һ����Ҳû�У�һ��紵�������ܷ�������ֵ���
������е�������Щ���⡣
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        
        set("exits", ([
                "northup" : __DIR__"yixiantiannei",
                "west" : __DIR__"diliufeng",
        ]));
        setup();
        replace_program(ROOM);
}
