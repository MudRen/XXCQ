// ɽèADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"��ѩɽ�㳡"NOR);
	set("long",
"������"+HBRED WHT"Сѩ������ѩɽ"NOR+
"����ǰ�㳡���㳡�ĵ���ȫ��������һ��\n"
"��������ʯ�����ﾭ��Χ��һȺС��죬����ɽ�е��Ӷ����������ڴ���\n"
"����������ЩС��쾭����ɽ�����¡�\n"
    );
        set("exits", ([
                "west":__DIR__"damen",
                "east":__DIR__"shanyao",
        ]));
        set("no_fight", 1);
        set("valid_startroom", 1);
	setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if( (dir=="west")
    &&(me->query("newbei")==1)
		&& !wizardp(me) )
	return notify_fail(HIC"���Ѿ�����Ҫ����ɽ��ѧϰ�ˣ�\n"NOR);
	return ::valid_leave(me, dir);
}
