// neitang.c ����
// lks��ơ����

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
	set("long",
	"������Ƿ��ζ���֮��լ�Ĵ�����--���γɹ���������ʩ��ĵط���
��������������������Ʊ�ã������������ڹ��Ķ��ǡ�����һ������
֮�ƣ���������Ҳ�Եø���æµ���������춼Ҫ���ᣬ���۾��ơ�\n"
     	);
     	set("valid_startroom",1);
	set("exits",([
     		"west" : __DIR__"zoulang2",
     	]));
     	set("objects",([
     		__DIR__"npc/wenmengcheng" : 1,
     	]));
     	setup();
     	replace_program(ROOM);
}


     	