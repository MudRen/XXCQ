// drum.c

#include <ansi.h>

inherit ITEM;

void de_group(string id);
int find_two_fighter(int size, int rnd);
string select_winner();
void checking(object ob1, object ob2);
string pai_ming(int num);
void recover(object ob);

void create()
{
    set_name("����Ӣ�۹�", ({ "drum" }) );
        set_weight(5000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "ֻ");
          set("long", "����һֻţƤ�Ƴɵľ޹ģ�������ʿ�ڻ�ɽ�۽�ʱ����(knock)����ʼ���䡣\n");
        }
}

int init()
{
        add_action("do_knock", "knock");
        add_action("do_fight", "fight");
        add_action("do_next", "next");
}

int do_next(string arg)
{
        object me;

        me = this_player();

        if(!query("drum_knocked"))      return 0;

        if(me->query("id") != query("drum_knocked") && !wizardp(me) )   
                return notify_fail("ֻ������ʦ���߻����߷������������������\n");

        add("round", 1);
        remove_call_out("start_fight");
        call_out("start_fight", 5);
        tell_room(environment(this_object()), "����������һ�غϵı��䡣\n");
        return 1;
}

int do_knock(string arg)
{
        object ob, me, *env;
        int i, j;
        string id, msg;

        me = this_player();
        ob = environment(me);

        if( !wizardp(me) )   
                return notify_fail("ʲô��\n");

        if(!arg || arg!="drum" )
		return notify_fail("��Ҫ��ʲô��\n");

        env = all_inventory(ob);

        for(i=0, j=0;i<sizeof(env);i++) {
                if(!userp(env[i]) || wizardp(env[i]) )  
                        continue;
                if(j==0)        id = env[i]->query("id");
                else            id+= env[i]->query("id");
                id += "\n";
                j++;
        }

	if(j < 4 )
		return notify_fail("��������̫���ˣ��㻹���ȶ��ټ�������Ұɡ�\n");

        if(query("drum_knocked") )
                return notify_fail("�������Ѿ���ʼ�ˣ������ٻ����ˡ�\n");

	msg=(me->query("name")+"�����˱��䳡�ϵĴ�ģ��������ˣ�������Ѫ���ڡ�\n");
        message("channel:chat",HIM+"�������᡿"+msg+NOR, users() );
        set("drum_knocked", me->query("id") );
//	environment(this_object())->delete("exits");

        de_group(id);

        return 1;
}


void de_group(string data)
{
        int i, j, k, grp, rest;
        string msg, *id, temp;
        object ob;

        if(!data)       return;

        id = explode(data, "\n");

        if(sizeof(id)==0)       return;

        for(i=0;i<20;i++)       delete("group"+i);

        grp = sizeof(id)/4;
        rest= sizeof(id)%4;

        k=0;
        for(i=0;i<grp;i++)
        for(j=0;j< 4 ;j++) {
                ob = find_player(id[k]);
                if(!ob) { j--;continue;}
                set("group"+i+"/"+j, ob->query("id") );
                k++;
        }

        if(rest==1) {
                temp = query("group0");
                if(ob=find_player(id[sizeof(id)-1]) )
                        set("group0/"+sizeof(temp), ob->query("id") );
        }
        if(rest==2 && grp>1 ) {
                temp = query("group0");
                if(ob=find_player(id[sizeof(id)-2]) )
                        set("group0/"+sizeof(temp), ob->query("id") );
                temp = query("group1");
                if(ob=find_player(id[sizeof(id)-1]) )
                        set("group1/"+sizeof(temp), ob->query("id") );
        }

        k=0;
        if(rest==2 && grp<1 ) {
                if(ob=find_player(id[sizeof(id)-2]) ) {
                        set("group0/"+k, ob->query("id") );
                        k++;
                }
                if(ob=find_player(id[sizeof(id)-1]) ) {
                        set("group0/"+k, ob->query("id") );
                        k++;
                }
        }

        k=0;
        if(rest==2 && grp==1) {
                if(ob=find_player(query("group0/3")) ) {
                        set("group1/"+k, ob->query("id") );
                        k++;
                }
                if(ob=find_player(id[sizeof(id)-2]) ) {
                        set("group1/"+k, ob->query("id") );
                        k++;
                }
                if(ob=find_player(id[sizeof(id)-1]) ) {
                        set("group1/"+k, ob->query("id") );
                        k++;
                }
                delete("group0/3");
        }

        k=0;
        if(rest==3) {
                if(ob=find_player(id[sizeof(id)-3]) ) {
                        set("group"+grp+"/"+k, ob->query("id") );
                        k++;
                }
                if(ob=find_player(id[sizeof(id)-2]) ) {
                        set("group"+grp+"/"+k, ob->query("id") );
                        k++;
                }
                if(ob=find_player(id[sizeof(id)-1]) ) {
                        set("group"+grp+"/"+k, ob->query("id") );
                        k++;
                }
        }

        msg = "�����᱾�ַ������£�\n\n";
        i=0;
        while(query("group"+i) ) {
                msg += "\n��"+chinese_number(i+1)+"�飺\n";
                for(j=0;j<sizeof(query("group"+i));j++) {
                        if(!ob=find_player(query("group"+i+"/"+j)) )    continue;
                        msg += sprintf("%-35s", sprintf("%s    (%s)", ob->query("name"), ob->query("id")));
                        if(j%2) msg += "\n";
                }
                i++;
        }

        msg += "\n";
//	message("channel:chat",HIM+"�������᡿"+msg+NOR, users() );
	tell_room(environment(this_object()), msg);
        delete("round");

        remove_call_out("start_fight");
        call_out("start_fight", 5);
}

