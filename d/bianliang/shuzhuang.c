// shuzhuang.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "������ׯ");
	set("long", @LONG
һ��СС����ׯ�������ı�ȫ���������飬���ָ������鼮��������
���������ҵ��������ĸ������˷���������ϵ��飬��ׯ�ϰ���һ��˹��
�������ˣ���˵ֻ�Ǹ���ţ�����˵ˮƽ���͡�
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"west" : __DIR__"hongbujie6",
	]));

	set("objects", ([
		__DIR__"npc/xiucai" : 1
	]));

	set("area", "����");

	setup();

	replace_program(ROOM);
}