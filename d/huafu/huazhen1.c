// huazhen1.c ����
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIR"����"NOR);
        set("long",
"��ͥԺֻ��һ�������������ܶ��ǻ�����Լ�ɼ��м���С·ͨ������
��������Ʈ�����㲻����Щ�����˯��·��֩��˿һ�����ӣ���������
��·�ˡ�\n"
	);
	set("outdoors","huafu");
	set("exits", ([
            "northeast" : __FILE__,
            "southeast" : __DIR__"zoulang2",
            "southwest" : __FILE__,
            "northwest" : __DIR__"huazhen2",
            "north" : __FILE__,
          "west" : __FILE__,
            "south" : __FILE__,
            "east" : __FILE__,
        ]));
        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int jingli_cost;

        me=this_player();

        jingli_cost=(-1) * ( me->query("max_jingli") ) / 20 ;

        return ::valid_leave(me, dir);
}
