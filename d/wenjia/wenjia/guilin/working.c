// Room: working.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "��δ����Ŀռ����");
        set ("long", @LONG
������һ����δ����Ŀռ���ڣ�ֻ��һ���˴���̫�շ�������һ��
��������ƽ̨��(SCV)��ָ����һȺZerging���Ż�Ǹ���̫�շ�����Ӧ
���������۰�?
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northeast" : __DIR__"guishulin3",
        ]));
        setup();
        replace_program(ROOM);
}

