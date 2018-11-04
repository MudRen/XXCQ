// NPC: zhangxuemian.c
// Created by Atlus 1999.7.23
// Modified by M.A.D. 1999.7.21
// 
// 

inherit NPC;
#include <ansi.h>

void init();
void greeting(object);
int give_task(string);
int do_join(string arg);
int do_uplevel(string arg);
void delete_served(object);

void create()
{
        set_name("��ѩ��", ({ "zhang xuemian" , "zhang"}) );
        set("nickname", HIC"�����ܹ�"NOR );
        set("gender", "����" );
        set("age", 45);
        set("long",
                "��ѩ���Ƿ��������ܹܣ�Ҳ�Ƿ������н�������������ˡ�֮һ�����������������һ���ճ����\n"+
                "��������ޣ�һ���ǳ����������ӡ�\n");
        set("attitude", "friendly");

        set("qi", 250);
        set("max_qi", 250);
        set("jingli", 250);
        set("max_jingli", 250);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 50);

        set("combat_exp", 1000000);

        create_family("������", 2, "����");

        set("inquiry", ([
                "����" : (: do_join :),
                      
        ]) );

        setup();
        
        carry_object("/d/feiyu/obj/chouduan")->wear();
}
        
void init()
{
        object ob;

        add_action("give_task", "task");
        add_action("give_uplevel", "uplevel");

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                 remove_call_out("greeting");
                 call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        if (ob->query("feiyutask/reg")) {
                 say("��ѩ��˵��������λ" + RANK_D->query_respect(ob)
                 + "����Ϊ����������������Ҫ�����(task)����\n");
        }
        else {
                 say("���е��Ӳ��࣬���в���������Ҫ���ء���\n");
        }
}

int do_join(string arg)
{
        object me;

        me=this_player();

        if (!(string)me->query("family") || (string)me->query("family/family_name") != "������") {
                message_vision("��ѩ�߹����ض�$N˵�����㲻�Ƿ�����ӣ���θ������Ĵ��?\n��",me);
                return 1;
        }

        if (me->query("feiyutask/reg")) {
                command("angry "+me->query("id"));
                message_vision("���ܹܶ�$N˵�������Ѿ��Ǽǹ��ˣ����ں�Ūʲô?��\n",me);
                return 1;
        }

        me->set("feiyutask/reg",1);
        me->set("feiyutask/done",1);
        me->set("feiyutask/first",1);
        me->set("title",RED"������"NOR);
        command("smile " + me->query("id"));
        message_vision("���ܹ�΢Ц�ض�$N˵�������úøɰɣ���������׳��Ϳ�������Щ����!��\n",me);

        return 1;
}

