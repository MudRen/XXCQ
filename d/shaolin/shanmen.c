// Room: /d/shaolin/shanmen.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG
һ���޴���Ʒ��������Ƭɽ��֮�䣬�Ʒ����Ϸ����������������
�������¡����ּ���Щ���䣬����ȥ�����Զ��һλ��ʮ���������ɮ��
����ɽ�����ࡣ�������һ��ʯ����
LONG );
	set("valid_startroom", 1);
    set("exits", ([
        "eastup" : __DIR__"shijie8",
        "west" : __DIR__"shijie7",
    ]));
    set("outdoors", "shaolin");
    set("objects",([
		"/kungfu/class/shaolin/tongren": 1
    ]));
    setup();
}

int valid_leave(object me, string dir)
{
    object *inv;
	mapping myfam;
    int i;

    if (me->query("gender") == "Ů��" && dir == "eastup" ) {
        if(objectp(present("tong ren", environment(me))))
            return notify_fail("ͭ��������ס�����һ��˵����ǧ����������������"
                "Ů�����롣" + RANK_D->query_respect(me) +"\n����ɽȥ�ɣ����"
                "����ûȤ��\n");
    }

    myfam = (mapping)me->query("family");

    if ((!myfam || myfam["family_name"] != "������" ) && dir == "eastup") {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                if(objectp(present("tong ren", environment(me))))
                    return notify_fail("ͭ����ס��˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�����ǧ���"
                        "��أ����\n���óֱ�����ɽ��\n");
    }
    return ::valid_leave(me, dir);
}
