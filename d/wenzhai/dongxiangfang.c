// dongxiangfang.c ���᷿
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","���᷿");
	set("long",
	"���ڶ������ܵĸı䣬����Ҳ������Ӧ�ı䶯��ԭ���Ķ���ȫ������
��һ�Ŵ����������������˿���������������Ϣ���ָ�ƣ�͡�������Ψһ
��һ�ų����Ϸ���һЩʳ���ˮ��������Щ���������ĵ����ǲ���ȥʳ��
�Ͳͣ���Ȼ��Щ�ԵĶ�����ʱ�伢֮�\n"NOR
     	);
     	set("valid_startroom",1);
	set("sleep_room",1);
	set("no_fight",1);
	set("exits",([
     		"west" : __DIR__"dongting",
     	]));
     	set("objects",([
     		"/clone/food/baozi" : random(5),
                "/clone/food/jiudai" : random(3),
     	]));
     	setup();
     	replace_program(ROOM);
}


     	
