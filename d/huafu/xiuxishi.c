// xiuxishi.c ��Ϣ��
// mlf��ƣ�lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","��Ϣ��");
        set("long",
"�����ǵ��ӵ���Ϣ�ң����������������۵�������õ�ƣ�ͻ��⣬��
�ﲢ�Ű��ż��Ŵ�������ȥ�����ʵ����ӡ�������ô��ʱ�䵹��������һ
�µ�Ҳ����\n"
	);
	set("valid_startroom",1);
	set("no_fight",1);
	set("exits",([
		"west" : __DIR__"liangong",
	]));
	set("sleep_room",1);
	setup();
	replace_program(ROOM);
}

