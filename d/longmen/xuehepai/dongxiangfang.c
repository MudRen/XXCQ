// dongxiangfang��c ���᷿
// mlf��ƣ�lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","���᷿");
	set("long",@LONG
���ڶ������ܵĸı䣬����Ҳ������Ӧ�ı䶯��ԭ���Ķ���ȫ������
��һ�Ŵ����������������˿���������������Ϣ���ָ�ƣ�͡�������Ψһ
��һ�ų����Ϸ���һЩʳ���ˮ��������Щ���������ĵ����ǲ���ȥʳ��
�Ͳͣ���Ȼ��Щ�ԵĶ�����ʱ�伢֮�
LONG   	);
     	set("valid_startroom",1);
	set("no_fight",1);
          set("sleep_room",1);
	set("exits",([
                "west" : __DIR__"zoulang2",
                "north" : __DIR__"zoulang4",
     	]));
     	set("objects",([
     		"/clone/food/baozi" : random(4),
                "/clone/food/jiudai" : random(2),
     	]));
     	setup();
     	replace_program(ROOM);
}
