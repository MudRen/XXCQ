// xiting.c ��ƫ��
// mlf��ƣ�lks���

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","��ƫ��");
	set("long",
	"����ֻ��һ��ƫ��������ܼ򵥣�һ��Բ��������Բ�ʡ������Ϸ���
һ������������һ��ò�����ɣ�����֮������Ů�����������������·�
�ӻ����߳�����֪�Ƿ��������ˣ��������˸������档����һ���Ź��š�\n"NOR
     	);
     	set("valid_startroom",1);
	set("exits",([
     		"east" : __DIR__"dating",
     		"west" : __DIR__"xixiangfang",
     	]));
     	create_door("west", "ľ��", "east", DOOR_CLOSED);
     	setup();
     	replace_program(ROOM);
}