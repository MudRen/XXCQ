// Room: paifang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.3.26
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�Ʒ�");
        set ("long", @LONG
��������ɽ·�ϵ�һ�����Ʒ����Ʒ���д�ź�ɫ���֡�����
���ֺ��¼ҡ���������ȥ�����¼ҵ������ˡ��������¼��ڽ���
�еġ��¼����������������������ǲ�Ҫȥ�ɡ�����ͷ������
������
LONG);
        set("area","����");
        set("outdoors", "wenjia");

        set("exits", ([
                "up" : __DIR__"square",
        ]));
        setup();
        replace_program(ROOM);
}
