//dati.c           

#include <ansi.h>
#include <room.h>
inherit ROOM;


void create()
{
        set("short", "���µ�һ����");
	set("long", @LONG
������Ȩ��������µ�һ���á��������������Ϊһ�壬�������£�����ͬ
Ϊ�Ż���ʯ�Ľ����������ı�����Ȩ����������۵��ּ������ư���.
LONG);
	set("valid_startroom",1);
	set("exits", ([
        	"north" : __DIR__"mingge",
        	"northeast" : __DIR__"zoulang3",
        	"west" : __DIR__"liangongfang",
        	"east" : __DIR__"sleep",
        	"south" : __DIR__"zhuang",
	]));
        set("area", "Ȩ����");
	setup();
        replace_program(ROOM);
}
