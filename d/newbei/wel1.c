// ɽèADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"��ӭ����Сѩ����"NOR);
	set("long", 
"���������������һ��İ�������磬���뿴����������"+HIC"(l, look),\n"NOR
"����֪����������ﶼ��˭"+HIC"(who)"NOR+",������Ҫ�Ĵ����ߣ�"+
HIC"(w,s,n,e,nw,ne,\n"
"sw,se,d,u,sd,nd,wd,ed,wu,nu,eu,su)"NOR+"����������ȿ���������Щ���Գ��ڡ�\n"
 );
        set("exits", ([
                "east":__DIR__"wel2",
                "south":__DIR__"welx",
                
        ]));
        set("objects",([
                __DIR__"npc/jieyinshi1":1,
                ]));
	set("no_fight", 1);
	setup();
	replace_program(ROOM);
}
