//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "˯��");
        set ("long", @LONG
����һ��谵�ķ��䣬������е�һ�ȴ�����������������������һ
�����̣�ֻ��˯�����ˣ����������Ĺ������Կ������ϻ��пյء���û��
˼ϸ�۲죬æ���˸��ط��ϴ���������
LONG);
	set("valid_startroom", 1);
         set("sleep_room", 1);

        set("exits", 
        ([
		"west" : __DIR__"jyqz2",
	]));

        setup();
}
