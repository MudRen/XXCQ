//zoulang1��c             Ѫ����--����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ѫ�����ϲ�����ȡ����������Ŵ�Ƭ�����֣�������죬��Ӱ
��涣���ʵ������⣬���в��ٱ���ϡ�е������м����У��������ϣ���
����������������ͨ�����᷿��
LONG);
        set("valid_startroom",1);
        set("outdoors","����");
	set("exits", ([
                        "east" : __DIR__"dongxiangfang",
                        "west" : __DIR__"xuehuatang",
	]));
        replace_program(ROOM);
	setup();
}
