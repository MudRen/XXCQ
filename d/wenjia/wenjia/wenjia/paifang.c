// Room: paifang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�Ʒ�");
        set ("long", @LONG
��������ɽ·�ϵ�һ�����Ʒ����Ʒ���д�ź�ɫ���֡��������ֺ���
�ҡ���������ȥ�����¼ҵ������ˡ��������¼��ڽ����еġ��¼�������
���������������ǲ�Ҫȥ�ɡ�����ͷ������������
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("exits", ([
                "northup" : __DIR__"square",
                "south" : __DIR__"shanlu4",
        ]));

        setup();
        replace_program(ROOM);
}