void start_fight()
{
        object room, ob1, ob2, ob, no1, no2, no3, no4, *list;
        int i, grp, in_grp, grp_rnd, sub_grp_size, round;
        string id, file, username;

        room=environment(this_object());

        delete("fighter1");
        delete("fighter2");

        round = (int)query("round");
        grp=0;
        while(query("group"+grp) )      grp++;
        if(grp<1)       return;

        in_grp = round%grp;
        grp_rnd= round/grp;
        sub_grp_size=sizeof(query("group"+in_grp));

        if(sub_grp_size==1) {
                file = "seperator\n";

                if(no1=find_player(query("group"+in_grp+"/0")) ) {
		tell_room(room, "���α�����ĵ�һ����"
			+no1->query("name")+"("+no1->query("id")+")��\n");
                file += no1->query("name")+" ("+no1->query("id")+")\n";
                no1->add_temp("win_score", 20);
                }

                username = pai_ming(1);
                if(!no2=find_player(username) )
                        no2=present(username, room);
                if(no2) {
		tell_room(room, "                �ڶ�����"
			+no2->query("name")+"("+no2->query("id")+")��\n");
                file += no2->query("name")+" ("+no2->query("id")+")\n";
                }

                username = pai_ming(2);
                if(!no3=find_player(username) )
                        no3=present(username, room);
                if(no3) {
                tell_room(room, "                ��������"
                        +no3->query("name")+"("+no3->query("id")+")��\n");
                file += no3->query("name")+" ("+no3->query("id")+")\n";
                }

                username = pai_ming(3);
                if(!no4=find_player(username) )
                        no4=present(username, room);
                if(no4) {
                tell_room(room, "                ��������"
                        +no4->query("name")+"("+no4->query("id")+")��\n");
                file += no4->query("name")+" ("+no4->query("id")+")\n";
                }

                log_file("lunjian", file);
//		room->set("exits/down", "/d/bianliang/guangchang");
                list=users();
                for(i=0;i<sizeof(list);i++)     {
                        list[i]->delete_temp("win_score");
                        list[i]->delete_temp("attend_meeting");
                }
                delete("drum_knocked");
                delete("lunshu");
                delete("round");
                delete("fighter1");
                delete("fighter2");
                return;
        }

        i = find_two_fighter(sub_grp_size, grp_rnd);
        if(i==0) {
                tell_room(room, "�������"+chinese_number((int)query("lunshu")+1)+"�ֱ���������\n");
                add("lunshu", 1);
                id = select_winner();
                de_group(id);
                return;
        }

        ob1 = find_player(query("group"+in_grp+"/"+i/10) );
        ob2 = find_player(query("group"+in_grp+"/"+i%10) );

        if(!ob1 && !ob2)        return;
        if(!ob1)        ob=ob2;
        if(!ob2)        ob=ob1;
        if(!ob1 || !ob2) {
                tell_room(room, "����һ����Ȩ����һ�ֵ�ʤ���ǣ�"
                        +ob->query("name")+"("+ob->query("id")+")��\n");
                add("round", 1);

                remove_call_out("start_fight");
                call_out("start_fight", 5);
                return;
        }

        tell_room(room,BLINK YEL"��"+chinese_number((int)query("lunshu")+1)
		+"�ֵ�"+chinese_number(round+1)+"�غϣ�  "
                +ob1->query("name")+"("+ob1->query("id")+")---V.S.---"
                +ob2->query("name")+"("+ob2->query("id")+")\n"NOR );

        set("fighter1", ob1->query("id"));
        set("fighter2", ob2->query("id"));
//�����Զ���ʼս�������Զ��ָ�����������������ɽèadx
	ob1->set("eff_qi",ob1->query("max_qi"));
	ob1->set("qi",ob1->query("max_qi"));
	ob1->set("eff_jingli",ob1->query("max_jingli"));
	ob1->set("jingli",ob1->query("max_jingli"));
	ob1->set("eff_neili",ob1->query("max_neili"));
	ob1->set("neili",ob1->query("max_neili"));

	ob2->set("eff_qi",ob2->query("max_qi"));
	ob2->set("qi",ob2->query("max_qi"));
	ob2->set("eff_jingli",ob2->query("max_jingli"));
	ob2->set("jingli",ob2->query("max_jingli"));
	ob2->set("eff_neili",ob2->query("max_neili"));
	ob2->set("neili",ob2->query("max_neili"));

//	command("fight "+ob2->query("id"), ob1);
//	command("fight "+ob1->query("id"), ob2);
//	ob1->fight_ob(ob2);
//	ob2->fight_ob(ob1);
}


