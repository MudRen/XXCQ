//qinghange��c  by baby

#include <room.h>

inherit ROOM;

void create()
{	
        set("short", "�庮��");
	set("long", @LONG
������Ѫ����Ů���ӵ��Է����߽��庮�������Ȼ���Ǻܻ�������
������͸��һ�����£����ţ����˸е����ʣ���⣬����������ѷ����
׺�ĳ�Ȼ���ף���������������Ũ�Ƶ��Ļ��㣬�·��������ɾ���
LONG);	
	set("valid_startroom",1);
	set("no_steal", "1");
	set("no_fight", "1");
	set("sleep_room",1);
        set("exits", ([
		"west" : __DIR__"zoulang3",
        ]));
	setup();
	replace_program(ROOM);
}
