// Room: ����
// Date: 
#include <room.h>
#include <ansi.h>

inherit ROOM;
void create()
{
         set("short","����");
         set("long",@long
����佻����ɵĳ�����ŨŨ������Ǻ����û��������ֻ����һ
λ������æ����ͣ��һ�᳴��һ���С��������һ�ߣ��и���
���ϵĵط����������ò͵ĵط���   
long);
         set("exits",([
         "west" : __DIR__"caoroom",
         "north" : __DIR__"eatroom",
         ]));
         set("no_fight",1);
           set("objects", ([
           __DIR__"npc/chushi" :1,
         ]));
         setup();
}
void init()
{
         add_action("do_add","fang");
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
         message_vision(HIW"$N��æ�ѳ��õĲ��ϣ��ŵ������\n"NOR,me);
         message_vision(HIW"��ʦ����Ķ�$N���˵�ͷ,˵�����ɵò�����Ϣһ��ɣ���\n"NOR,me);
         me->add("combat_exp",100+random(30));
         me->add("potential",50+random(30));
         me->delete_temp("do_over_job1");
         return 1;
}        

