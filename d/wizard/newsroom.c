#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIY "Сѩ�������ŷ�������" NOR);
	set("long", @LONG
������Сѩ��������ŷ������ģ���ʲô���Ŷ����������﷢��(post)��
Ȼ��ϵͳ�Զ����֪ͨ����������ҡ�
LONG );
	set("exits", ([
		"north" : __DIR__"wizard_room",
	]));
	set("objects",([
		__DIR__"newer":1,
	]));
	set("no_clean_up", 1);
	setup();
	call_other("/clone/board/news_b", "???");
	replace_program(ROOM);
}
