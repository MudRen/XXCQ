// Room: /city/dangpu.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǿ���Ψһ��һ�ҵ��̣���Ϊ�ھ��ǿ����̣�����Ҫ�����ÿͻ���
���һ�Ҫ�����������µĹ�ϵ����ҵ��̵����ϰ����ھ��ǿ���ҵ���
���Ｘʮ�꣬��Ȼ�к�̨֧�ţ�������˭���Ͳ��ö�֪�ˡ��߽����̣�һ
����߸ߵĹ�̨���������ǰ����̨���������ϰ壬һ˫�������۾�����
���´������㡣
LONG
	);
	set("valid_startroom", 1);
        set("no_steal", 1);
         set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/liu1" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"huangshanjie5",
	]));

	set("area", "����");

	setup();
	replace_program(ROOM);
}
