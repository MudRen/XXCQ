// Room: xiaojing.c
// Created by Zeus 1999.5.12
// Modified by Zeus 1999.5.12
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�ض���");
        set ("long", @LONG
�¼Һ�����֪��������ط�����Ϊ�����ŵĶ����¼ҵ�������
�ղ���������к�����ʶ�����С���������ҩ�ĳ�Ʒ���õ�һ��
�Ϳ������𽭺���
LONG);
        set("area","����");

        set("exits", ([
                "up" : __DIR__"duku",
        ]));
        replace_program(ROOM);
        setup();
}