// mlf��ƣ�lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","��լ����");
	set("long",
	"�¸��������ҷ־�����ֻ��ʯ���룬ͨ��ī�̣��Ŷ���һ���ɫ���ң�
���顰�¸����������֣����ƷǷ��������Ǵ�������Ⱥ��������С����ߺ
�������ǳ����֡�\n"
     	);
     	set("valid_startroom",1);
	set("outdoors","wenzhai");
     	set("exits",([
              "north" : "/d/bianliang/huangkudajie3",
     		"enter" : __DIR__"dating",
     	]));
      set("objects",([
              __DIR__"npc/long" : 1,
      ]));
	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam,party;

             me=this_player();
             myfam=(mapping)me->query("family");
             party=(mapping)me->query("party");
	if( (!party || party["party_name"] != HIG "���ζ���" NOR) && ( !myfam || myfam["family_name"] != "���ζ���") 
                && (dir == "enter") )
        {
                if(objectp(present("long tuzhu", environment(me))))
                        return notify_fail("������������ס��ǫ��˵�������ζ�����լ���������������ڣ�\n���ǰ�ʦ�Ļ�"
                                + RANK_D->query_respect(me) +"�������ȥ�ɣ��������ûȤ��\n");
        }

        return ::valid_leave(me, dir);
}
