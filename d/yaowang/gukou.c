// Room: ҩ����
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ȿ�");
	set("long", @LONG
������һ��ɽ�ȵĹȿڣ������Ǹ߸ߵ�ɽ�壬��Χ�������ƣ���ֻ�ܿ��弸��
�⣬һ��С·�����ͽ�����ɽ�ȣ�·������һ��ʯ��(bei)��
LONG );
	set("area", "ҩ����");
	set("areb", "�ȿ�");
	set("exits", ([
		"north" : __DIR__"zhuangqian",
		"south" : __DIR__"shanlu2",
	]));
	set("item_desc", ([
		"bei" :  HIW"\n     ��������\n"+
		   HIW"     �� "HIB"ҩ"HIW" ��\n"+
		   HIW"     �� "HIB"��"HIW" ��\n"+
		   HIW"     �� "HIB"��"HIW" ��\n"+
		   HIW"     �� "HIB"��"HIW" ��\n"+
		   HIW"     �� "HIB"��"HIW" ��\n"+
		   HIW"     �� "HIB"��"HIW" ��\n"+
		   HIW"     �� "HIB"��"HIW" ��\n"+
		   HIW"     �� "HIB"��"HIW" ��\n"+
		   HIW"     ��    ��\n"+
		   HIW"     �� "HIR"ɱ"HIW" ��\n"+
		   HIW"     �� "HIR"��"HIW" ��\n"+
		   HIW"     �� "HIR"��"HIW" ��\n"+
		   HIW"     ��������\n"NOR,
	]));

        set("outdoors", "yaowang");
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if( dir=="north" 
        && me->query("party/party_name")!=HIB"ҩ����"NOR)
                return notify_fail(WHT"�뿴ʯ����\n"NOR);
        return ::valid_leave(me, dir);
}
