// Room: lingqu.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
�ҹ��Ŵ�ΰ���ˮ�����̾ͳ���������ǰ����ΰ��Ĺ��̱������ҹ�
������ǻۺ�ΰ�����޷���Ϊ��һΰ��Ĺ����ԺȲʡ���������������
����һƬ�콭�ĵ̰������������ǵ��ƽϸߵ��콭���Ρ�
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northeast" : __DIR__"lijiangbian2",
                "southwest" : __DIR__"jiangdi",
        ]));
        setup();
        replace_program(ROOM);
}

