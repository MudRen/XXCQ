// Room: /d/wizard/wizard_room.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIW "������" NOR);
	set("long", @LONG
����һ��ܴ�Ļ����ң����ɫ��Բ�����м��������Ļ��ݣ�ƽʱ
��ʦ�Ǿ���������л��飬���۸��־����������⡣Ҳ��ʱ����ұ�����
���������������
LONG );

	set("exits", ([
  	"south"  : __DIR__"wizard_room",	
 ]));

	set("no_clean_up", 0); 
        set("recordable_room",1);
      setup();

	replace_program(ROOM);
}
