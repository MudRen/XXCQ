//qingfengge��c  by baby

#include <room.h>

inherit ROOM;

void create()
{	
        set("short", "����");
	set("long", @LONG
����һ����ܰ�����ҡ�������Ѫ�����е��Ӿ�ס�ĵط����������
����ǽ�ڷ�ˢ��ѩ�ף����߰ڷ���һ�ſ�����ʵ�������ͷ��һ�ű���
�õ�һ����Ⱦ�ĺ�ľ�������ſڴ���վ����һ���̴ӣ���ʱ׼����������
�ķԸ���
LONG);	
	set("valid_startroom",1);
	set("no_steal", "1");
	set("no_fight", "1");
	set("sleep_room",1);
        set("exits", ([ "east" : __DIR__"zoulang4",
        ]));
	setup();
	replace_program(ROOM);
}