int give_task(string arg)
{
        object me,givesilver;
        int givepot,giveexp,i,tasktime;

        me=this_player();

        message_vision("$N�����ܹ�ѯ����������ľ������!\n",me);

        if ( arg || arg == "ok" ) { //����������task ok����ô��ʾ����������
                if( me->query_temp("feiyutask/given") && me->query_temp("di1mark") && me->query_temp("di2mark") && me->query_temp("di3mark")  && me->query_temp("di4mark")  ) {
                        command("pat " + me->query("id"));
                        message_vision("���ܹܶ�$N˵�����ã����Ѿ��������������ı���!��\n",me);
                        if ( me->query("feiyutask/first")) {
                                message_vision(HIY"���ܹ�΢Ц�ض�$N˵������һ����������������ĳɼ���Ҫ�����ر���!��\n"NOR,me);
                                me->add("potential", 40+random(100));
                                me->add("combat_exp", 100+random(100));
                                givesilver=new("/clone/money/gold");
                                givesilver->move(me);
                                me->set("feiyutask/first",0);
                        }
                        givepot=15+random(10);
                        giveexp=85+random(10);
                        me->add("feiyutask/done",1);
                        tasktime=me->query("feiyutask/done");
                        me->add("potential", givepot);
                        me->add("combat_exp", giveexp);
                        message_vision(HIY"$N��������"+chinese_number(givepot)+"��Ǳ�ܺ�"+chinese_number(giveexp)+"�㾭�顣\n"NOR,me);
                        for (i=1;i<2+random(4);i++) {
                        givesilver=new("/clone/money/silver");
                        givesilver->move(me);}
                        message_vision(HIC"$N�Ѿ�Ϊ�����������"+chinese_number(tasktime)+"������\n"NOR,me);
                        message_vision(HIC"���ܹ��ó��������ӣ�������$N��\n"NOR,me);
                        me->delete_temp("feiyutask/done");
                        me->delete_temp("feiyutask/given");
                        me->delete_temp("di1mark");
                        me->delete_temp("di2mark");
                        me->delete_temp("di3mark");
                        me->delete_temp("di4mark");
                        me->set_temp("busying", 1);
                        call_out("delete_served", 20, me);
            
                
                return 1;
                }
                else if ( !(me->query_temp("feiyutask/given")) ) {
                        command("angry " + me->query("id"));
                        message_vision("���ܹܶ�$N˵�����㻹û����������!��\n",me);
                        return 1;
                }
                else if ( me->query_temp("feiyutask/given") ) {
                        command("angry " + me->query("id"));
                        message_vision("���ܹܶ�$N˵�������������񲻸Ͽ�ȥ������ʱ�������Ч��!��\n",me);
                        return 1;
                }
        }        

        if ( !(me->query("feiyutask/reg"))) {
                if (!(string)me->query("family") || (string)me->query("family/family_name") != "������") {
                        message_vision("��ѩ�߹����ض�$N˵�����㲻�Ƿ�����ӣ���θ������Ĵ��?��\n",me);
                return 1;
                } {
                message_vision("���ܹܶ�$N˵��������Ǽ�һ�£�����������!��\n",me);
                return 1;}                
        }
        
        if( (int)me->query("combat_exp") > 50000) {
                        message_vision("��ѩ�߶�$N˵�� ��������������̫��ϧ�ˣ�ȥ��Щ��Ĺ����ɣ��� \n",me);
                 return 1;}
 
        if ( me->query_temp("feiyutask/given") ) {
                command("angry " + me->query("id"));
                message_vision("���ܹܶ�$N˵�������������񲻸Ͽ�ȥ������ʱ�������Ч�ģ���\n",me);
                return 1;
        }
        
        if ( me->query_temp("busying") ) {
                message_vision("���ܹܶ�$N˵������ող��Ͷ���������ȥ��Ϣһ����ɡ��� \n",me);
                return 1;
        }
                
        me->set_temp("feiyutask/given",1);
        message_vision("���ܹܶ�$N˵������ȥ�Ĵ�Ѳ��һ��,��ʲô�����������!��\n",me);

        return 1;
}

int give_uplevel(string arg)
{
        object me;
        int donenum;
        int exp;
        
        me=this_player();
        donenum=(int)me->query("feiyutask/done");
        exp=(int)me->query("combat_exp");
        
        if ( donenum>300 && exp<50000 ){
                me->set("title",RED"������"NOR);
                message_vision("���ܹܶ�$N˵��������Ƿ����������ˡ���\n",me);
                return 1;
        } else if ( donenum<600 && exp>50000 ) {
                me->set("title",GRN"����"NOR);
                message_vision("���ܹܶ�$N˵������ϲ��!�ӽ��쿪ʼ����Ƿ������������ˡ���\n",me);
                return 1;

        } else if ( donenum<900 && exp>100000 ) {
                me->set("title",GRN"����"NOR);
                message_vision("���ܹܶ�$N˵������ϲ��!��������ͷ�ӡ����Ƽ����ӽ��쿪ʼ����Ƿ������������ˡ���\n",me);
                return 1;
        } else if ( donenum<1500 && exp>200000 ) {
                me->set("title",YEL"����"NOR);
                message_vision("���ܹܶ�$N˵��������!��������ͷ�ӡ����Ƽ����ӽ��쿪ʼ����Ƿ������������ˡ���\n",me);
                return 1;
        } else if ( donenum<2000 && exp>400000 ) {
                me->set("title",BLU"��ͷ��"NOR);
                message_vision("���ܹܸ��˶�$N˵����ׯ�������ӽ��쿪ʼ������Ϊ���Ƿ������ġ���ͷ�ӡ�����\n",me);
                return 1;
        } else if ( donenum<2500 && exp >800000) {
                me->set("title",MAG"����"NOR);
                message_vision("���ܹܹ����ض�$N˵�����ֵܣ��ӽ��쿪ʼ����Ƿ������ġ����ˡ��ˣ������Ѿ�ƽ��ƽ������������ˡ���\n",me);
                return 1;
        } else if (donenum>3000 && exp >1200000) {
                me->set("title",CYN"Ӥ��"NOR);
                message_vision("���ܹܹ����ض�$N˵����������ҵ����ۣ�һ�¾����ӽ��쿪ʼ����Ǳ�����ߵġ�Ӥ�����ˣ��պ������������\n",me);
                return 1;
        }
        message_vision("���ܹܶ�$N˵������Է������Ĺ��׻�����������������������\n",me);
        return 1;
}

void delete_served(object me)
{
      if ( objectp(me) ) me->delete_temp("busying");
}
