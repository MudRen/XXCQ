// fmquest.c

#include <ansi.h>

int consider_lv(object ob,int a);

int update_condition(object me, int duration)
{
           object ob,where,ob1,*obb;
           int i;

        where=environment(me);
        me->apply_condition("xhquest1", duration - 1);

        if (file_name(where)==me->query_temp("where1"))
        {
                if (present("di zi",where)) {
                        message_vision(HIG"��ʱһ������ɱ������$N����һ����\n"NOR,me);
                        message_vision(HIG"$N����һ����ԭ���Ǿ�Ԯ����ѵ��Ӵ����ˣ��㲻������һ������\n"NOR,me);               
                        tell_object(me,HIC"�����������ˣ��쵽�ܴ��Ƕ�ȥ�㱨�ɣ�\n"NOR);
                        me->delete_temp("jobstart");
                        me->delete_temp("followed");            
                        me->set_temp("jobok",1);
                        obb=all_inventory(environment(me));
                        for(i=0; i<sizeof(obb); i++) {
                                if (obb[i]->is_character() )
                                {
                                        if (interactive(obb[i])) continue;
                                        if (obb[i]->query("id")!="di zi") continue;
                                        destruct(obb[i]);
                                        
                                }
                        }
                        return 0;
                }
            else {
                tell_object(me,HIC"�㵽�˵ط��������㱣���ĵ�������ȥ�ˣ��Ͽ�ȥ���ҡ�\n"NOR);
                return 1;
       }
        }
         if ((!(present("sha shou",where))) && (random(12)<=4) && present("di zi",where))
        {
                ob = new("/kungfu/class/xuehepai/dizi1");
                 ob->move(environment(me));
                ob->set_name(me->query_temp("duishou")+"ɱ��",({"sha shou","shou"}));
                message_vision(HIG"ͻȻһ����Ӱ��$N�ȵ�����Ѫ���ɵ���ɱ���⣡��\n"NOR, me);
                ob->set("combat_exp",me->query("combat_exp"));
                ob->set("max_qi",me->query("max_qi")*60/100);
                ob->set("eff_qi",me->query("max_qi")*60/100);
                ob->set("qi",me->query("max_qi")*60/100);
                ob->set("max_jingli",me->query("max_jingli")*60/100);
                ob->set("eff_jingli",me->query("max_jingli")*60/100);
                ob->set("jingli",me->query("max_jingli")*60/100);
                ob->set("mex_neili",me->query("max_neili")*60/100);
                ob->set("neili",me->query("max_neili")*60/100);
                ob->set_skill("cuff",consider_lv(ob, 5));
                ob->set_skill("force",consider_lv(ob, 5));
                ob->set_skill("dodge",consider_lv(ob, 5));
                ob->set_skill("parry",consider_lv(ob, 5));
                ob->set_skill("tianyu-xinfa",consider_lv(ob, 5));
                ob->set_skill("tianyu-shenfa",consider_lv(ob, 5));
                ob->set_skill("finger",consider_lv(ob, 5));
                ob->set_skill("sword",consider_lv(ob, 5));
                ob->set_skill("changkong-zhi",consider_lv(ob, 5));
                ob->set_skill("tianyu-qijian",consider_lv(ob, 5));
                ob->map_skill("force","tianyu-xinfa");
                ob->map_skill("dodge","tianyu-shenfa");
                ob->map_skill("parry","tianyu-qijian");
                ob->map_skill("sword","tianyu-qijian");
                ob->map_skill("finger","changkong-zhi");
                ob->prepare_skill("finger","changkong-zhi");
                  ob->set_leader(me);
                ob->set("followid",me->query("id"));
                ob->kill_ob(me);
                me->kill_ob(ob);
        }

        if ( duration < 1 )
        {
           if (me->query_temp("jobstart"))  {
                if (file_name(where)==me->query_temp("where1"))
                {
                if (present("di zi",where)) {
                                message_vision(HIG"��ʱһ������ɱ������$N����һ����\n"NOR,me);
                               message_vision(HIG"$N����һ����ԭ���Ǿ�Ԯ����ѵ��Ӵ����ˣ��㲻������һ������\n"NOR,me);               
                                tell_object(me,HIC"�����������ˣ��쵽�ܴ��Ƕ�ȥ�㱨�ɣ�\n"NOR);
                                me->delete_temp("jobstart");
                                me->delete_temp("followed");            
                                me->set_temp("jobok",1);
                        me->apply_condition("xhquest1",0);
                        obb=all_inventory(environment(me));
                        for(i=0; i<sizeof(obb); i++) {
                                if (obb[i]->is_character() )
                                {
                                        if (interactive(obb[i])) continue;
                                        if (obb[i]->query("id")!="di zi") continue;
                                        destruct(obb[i]);
                                        
                                }
                        }
                                return 0;
                                }
                }
                else if (ob1=present("di zi",where)) 
                {
                       tell_room(where,HIG"ͻȻɱ������"+me->query_temp("duishou")+"���Ӷ���"+obb->query("name")+"�Ϳ�һ��\nȻ����Ĵ�ɢ���������ˡ�\n");
                  ob1->die();
                        tell_object(me,HIC"��û�б����õ��ӣ�����ʧ�ܣ�\n"NOR);                 
                        me->set_temp("jobfailed",1);
                        me->delete_temp("jobstart");
                        me->delete_temp("followed");
                        return 0;
                }
                                tell_object(me,HIC"�㱣���ĵ�������ȥ�ˣ��϶��Ѿ��׶༪�٣�\n"NOR);                    
                me->set_temp("jobfailed",1);
                        me->delete_temp("followed");
                me->delete_temp("jobstart");
                 }
                return 0;
        }

        return 1;
}

int consider_lv(object ob,int a)
{
        int level; 
        float exper;

        exper = to_float(ob->query("combat_exp"));
        level = ceil( pow( exper*10.0, 0.333333) );

        level = level * a / 10;

        return level;
}


