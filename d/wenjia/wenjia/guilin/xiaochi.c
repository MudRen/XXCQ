// Room: xiaochi.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "С�Ե�");
        set ("long", @LONG
�����ǹ������ϵ�Ψһ��С�Ե꣬���׳���˶�Ҫ������Զ�������
��ķ��˱���౾�������Ķ��óԡ������������һЩ�������˺ͷ�ζ
С�ԡ�����Ҳ�ǹ�����Ψһ����׳���˿��ĵ��̡�
LONG);
        set("area","����");
	set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/afa" : 1,
        ]));

        set("exits", ([
                "east" : __DIR__"zhongxin",
        ]));
        setup();
        replace_program(ROOM);
}

