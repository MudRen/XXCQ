//By adx by snow 99-12-5

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"����Ϣ��"NOR);
	set("long",
"������ݵ�����Ϣ�ң���ݵ��е���һ�㶼������˯����\n"+
"˯һ��"+HIC"(sleep)"NOR+"���Իָ�����������������˯������ȫ���ָ���\n"
);
	set("exits", ([
	"south"  : __DIR__"houyuan",
	]));

	set("sleep_room","1") ;
    
	setup();
	replace_program(ROOM);
}
