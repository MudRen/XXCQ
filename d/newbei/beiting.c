//By ɽèadx by snow 99-12-5

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",WHT"��ѩ������"NOR);
    set("long",
"���߽�һ�䲻��ķ�����������ѩɽ�ı����������������������ѩɽ\n"
"ɽ����������ȥ��"+HIC"(ask motobaby about job)��\n"NOR
    );
        set("exits", ([
                "south":__DIR__"dating",
        ]));
        set("objects",([
                __DIR__"npc/moto":1,
                ]));
        set("no_fight", 1);
	setup();
        replace_program(ROOM);
}
