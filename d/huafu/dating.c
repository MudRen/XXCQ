// dating.c ����
// mlf��ƣ�lks���

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"������ǻ����������������ϣ�����һ�۾Ϳ��Կ���ǽ����һ���ֻ�
��������׵�<<������>>�����ɷǷ���������ĳЩϲ������ӣ�����ͻ�
�ŵƽӲʣ������ϯ��\n"
	);
        set("class","���ζ���");
	set("valid_startroom",1);
	set("exits",([
		"south" : __DIR__"huayuan",
		"west"  : __DIR__"zoulang3",
		"east"  : __DIR__"zoulang4",
		"northeast" : __DIR__"zoulang2",
	]));
	set("objects",([
		__DIR__"npc/zhang" : 1,
	]));
	setup();
          "/clone/board/huafu_b"->foo();
}

/*
void init()
{
        object ob;
      int i;
        object *obb;
        object me=this_player();
        mapping fam;
        mapping party;
        
        if (interactive(me))
        {
                if (me->query_temp("compaign_start"))
                {
                        if (query("send"))      return;
                        if (!objectp(ob=present("hua kufa",environment(me)))) 
                        {
                                ob=new("/d/huafu/npc/huakufa");
                               ob->move(environment(me));
                                message_vision("���ݷ����˹�����\n",me);
                        }
                        if (!objectp(ob=present("wen mengcheng",environment(me))))           
                        {
                                ob=new("/d/wenzhai/npc/wenmengcheng");
                               ob->move(environment(me));
                                message_vision("���γ����˹�����\n",me);                                
                        }
                        message_vision("���ݷ������γɽ�̸��һ�ᣬ��$N˵��������������죬������Ƹ��㷢��ʩ��ɣ���\n",me);
                        ob=new("/d/huafu/obj/ling");
                        ob->move(me);
                        me->set_temp("shouling",1);
                        set("send",1);
                }
                if (me->query_temp("killwei"))
                {
                        obb=all_inventory(environment(me));
                        for(i=0; i<sizeof(obb); i++) {
				if (obb[i]->is_character() )
				{
                                fam=(mapping)obb[i]->query("family");
                                party=(mapping)obb[i]->query("party");
//                                if (fam["family_name"]==me->query_temp("oponent") || party["party_name"]==me->query_temp("oponent") )
                                if ( !fam && !party ) return;
                                if ((fam && fam["family_name"]!="���ζ���") || (party && party["party_name"]!=HIG"���ζ���"NOR ))
					return;
                                        obb[i]->kill_ob(me);
                                        me->kill_ob(obb[i]);
                        }
                 return;
               }
                }
                return;
        }
}


int valid_leave(object me, string dir)
{
        object ob;
        mapping myfam,party;
        myfam=(mapping)me->query("family");
        party=(mapping)me->query("party");
        if ( !party && !myfam ) return ::valid_leave(me,dir);
        if( (!party || party["party_name"] != HIG "���ζ���" NOR) && ( !myfam || myfam["family_name"] != "���ζ���"))
                return ::valid_leave(me,dir);
               if (!(me->query_temp("buzhile")) && me->query_temp("compaign_start"))
                      return notify_fail(
                      WHT"��û�з������������򣬲����뿪��\n"NOR);
        me->delete_temp("compaign_start");
        me->set_temp("zhangang",1);
        return ::valid_leave(me,dir);
}


*/
