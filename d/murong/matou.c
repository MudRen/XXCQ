// matou.c

inherit ROOM;
#include <ansi.h>  

void create()
    {
        set("short", "��ͷ");
set("long",@LONG
����һ������̫����ˮ����ͷ��ֻ�����������������ò����֡�һ����
�糾���ͣ���ͷ�ߵ��ϴ���������߹���������Ц�Ǻǵ�ӭ����ȥ��
LONG 
);
	set("outdoors","����Ľ��");
	set("objects",([
	__DIR__"npc/laoda" : 1,
]));
	set("exits",([
	 "north" : __DIR__"sq",
]));
	setup();
	replace_program(ROOM);
}                                                           



