// ɽèADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", WHT"��ѩ����"NOR);
    set("long",
"������Сѩ������ѩɽ�Ĵ�����������ڷ���һ���������Բ�"+
HIC"��board��\n"
NOR"���ڵ��Ӽ佻��ʹ�ã��������ʲô��Ҫ���������˻���ʲô��Ҫ������\n"
"���Է��ֲ����ߣ������������"+HIC"��post��"NOR+"��\n"
    );
        set("exits", ([
                "west":__DIR__"houting",
                "east":__DIR__"damen",
                "north":__DIR__"beiting",
                "south":__DIR__"nanting",
        ]));
        set("no_fight", 1);
        set("valid_startroom", 1);
	setup();
}
