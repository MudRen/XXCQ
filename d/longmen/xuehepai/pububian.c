#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ٲ���");
        set("long", @LONG
��ò����ײ�������������£����ɵó���һ��������������ˮ����
���ߴ�����ԭ�����Ѿ����������ٲ��Աߡ����������ؾ�������������ˮ
һս�ģ��뵽����㲻�ɵüӿ�Ų������һ�����˵��������ĵط���
��ʲôֵ�ü���Ķ�����
LONG);
        set("valid_startroom",1);
        set("exits", ([
		"southdown" : __DIR__"shugan3",
		"west" : __DIR__"pubu",
        ]));
        set("outdoors","����");
        setup();
        replace_program(ROOM);
}

