//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG
���Žֱ��Ľ���Ǯׯ�Ľ������֪�����������������Ľ���Ǯׯ����
�������Ǯׯ����Ȩ�����֧�ų����ưԣ�����������ֻ����ôһ��Ǯ
ׯ���������⻹�ǲ���ġ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"jinyin3",
		"west" : __DIR__"jinyin1",
		"north" : __DIR__"jyqz",
	]));

        set("outdoors", "zigui");
        setup();
}