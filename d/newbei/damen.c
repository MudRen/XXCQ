// ɽèADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", WHT"��ѩɽ"NOR);
    set("long", 
"���ߵ�һ���ģ�������ׯԺ���ţ���ǰ���԰ڷ�����ͷ�ߴ��ʯʨ\n"
"�����ϷŸ߸�������һ������"+HBRED WHT"��Сѩ������ѩɽ��"NOR+
"���������߽���\n"
"ɽ�п�ʼѧϰһЩ�������书��\n"
    );
        set("exits", ([
                "west":__DIR__"dating",
                "east":__DIR__"menqian",
        ]));
        set("no_fight", 1);
        set("valid_startroom", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if( (dir=="east" )
    &&(me->query("newbei")==1)
	&&!wizardp(me) )
	{
		return notify_fail(HIC"�㻹�����뿪��ѩɽ������Ҫ����ѧϰ��\n"NOR);
	}
	else {
		me->set("startroom","/d/newbei/menqian");
	}
	return ::valid_leave(me, dir);
}
