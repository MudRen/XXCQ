//liangong.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "������");
	set("long", @LONG
�������ŵ���������ƽ������һЩ�������������������Ϊ����
�������ڽ�����ĬĬ���ţ�������������һ���ܹ����ֻ��ܴ�������ˮ
��Ϊ�����еĵ�һ�ˡ�
LONG);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([	"north" : __DIR__"wzlang1",]));
	setup();
	replace_program(ROOM);
}