int find_two_fighter(int size, int rnd)
{
        if(size<2)      return 0;

        if(size==2 && rnd>0)    return 0;
        if(size==2)             return 1;

        if(size==3 && rnd>2)    return 0;
        if(size==3 && rnd==0)   return 1;
        if(size==3 && rnd==1)   return 2;
        if(size==3 && rnd==2)   return 12;

        if(size==4 && rnd>5)    return 0;
        if(size==4 && rnd==0)   return 1;
        if(size==4 && rnd==1)   return 23;
        if(size==4 && rnd==2)   return 2;
        if(size==4 && rnd==3)   return 13;
        if(size==4 && rnd==4)   return 3;
        if(size==4 && rnd==5)   return 12;

        if(size==5 && rnd>9)    return 0;
        if(size==5 && rnd==0)   return 1;
        if(size==5 && rnd==1)   return 23;
        if(size==5 && rnd==2)   return 4;
        if(size==5 && rnd==3)   return 12;
        if(size==5 && rnd==4)   return 34;
        if(size==5 && rnd==5)   return 2;
        if(size==5 && rnd==6)   return 13;
        if(size==5 && rnd==7)   return 24;
        if(size==5 && rnd==8)   return 3;
        if(size==5 && rnd==9)   return 14;

        if(size>5)      return 0;
}

string select_winner()
{
        int grp, i, j, k, l, m=0;
        string id;
        object ob, ob1;

        grp=0;
        while(query("group"+grp) )      grp++;

        if(grp==1 && sizeof(query("group0"))==2) {
                ob = present(query("group0/0"), environment(this_object()));
                ob1= present(query("group0/1"), environment(this_object()));
                if(!ob && !ob1) return "\n";
                if(!ob)         return ob1->query("id");
                if(!ob1)                return ob->query("id");
                if(ob->query_temp("win_score") > ob1->query_temp("win_score")) 
                        return ob->query("id");
                else    return ob1->query("id");

                if(ob->query_temp("win_score")==ob1->query_temp("win_score")) {
                        if(ob->query("combat_exp")<ob1->query("combat_exp") )
                                return ob1->query("id");
                        else    return ob->query("id");
                }
        }

        for(i=0;i<grp;i++)
        for(j=0;j<sizeof(query("group"+i));j++) {
                ob = present(query("group"+i+"/"+j), environment(this_object()));
                if(!ob) continue;

                l=0;
                for(k=0;k<sizeof(query("group"+i));k++) {
                        ob1 = present(query("group"+i+"/"+k), environment(this_object()));
                        if(!ob1)        continue;
                        if(ob==ob1)     continue;
                        if(ob->query_temp("win_score")<ob1->query_temp("win_score")) {
                                l++;
                                continue;
                        }
                        if(ob->query_temp("win_score")==ob1->query_temp("win_score")) {
                                if(ob->query("combat_exp")<ob1->query("combat_exp") )
                                        l++;
                        }
                }
                if(l<2) {
                        if(m==0)        id = ob->query("id");
                        else            id+= ob->query("id");
                        id += "\n";
                        m++;
                }
        }
        return id;
}


