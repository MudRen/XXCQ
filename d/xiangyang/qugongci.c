//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG
������ʵ������������Ͽڣ���Ϊ����һ��Ϊ��ԭ�����Ʒ������ö�
����������������Ѳ����ˣ������Ʒ�һֱ�ڡ�������������һ����ʯ��
��ͨ��Զ����
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"huiyang2",
		"southeast" : __DIR__"guandao3",
	]));

        set("outdoors", "zigui");
        setup();
}