// do_songxin

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int consider_lv(object ob,int a);
int update_condition(object me, int duration)
{
        object ob,obj;
        obj=present("mi han", me);
        if (duration<1)
        return 0;
        if (duration == 9)
        {
                if(me->query_temp("do_job2"))
                {
                        if(present("mi han", me))
                        {
                                tell_object(me,RED"���ܸе����ǣ����������˶����㡣\n"NOR);
                                tell_object(me,RED"���ܾ�����������ʲô�����������ڴ�һ���������Ŷ��ˡ�\n"NOR);
                                ob=new("/d/tianyu/npc/killer");
                                ob->move(environment(me));
                                me->start_busy(4);
                                ob->set_leader(me);
                                obj->move(ob);
                                tell_object(me,HIR"ͻȻ�����˺ȵ���С�ӣ������������������ɱ����֮�ˣ�ֻ����������ʱ�ˣ�\n"NOR);
                                ob->kill_ob(me);
                                ob->set("combat_exp",(int)me->query("combat_exp") * 4 / 5);
                                ob->set("max_qi",(int)me->query("max_qi"));
                                ob->set("eff_qi",(int)me->query("max_qi"));
                                ob->set("qi",(int)me->query("max_qi"));
                                ob->set("max_jingli",(int)me->query("max_jingli"));
                                ob->set("eff_jingli",(int)me->query("max_jingli"));
                                ob->set("jingli",(int)me->query("max_jingli"));
                                ob->set("max_neili",(int)me->query("max_neili"));
                                ob->set("neili",(int)me->query("max_neili"));
                                ob->set_skill("force", consider_lv(ob, 8));
                                 ob->set_skill("unarmed", consider_lv(ob, 8));
                                ob->set_skill("dodge", consider_lv(ob, 8)); 
                                ob->set_skill("blade", consider_lv(ob, 8));
                                ob->set_skill("parry", consider_lv(ob, 8));
                                ob->set_skill("xiuluo-dao",consider_lv(ob, 8)); 
                                me->set_temp("jiefei_1",1);
                                me->apply_condition("do_songxin", duration - 1);
                                return 1;
                        }
                                                        
                }       
                
         }
         me->apply_condition("do_songxin", duration - 1);
         return CND_CONTINUE;     
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

