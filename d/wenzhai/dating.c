// dating.c ����
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
	set("long",
	"�������¸��Ĵ��������Ҹ�һ��Ӣ��ϯ������һ�ź�ɫ���������߶�
��������̫ʦ�Ρ�ǽ�Ϲ���һ������Ծ��Ĵ��֡�ͨ�� ���䡱��Ȼ����
����֮�֣�������Ȼ�𾴡����Ҹ���С��ͨ��ƫ�����᷿��\n"NOR
     	);
     	set("valid_startroom",1);
	set("exits",([
     		"west"  : __DIR__"xiting",
     		"east"  : __DIR__"dongting",
     		"north"   : __DIR__"caodi",
     		"south" : __DIR__"huayuan",
     	]));
     	setup();
     	replace_program(ROOM);
}
