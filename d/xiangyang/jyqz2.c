//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "����Ǯׯ����");
        set ("long", @LONG
�߽�����Ǯׯ�������Ϳ���һ�����½����˶������Ĵ���������
�����Է���һ������ƣ������������ţ��һ�ɣ��ŵ������һ����ս��
������Ǯׯ�ܹܹܰ˷��ˡ�������һ��ƫ����˯����
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"jyqz",
		"east" : __DIR__"sleep",
	]));

	set("objects", ([
//		__DIR__"npc/cheng": 1,
	]));

        setup();
}