// Room: �ݵ�
// Date:

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
��������һ���ݵرߡ������ʲô�ݶ���,�������������
������ɫ���Աߺü��������ڸ�ݣ��㲻�Ҵ��ţ�վ��һ�Ծ�
���ؿ���      
LONG );
        set("exits", ([
                "east" : __DIR__"churoom", 
                ]));
        setup();
}
void init()
{
        object me;
        me=this_player();
        if(me->query_temp("do_job1"))
        {
        remove_call_out("greeting");
        call_out("greeting",0,me);
        }
        add_action("do_chop","chu");
}
void greeting(object me)
{
        if(me->query_temp("do_job1"))
        message_vision("���ﻹ�кܶ����,���Щ���ȥ���������������أ�"+HIY+"��chu cao��\n"NOR,me);
}
int do_chop(string arg)
{
        object weapon;
        int i;
        i=(int)this_player()->query_temp("do_num");
        if(!this_player()->query_temp("do_job1"))
        return 0;
        if (!arg)
        return 0;
        if(arg!="cao")
        return notify_fail("��Ҫ��ʲô��\n");
        if(!objectp(weapon=this_player()->query_temp("weapon"))
        ||(string)weapon->query("id")!="liandao")
        return notify_fail("������û����������ô����?\n");
        if(this_player()->is_busy())
        return notify_fail("���ϸ�������û����ɣ�ЪЪ������!\n");
        if(this_player()->query("jingli")<30)
        return notify_fail("��̫���ˣ�ЪЪ������!\n");
        if(arg=="cao")
        {
                if(i<1)
                {
                message_vision(RED"$N�������������ĳ��Ųݣ�һ���Ѿ��۵���ͷ���ˡ�\n"NOR,this_player());
                message_vision(HIY"ֻ�����Աߵ�����˵�������ˣ�$N���������һ������\n"NOR,this_player());
                tell_object(this_player(),HIR"��ȥ����������(fang cao)��\n"NOR);
                destruct(weapon);
                this_player()->delete_temp("do_num");
                this_player()->delete_temp("do_job1");
                this_player()->set_temp("do_over_job1",1);
                return 1;
                }
                else
                {
                message_vision(RED"$N�������������ĳ��Ųݣ�һ���Ѿ��۵���ͷ���ˡ�\n"NOR,this_player());
                this_player()->start_busy(random(2));
                this_player()->add("jingli",-random(15));
                this_player()->add_temp("do_num",-1);
                return 1;
                }
         }      
}                       

