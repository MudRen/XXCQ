//xuehuatang.c          Ѫ����--Ѫ����

#include <ansi.h>
#include <room.h>
inherit ROOM;


void create()
{
        set("short", "Ѫ����");
	set("long", @LONG
������Ѫ���ɵ�Ѫ���á���������Ƹ���Ϊһ�壬�������£�����ͬ
Ϊ�Ż���ʯ�Ľ����������ı�����Ѫ���ɸ������ŵ��ּ������ư��磬��
������ǰ���죬��Ϊ������·�������һ�ȴ��ŵ�סȥ·��
LONG);
	set("valid_startroom",1);
	set("exits", ([
        	"north" : __DIR__"qixuetang",
        	"northeast" : __DIR__"qingyunge",
        	"west" : __DIR__"zoulang1",
        	"east" : __DIR__"zoulang2",
        	"south" : __DIR__"gate",
	]));
        set("area", "����");
	setup();
        replace_program(ROOM);
}
