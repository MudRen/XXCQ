// Room: jiedao.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�ֵ�");
        set ("long", @LONG
�����ǹ������ϵĽֵ�������������׳��ľۼ��أ����Ե���������
��������׳����ε���������ȥ��������һ���ջ�����������һƬ��
���֡�
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/zzoldwoman" : 1,
        ]));

        set("exits", ([
                "north" : __DIR__"guishulin4",
                "south" : __DIR__"zhongxin",
                "west" : __DIR__"kezhan",
        ]));
        setup();
        replace_program(ROOM);
}

