// Room: lijiangbian2.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�콭��");
        set ("long", @LONG
�ļ����콭��ˮ�������ߵ������·ɱ����ڽ�ˮ�������һ�������ţ�
�߹������ſ��Ե���ȥ�Ĵ��������������������������������Ϸ�����
�Ϳ��������ҹ��Ŵ���ΰ���ˮ�����̡���������
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northwest" : __DIR__"tiesuo",
                "southwest" : __DIR__"lingqu",
        ]));
        setup();
        replace_program(ROOM);
}

