// Room: �ƶ�
// Date: by godzilla 1999.11.18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"�ƶ�"NOR);
	set("long",
HIW"ֻ�����ܵ��Ʒɿ����������ƶ�......\n"NOR
 );

	setup();
	replace_program(ROOM);
}
