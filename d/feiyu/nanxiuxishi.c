// Room: nanxiuxishi.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����Ϣ��");
        set ("long", @LONG
��䷿����������һЩ�Źֵ���ζ�����ʱ���ò�̫���ڡ��㿴����
�ܣ������������ż��Ŵ��̣����̷ǳ����ʡ�����ȴ�����߰��㣬���м�
�����ں�����˯�����価ͷ��һ�����ӣ�������ȼ��һ���㣬����һ���
�ջ����·����Ҷ������ϡ�
LONG);
        set("area","����");
        set("valid_startroom", 1);
        set("sleep_room", "1");
        set("no_fight", "1");

        set("exits", ([
                "south" : __DIR__"wxiaojing",
        ]));

        setup();
        replace_program(ROOM);
}
