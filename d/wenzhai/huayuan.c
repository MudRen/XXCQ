// huayuan.c ��԰
// mlf���,lks ���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","��԰");
	set("long",
	"��԰���൱��������ɽ��ľ������С�ӣ��������š���������԰����
��һ������Сͤ���Ժ�����Ϊ���������̽ǣ��ǳ����¡�ͤ�л���ʯ����
ʯ�ʣ����Ͽ���һ�����̣�����С�����塣\n"NOR
     	);
     	set("outdoors","wenzhai");
	set("valid_startroom",1);
	set("exits",([
     		"north" : __DIR__"dating",
     		"west"  : __DIR__"sxge",
     		"east"  : __DIR__"fotang",
     		"south" : __DIR__"jiashan",
     	]));
     	setup();
     	replace_program(ROOM);
}

