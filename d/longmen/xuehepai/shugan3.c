#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������ţ�����Ũ�ܵ���Ҷ����֦���ص�������������ߡ�������
ʱ��ͻȻ����ŨŨ����Ҷ����֦��Ȼ�ǵ���һ�����µı�Ե�����ϲ����
����æ�ǿ���֦����������ȥ��
LONG);

        set("exits", ([
//		"southdown" : __FILE__,
		"northdown" : __FILE__,
		"westdown" : __DIR__"shugan2",
//		"eastdown" : __FILE__,        
		"westup" : __FILE__,
		"northup" : __DIR__"pububian",
//		"southup" : __FILE__,
//		"eastup" : __FILE__,
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