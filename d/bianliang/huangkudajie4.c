// huangkudajie4.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{	
	set("short", "�ƿ���");
	set("long", @LONG
��������,�Ѿ����ټ�����͢��ʿ���ˣ����̾�����������㼯����
��ٲȻ��Ϊ�˽�����ʿ�����ã���������ڷ��ζ����Ļ����Ҵ��٣�����
���Ե÷�������֡�
LONG);	
        set("valid_startroom",1);
        set("no_steal", "1");
        set("outdoors", "bianliang");
	set("exits", ([
//                "north" : __DIR__"luobuzhuang",
                "south" : "/d/huafu/menfang",
		"west" : __DIR__"hua_lukou",
		"east" : __DIR__"huangkudajie5",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
}

/*
int valid_leave(object me, string dir)
{
        object ob;
        mapping myfam,party;
        myfam=(mapping)me->query("family");
        party=(mapping)me->query("party");

        if( (party && party["party_name"]== HIG "���ζ���" NOR) || (myfam && myfam["family_name"]== "���ζ���")
                && (dir == "south") )
        return ::valid_leave(me, dir);
           if (!myfam && !party)
        return ::valid_leave(me, dir);
         if (dir=="south")
         {
                if(!objectp(present("men wei", environment(me))))              
                {
                	if (query("shibai"))
            {
                  me->set_temp("killwei",1);
                		return ::valid_leave(me,dir);
      }
                ob=new("/d/huafu/npc/menwei1");
                ob->move(environment(me));      
                message_vision("һ����Ӱ����$N����ǰ��\n",me);
                	set("shibai",1);
                }
                if(!objectp(present("bai tie",me)))
                      return notify_fail("����������ס��ǫ��˵�������ζ����������������������ڣ�\n���ǰ�ʦ�Ļ�"
                                + RANK_D->query_respect(me) +"�������ȥ�ɣ��������ûȤ��\n");
		return notify_fail("����Ц���еĶ���˵�����Ѱ������Ұɡ�\n");
         }
       return ::valid_leave(me, dir);
}


*/
