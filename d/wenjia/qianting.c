// Room: qianting.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.3
// Modified Long
// 

inherit ROOM;
void create ()
{
        set ("short", "ǰ��");
        set ("long", @LONG
�߽��Ǻ�ΰ�Ľ�������������ǰ������ʱ������һ����ɱ��
���ա���ǰ����ǽ���ϻ���һֻ������צ�Ľ����������������
����д�š��¼����á������м�������̫ʦ�Σ��������������
һ�ŵ��ӡ��������¼ҽӴ����˵ĵط�������ȥ������ͨ��ƫ
�����š���������ֱ����������ȡ�
LONG);
        set("area","����");
	set("valid_startroom", 1);
        set("objects", ([
                __DIR__"npc/wenjiadizi" : 2,
        ]));

        set("exits", ([
                "south" : __DIR__"square",
                "northeast" : __DIR__"dongpianting",
                "northwest" : __DIR__"xipianting",
                "east" : __DIR__"dongzoulang",
                "west" : __DIR__"xizoulang",
        ]));
        setup();
        replace_program(ROOM);
}
