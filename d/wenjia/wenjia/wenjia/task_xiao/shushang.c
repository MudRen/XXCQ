// Room: shushang.c
// Created by Zeus 1999.7.17
// Modified by Zeus 1999.6.17
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
������һƬ���ֵ���������֦ï�ܵÿ���������վ�ȣ������Ṧ����
���˻��ǻ��������
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        setup();
        replace_program(ROOM);
}
