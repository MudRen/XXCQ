// Room: fengfan.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�緫");
        set ("long", @LONG
һֻСС�ķ緫��ֻ���������ˡ�������������÷ǳ����ƣ���ȫ��
�Խ��г�;���С�һֻ�緫�����ǵùĹĵģ������һ�������š�
LONG);
        set("area","����");
        set("outdoors", "guilin");

        setup();
        replace_program(ROOM);
}

