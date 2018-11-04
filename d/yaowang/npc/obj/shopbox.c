// Room: ãêÁºÒ©¾Ö
// By É½Ã¨adx @ Äþ²¨Ð¡Ñ© 17:00 99-10-26

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("Ò©¹ñ",({"treasure box", "box"}));
	set("short", "Ò©¹ñ");
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
