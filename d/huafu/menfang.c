// menfang.c  �ŷ�
// mlf��ƣ�lks���

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short","��������");
	set("long",@LONG
�����Ƿ����ܲ������Ĵ��ţ�����������������ͷ��ʯʨ�ӡ�������
����һ����ң����顰�������������֣��ҵ����Ҵ�����������������
�ų����ţ����ڷ��ζ������ӵܴ���Ǿ��ǵ��о�֮ͽ����������Ҳ����
�����֡�
LONG
	);
	set("outdoors","huafu");
	set("valid_startroom",1);
	set("exits",([
                "enter" : __DIR__"huayuan",
                "north" : "/d/bianliang/huangkudajie4",
	]));
	set("objects",([
		__DIR__"npc/qi" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam,party;
        myfam=(mapping)me->query("family");
        party=(mapping)me->query("party");

        if( (!party || party["party_name"] != HIG "���ζ���" NOR) && ( !myfam || myfam["family_name"] != "���ζ���") 
                && (dir == "enter") )
        {
                if(objectp(present("qi lianxia", environment(me))))
                        return notify_fail("����ϼ������ס��ǫ��˵�������ζ����������������������ڣ�\n���ǰ�ʦ�Ļ�"
                                + RANK_D->query_respect(me) +"�������ȥ�ɣ��������ûȤ��\n");
        }

        return ::valid_leave(me, dir);
}