void checking(object ob1, object ob2)
{
        int max_kee1, max_kee2, i, base;
        object winner;

        max_kee1 = ob1->query("max_kee");
        max_kee2 = ob2->query("max_kee");

        if(ob1 && ob1->query_temp("unconcious"))        ob1->revive();
        if(ob2 && ob2->query_temp("unconcious"))        ob2->revive();

        if ( (ob1->is_fighting() && ob2->is_fighting())
          && (!ob1->query_temp("unconcious") && !ob2->query_temp("unconcious")) 
          && (living(ob1) && living(ob2))  && (ob1 && ob2)
          && (find_player(ob1->query("id")) && find_player(ob2->query("id"))) ) 
        {
                remove_call_out("checking");
                call_out("checking",2, ob1, ob2);
                return ;
        }

        add("round", 1);
	remove_call_out("start_fight");
	call_out("start_fight", 5);

        if ( ob1 && ((int)ob1->query("kee")*100 / max_kee1) <= 50 ) 
                winner = ob2;
        if ( ob2 && ((int)ob2->query("kee")*100 / max_kee2) <= 50 ) 
                winner = ob1;

        if(ob1 && ob2 && !winner) {
                if( ((int)ob1->query("kee")*100 / max_kee1) < ((int)ob2->query("kee")*100 / max_kee2) )
                        winner = ob2;
                else    winner = ob1;
        }

        base=1;
        for(i=0;i<(int)query("lunshu");i++)
                base*=10;

        if(winner) {
                winner->add_temp("win_score",2*base);
                tell_room(environment(winner), GRN"��һ�غϵĽ���ǣ�  "+winner->query("name")+" ʤ��\n"NOR);
                return ;
        }

        if(ob1) ob1->add_temp("win_score",base);
        if(ob2) ob2->add_temp("win_score",base);
}

int do_fight(string arg)
{
        object me, target;

        me=this_player();
        if(!arg)        return 0;
        if(!query("drum_knocked"))      return 0;

        target = present(arg, environment(me));
        if(!target)     return 0;
        if( !living(target) )   return 0;
        if(me->is_fighting())   return 0;

        if( (target->query("id") == query("fighter1") || target->query("id") == query("fighter2") )
          && (me->query("id") == query("fighter1") || me->query("id") == query("fighter2") ) ) {
                if( (object)target->query_temp("pending/fight") == me ) {
                        me->set_temp("attend_meeting", 1);
                        target->set_temp("attend_meeting", 1);
                        recover(me);
                        recover(target);
                        remove_call_out("checking");
                        call_out("checking", 2, me, target);
                }
                return 0;
        }
        tell_object(me, "�ȱ𼱣���û���ֵ�����ء�\n");
        return 1;
}


string pai_ming(int num)
{
        object *list;
        int i, j, k;

        list=users();

        for(i=0;i<sizeof(list);i++) {
                if(!list[i]->query_temp("attend_meeting") )     continue;

                k=0;
                for(j=0;j<sizeof(list);j++) {
                        if(!list[j]->query_temp("attend_meeting") )
                                continue;
                        if(list[i] == list[j] )
                                continue;
                        if(list[i]->query_temp("win_score") < list[j]->query_temp("win_score") ) {
                                k++;
                                continue;
                        }
                        if(list[i]->query_temp("win_score") == list[j]->query_temp("win_score") 
                        && list[i]->query("combat_exp") < list[j]->query("combat_exp") ) {
                                k++;
                                continue;
                        }
                }
                if(k == num)    return  list[i]->query("id");
        }

        return "\n";
}

void recover(object ob)
{
        ob->set("eff_gin", ob->query("max_gin"));
        ob->set("gin", ob->query("eff_gin"));
        ob->set("eff_kee", ob->query("max_kee"));
        ob->set("kee", ob->query("eff_kee"));
        ob->set("eff_sen", ob->query("max_sen"));
        ob->set("sen", ob->query("eff_sen"));
}
