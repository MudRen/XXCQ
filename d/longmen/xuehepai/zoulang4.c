//zoulang1��c             Ѫ����--����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ѫ������������ȡ����������Ŵ�Ƭ�����֣�������죬��Ӱ
��涣���ʵ������⣬���в��ٱ���ϡ�е������м����У��������ϣ���
����������������ͨ�����᷿��
LONG);
	set("outdoors","����");
	set("valid_startroom",1);
	set("exits", ([
		"west" : __DIR__"qingfengge",
		"north" : __DIR__"weitiange",
		"east" : __DIR__"liangongfang1",
		"south" : __DIR__"dongxiangfang",
	]));
	setup();
}

int valid_leave(object me,string dir)
{

        mapping myfam;
	me=this_player();
        myfam=(mapping)me->query("family");

        if (dir=="west")
	{
        if (!myfam || myfam["family_name"]!="Ѫ����")
            return notify_fail("�㲻��Ѫ���ɵĵ��ӣ����ܽ�ȥ��\n");

        if ( me->query("gender")!="����")
            return notify_fail("�������е��ӵ���Ϣ�ң��㲻�ܽ�ȥ��\n");

	}
        return ::valid_leave(me, dir);

}
