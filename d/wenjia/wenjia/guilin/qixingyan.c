// Room: qixingyan.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
�������Դ��������������ʤ�ء��ǹ���ɽˮ�С�������֮һ������
���ǹ��ֽϴ���Ҷ�����Ϊ�ϡ��С������㣬�²�Ϊ�ӣ�������ˮ������
�������ᣬʯ��ʯ����ʯ��������ʡ�εΪ׳�ۡ�
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "west" : __DIR__"guishulin2",
        ]));
        setup();
        replace_program(ROOM);
}

