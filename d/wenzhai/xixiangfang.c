// xixiangfang.c ���᷿
// mlf���,lks���

#include <ansi.h>

inherit ROOM;
#include <room.h>

void create()
{
	set("short","���᷿");
	set("long",
	"���ﲻ֪����˭ס�ģ������ڼ������ӣ�һ�ŷۺ�ɫ�Ĵ󴲣�������
����һ��Ů���ӳ��õ���ױ̨���پ���һ��̴ľ�������ӣ������ϻ���һ
����Ļң��������û��ס�ˣ���֪���ǲ��ǻ��ϵ���λ���\n"NOR
     	);
     	set("valid_startroom",1);
	set("exits",([
     		"east" : __DIR__"xiting",
     	]));
           set("objects",([
                    "/d/huafu/npc/luo" : 1,
           ]));
     	create_door("east", "ľ��", "west", DOOR_CLOSED);
     	setup();
     	replace_program(ROOM);
}
