// damen��c  ����
// god

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short","Ȩ�������");
	set("long",@LONG
������Ȩ����Ĵ��ţ������Ϸ������ĽǷ��ܣ����������ĸ�����ʯ
������������ͼ�ڵװ�����������������һ����ң����С��������¡���
��Ѫ����֣������پ�.
LONG);
	set("valid_startroom",1);
	set("outdoors","����");
	set("exits",([
        	"north" : __DIR__"qilingtang",
            "south" : "/d/xiangyang/jyqz",
	]));
        set("objects",([
           __DIR__"npc/bangzhong" : 2,
           ]));
	setup();
              replace_program(ROOM);
}
