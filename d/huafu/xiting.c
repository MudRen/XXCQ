// xiting.c ����
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"�����ǻ����Ӵ�������ѵĵط�����ͷ�輸�Ϸ�����ʱ�ʹ�����ϸ��
�㣬͸�����˵�ϸ���ܵ����ٽ�������Ļ��״��٣��������װ��Ļ�Ȼ
һ�¡����˺�Ѿ�߶���æ��æ����Ĵ����ߡ�\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"east" : __DIR__"zoulang3",
		"north" : __DIR__"xixiangfang",
	]));
	setup();
	replace_program(ROOM);
}
