// Room: nanxiuxishi.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.3
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����Ϣ��");
        set ("long", @LONG
��䷿��������һЩ��ɫ����������ʱ���þ���������ġ���
�ÿ�Ҫ���ϵ��۾��������ܣ������������ż��Ŵ��̣����̷ǳ����ʡ�
�������ż����ˣ����Ƕ��ں�����˯�����価ͷ��һ�����ӣ�������
ȼ��һ���㣬�ݱ���˵�����¼�ר�������������ߵ��㡣
LONG);
        set("area","����");
	set("valid_startroom", 1);
	set("sleep_room", "1");
	set("no_fight", "1");

        set("exits", ([
                "east" : __DIR__"fantang",
        ]));
        setup();
        replace_program(ROOM);
}
