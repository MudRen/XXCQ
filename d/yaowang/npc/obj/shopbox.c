// Room: ����ҩ��
// By ɽèadx @ ����Сѩ 17:00 99-10-26

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("ҩ��",({"treasure box", "box"}));
	set("short", "ҩ��");
	set("env/invisibility",1);
	set_max_encumbrance(50000000);
	set_weight(100);
	set("no_clean_up", 1);
	set("no_get",1);
	set("no_magic", 1);
	set("no_fight", 1);
	seteuid(getuid());
	setup();
}

int clean_up()
{
    return 0;
}    
