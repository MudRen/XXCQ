#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������ţ�����Ũ�ܵ���Ҷ����֦���ص�������������ߡ���Ŭ
���İǿ���֦����������������һ���ľ�ɫ���㲻����ã�ˡ�ֱ������
�㣺����·�ˡ�
LONG);
        set("exits", ([
		"southdown" : __DIR__"zrping",
		"northdown" : __DIR__"shugans",
//		"westdown" : __FILE__,
//		"eastdown" : __FILE__,        
//		"westup" : __FILE__,
//		"eastup" : __FILE__,
		"southup" : __FILE__,
		"northup" : __DIR__"shugan2",
        ]));
        set("outdoors", "����");
        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int jingli_cost;

        me=this_player();

        jingli_cost=(-1) * (( me->query("max_jingli") ) / 20 );

        return ::valid_leave(me, dir);
}


