// Room: /d/wizard/wizard_room.c


#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIW "��Ϸ���ȱ�" NOR);
	set("long", @LONG
������һ��û��һ˿�ҳ���С�ݣ��������һ�����ӣ����ø�λ��ʦ
�������ĸĶ���Ŀ�꼰��������¼�����ı��ӣ������Ѿ�д�˺���һ
����ˣ��ǿ���Сѩ�������ʦ�ǵ���Ѫ��֤������
LONG );

	set("exits", ([
"west" : __DIR__"wizard_room",
 ]));

	set("no_clean_up", 0); 
      setup();
	call_other("/clone/board/lpc_b", "???");
	replace_program(ROOM);
}
