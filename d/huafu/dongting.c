// dongting.c ����
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"�����ǻ����Ķ��������붫������ֻ�����װڷ���һ����̴ľ�ļҾ�
����ʰ���˳���Ⱦ���Ҿ��ϰڷ���һЩ����ĹŶ�����������������Ǹ�
������������ʿ��\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"northwest" : __DIR__"huayuan",
		"south" : __DIR__"dongxiangfang",
	]));
        set("objects",([
                 __DIR__"npc/yin" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
