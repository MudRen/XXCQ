// Room: duqiu.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�����");
        set ("long", @LONG
������������ģ����ڹ·�ͻأ������������С�����һ����֮�ơ�
������֮��Ρ���ׯ��������ȥ��ȴͦ�ο��㡣�С����۽����������Ȼ
������������ʯ�̡�����´��ɽ��������������ʯ�ף���ֱ��嶥��
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "west" : __DIR__"zhongxin",
        ]));
        setup();
        replace_program(ROOM);
}

