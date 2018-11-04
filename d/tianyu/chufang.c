// Room: ����
// Date: by godzilla 1999.11.18

#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
         set("short","����");
         set("long",@long
����һ��С����, ��Ȼ����, ���ǹ���ư��, ���ν��ף�
������ȫ����̨�϶��������ʹϹ��߲�, �����Ϻ, ������
�಻��, ��ʮ�ָɾ����롣
long);
         set("exits",([
         "west" : __DIR__"qianyuan",
         ]));
           set("no_fight",1);
         set("resource/water", 1);
           set("objects", ([
           __DIR__"npc/chushi" :1,
           __DIR__"obj/hulu" : 2,
           __DIR__"obj/feicui-yuyuan" : 1,
           __DIR__"obj/meihua-zaoya" : 2,
         ]));
         create_door("west","ľ��","east",DOOR_CLOSED);
         setup();
}
void init()
{
	 add_action("do_add","add");
}	
int do_add(string arg)
{
	 object me;
	 me=this_player();
	 if(!arg||arg=="")
	 return 0;
	 if(!me->query_temp("do_over_job1"))
	 return 0;
	 if(arg=="chai")
	 message_vision(CYN"$N��æ�����õĲ����ӵ����\n"NOR,me);
	 message_vision(HIR"��һ�ᣬԭ���Ѿ�����һϢ�Ļ����ִܵ��ϸߣ���ԽȼԽ�������������ŵ�ʳ���Ѿ������ŵ���ζ�ˡ�\n"NOR,me);
	 message_vision(CYN"��ʦ����Ķ�$N���˵�ͷ,˵�����ɵò���ȥ˯����Ϣһ��ɣ���\n"NOR,me);
	 me->add("combat_exp",90+random(30));
	 me->add("potential",60+random(30));
	 me->delete_temp("do_over_job1");
	 return 1;
}	 
int valid_leave(object me, string dir)
{
        if (present("qingshui hulu",me)||present("kao ya",me)&&dir == "west" )
        {
                   return notify_fail("��ȫ�����ˣ�������ô�졣\n");
        }
        return ::valid_leave(me, dir);
}
