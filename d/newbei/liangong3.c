//By adx by snow 99-12-5

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"������"NOR);
	set("long",
"��������ݵ���������������ש�̵أ��յ�����һ���󷿼���\n"
"���˼�����ݵ�����������������û�������Ķ���������Ժ���������\n"
"����"+HIC"(finger peilian)"NOR+"Ҳ����ֱ�ӹ���"+
HIC"(hit peilian)"NOR+"��������������\n"
"��������Ǳ�ܺ�ս�����飬�ͻ�һ���������ԡ�\n"
	);
	set("exits", ([
		"southeast" : __DIR__"houyuan",
	]));
        set("objects",([
                __DIR__"npc/peilian3":3,
                ]));
	setup();
	replace_program(ROOM);
}
