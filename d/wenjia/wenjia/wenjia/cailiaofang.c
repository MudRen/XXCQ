// Room: cailiaofang.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;

void create ()
{
        set ("short", "���Ϸ�");
        set ("long", @LONG
������С�ֺŴ�Ų��ϵķ��䡣����ʮ�ֻ谵��ֻ����һֻ������
���кܶ��ƿƿ�޹ޣ�һЩƿ����������Ѿ�ĥ�ɷ�ĩ��ҩ�ġ�����һЩ
͸����ƿ�������һЩ���ӣ�������ʮ�ֶ��ġ����ˣ��㼸��Ҫ�³�����
���Ͽ���һ������塣
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "up" : __DIR__"zhidushi",
        ]));

        setup();
        replace_program(ROOM);
}


