#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ʯС·");
        set("long", @LONG
�����Ǻ�ɽС·����·Խ��Խխ��ɽʯ������״��Ȯ�ݣ���ʯ���Ľ�
��ʹ��ʹ�ģ���ʱ��Զ������������Х������ͷƤ���飬С·����������
��ǰ��ȥ��ͨ����������ĺ�ɽ��
LONG);
        set("valid_startroom",1);
        set("exits", ([
		"northup" : __DIR__"houshan",
		"east" : __DIR__"hsxiaolu2",
		"north" : __DIR__"hsxj1",
        ]));
        set("outdoors", "����");
        setup();
        replace_program(ROOM);
}

