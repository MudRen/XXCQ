// sxge.c �����
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","�����");
	set("long",
	"����ӭ������ľ���һ������ζ������ǽ��һ��ԭľ�������ң����
���֡�����󡱡�����ǽ�ڱ�������ܣ���Ȼ����ķ������飬����Ҳ��
������ѧ���ŵ��鼮��������ʮʯ���е���ıʯ�����︺����������
����Ҫ�顣\n"NOR
     	);
     	set("valid_startroom",1);
	set("exits",([
     		"east" : __DIR__"huayuan",
     	]));
     	set("objects",([
     		__DIR__"npc/qing" : 1,
     	]));
	setup();
	replace_program(ROOM);
}


	
     	