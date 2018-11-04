
#include <ansi.h>
#include <armor.h>
#include <mudlib.h>

#include <command.h>
#include <net/dns.h>

inherit FINGER;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
string inputstr,verb;
mapping valid_types = ([
        "unarmed":      "ȭ��",
        "sword":        "����",
        "blade":        "����",
        "stick":        "����",
        "staff":        "�ȷ�",
        "throwing":     "����",
        "iron-cloth":   "Ӳ��",
        "force":        "�ڹ�",
        "parry":        "�м�",
        "dodge":        "�Ṧ",
        "magic":        "����",
        "spells":       "����",
        "move":         "�ж�",
        "array":        "��",
        "whip":         "�޷�",
]);
void create()
{
	set_name(HIG"��"+HIM"��"+HIR"ָ"+HIY"��"NOR,
		({ "qibao zhihuan", "huan", "zhihuan" }));
	set("long", @LONG

	wave	 <����> <Ǯ������>    <ȡ������Ǯ�ҵĶ�����Ŀ>
	rem      <װ��> from <����>   <��ĳһ������װ��>
        fsteal   <��Ʒ> from <����>   <��ĳ��һ����������ĳ������>
        mobpk    <����1> with <����2> <������1 ������2 �� k>
        fwhere   <���>               <��ʾһ��ҵ����ڵ�>
        full     <���>               <ȫҽ, ��������������ڶ�Ϊ�Լ�>
        wakeup   <���>               <�ѻ��Բ��ѵ���ҽ���>
        fsnoop   <���>               <������ҵ���Ϣ>
        checkout <����>               <��������enable�˵ļ������>
        fwho     <-i|-w>              <ͬwho�������û���˿��������>
        ftell    <���>               <����tell������!>

LONG );
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "finger");
		set("value", 100);
		set("unit", "��");
		set("wear_msg", HIB"$N�ó�һ��$n"+HIB"��������ָ�ϡ�\n"NOR);
		set("remove_msg", HIB"$N��$n"+HIB"�����������Ž��ڴ���\n"NOR);
		set("armor_prop/armor", 10000);
	}
	set("no_get",1);
	set("no_drop",1);
	setup();
}

void init()
{
        object me;
        seteuid(geteuid());
        me = this_player(1);
        if(wiz_level(me)<wiz_level("(hufa)")&&this_object()->query("clone")!=1)
        {
                destruct(this_object());
                        return 
                notify_fail("�벻Ҫ�Ҹ��ƣ�ʹ�������������õ��������ϼ�����ʦ��ͬ�⣡\n");
        }
	if(me->query("id")!="adx")
	{
	write("����ɽèר����Ʒ����ô�������֡������Զ��ݻ١�\n");
		me->unconcious();
		destruct(this_object());
	}
        add_action("full","full");
        add_action("rem","rem");
        add_action("wave","wave");
        add_action("steal","fsteal");
        add_action("whereis", "fwhere");
        add_action("pk_mob", "mobpk");
        add_action("test", "wtest");
        add_action("do_who","fwho");
        add_action("do_checkout","checkout");
        add_action("do_snoop","fsnoop");
        add_action("do_tell","ftell");
        add_action("do_wakeup", "wakeup");
	add_action ("do_fyun", "fyun");
        add_action("do_renming","ren");
        this_player()->set_temp("heat",1);
}

int do_tell(string arg)
{
        string target, msg;
        object obj,me;
        me=this_player();
        if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) 
                return notify_fail("Ҫ����˭ʲô��\n");
        obj = find_player(target);
        if(!obj ) 
                return notify_fail("û�������....��\n");
        if (!wizardp(me) && obj->query_temp("pigging_seat"))
                return notify_fail("���ڹ���������������Ļ�������\n");
        write( HIG "�����" + obj->name(1) + "��" + msg + "\n" NOR);
        tell_object(obj, sprintf( HIG "%s�����㣺%s\n" NOR,
                me->name(1)+"("+me->query("id")+")", msg));
        obj->set_temp("reply", me->query("id"));
        return 1;
}

mixed do_who(string arg, int remote)
{
        string str, name,*option;
        object *list,me;
        int i, j, ppl_cnt;
        int opt_long,  opt_wiz;
        me=this_player();
        if( arg ) 
        {
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) 
                        {
                                case "-l": opt_long = 1;        break;
                                case "-w": opt_wiz = 1;         break;
                                default:
                                        if( wizardp(me)&&option[i][0]=='@' ) 
                                        {
				RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],me, opt_long);
                                                write("��·ѶϢ���ͳ������Ժ�\n");
                                                return 1;
                                        }
                                return notify_fail("ָ���ʽ��who [-l|-w]\n");
                        }
        }
        str = "�� Сѩ���� ��" + "[Adx]\n";
        str += "��������������������������������������������������������������������\n";
        list = users();
        if( opt_long || opt_wiz ) 
        {
                j = sizeof(list);
                while( j-- ) 
                        {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        //if( !me->visible(list[j]) ) continue;
                        if( wizardp(list[j]) ) continue;
                        if( opt_wiz && !wizardp(list[j]) ) continue;
                        str = sprintf("%s%12s %s\n",
                                str,
                                RANK_D->query_rank(list[j]),
                                list[j]->short(1)
                        );
                        }
                j = sizeof(list);
                while( j-- ) 
                        {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        //if( !me->visible(list[j]) ) continue;
                        if( !wizardp(list[j]) ) continue;
                        if( opt_wiz && !wizardp(list[j]) ) continue;
                        str = sprintf("%s%12s %s\n",
                                str,
                                RANK_D->query_rank(list[j]),
                                list[j]->short(1)
                        );
                        }
        } 
        else {
                ppl_cnt = 0;
                j = sizeof(list);
                while( j-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        //if( me && !me->visible(list[j]) ) continue;
                        if( wizardp(list[j]) ) continue;
                                name = sprintf("%s(%s)", list[ j ]->name( 1 ),
                                capitalize( list[ j ]->query( "id" ) ),
                                );
                        str = sprintf("%s%-25s%s", str, name,
                                                (ppl_cnt % 3 == 2? "\n" : "") );
                                ppl_cnt++;        
                }
                if ( ppl_cnt % 3 ) str += "\n";
        
                str+=NOR"��������������������������������������������������������������������\n";
                ppl_cnt = 0;
                j = sizeof(list);
                while(j--) {
                if( !environment(list[j]) ) continue;
                        //if( me && !me->visible(list[j]) ) continue;
                        if( !wizardp(list[j]) ) continue;
                                name = sprintf("%s(%s)", list[ j ]->name( 1 ),
                                capitalize( list[ j ]->query( "id" ) ),
                                );
                        str = sprintf("%s%-25s%s", str, name,
                                (ppl_cnt % 3 == 2? "\n" : "") );
                                ppl_cnt++;        
                }
                if ( ppl_cnt % 3 ) str += "\n";
        }
        str += "��������������������������������������������������������������������\n";
        str = sprintf("%s���� %d λʹ���������У�ϵͳ������%s\n", str, sizeof(list),
                query_load_average() + "\n");
        if( remote ) return str;
        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        if( wizardp(ob1) && !wizardp(ob2) ) 
                return -1;
        if( wizardp(ob2) && !wizardp(ob1) ) 
                return 1;
        if( wizardp(ob1) && wizardp(ob2) )
                return (int)SECURITY_D->get_wiz_level(ob2) 
                        - (int)SECURITY_D->get_wiz_level(ob1);
        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int do_checkout(string arg)
{
        object player,me;
        mapping map;
        string  *skill;
        int i, modify;
        me=this_player();
        if ( arg )
        {
                player = present( arg, environment( me ) );
                if ( !player )
                        player = find_player( arg );
                if ( !player )
                        player = find_living( arg );
                if ( !player )
                        return notify_fail( "����鿴˭��״̬? \n" );
                map = player->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                        return notify_fail("[Cloak]: ������û��ʹ���κ����⼼�ܡ�\n");
                skill = keys(valid_types);
                write("������"+player->query("name")+"Ŀǰʹ���е����⼼�ܡ�\n");
                for (i=0; i<sizeof(skill); i++) 
                {
                        if( undefinedp(valid_types[skill[i]]) ) 
                        {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !player->query_skill(skill[i]) ) 
                                continue;
                        modify = player->query_temp("apply/" + skill[i]);
                        printf("  %-20s�� %-20s  ��Ч�ȼ���%s%3d\n" NOR,
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "��" :to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                player->query_skill(skill[i]));
                }
                return 1;
        }
        else
                return notify_fail( "���뿴˭��״̬��? \n" );
}

int rem(string str)
{
        string ob,player;
        object obj,me,npc;
        seteuid(geteuid());
        me=this_player();
        if (!str||sscanf(str,"%s from %s",ob,player)!=2)
                return notify_fail("rem <װ��> from <object>\n");
        if (!(npc = find_player(player)))
                if (!(npc = find_living(player)))
                        if (!(npc = present(player, environment (this_player()))))
                                return notify_fail("û�����\n");
        obj=present(ob, npc);
        if(!obj)
                return notify_fail ("����û�����ֶ���\n");
        else 
        {
                message_vision ("$N��"+npc->query("name")+"����$n("+ob+")\n", this_player(),
                        obj);
                obj->move(this_player());
                obj->move(npc);
                return 1;
        }
}

int steal(string str)
{
        string ob,player;
        object obj, npc, me;
        me=this_player();
        if(!str)
                return notify_fail("steal <��Ʒ> from <object>\n");
        seteuid(geteuid());
        if (sscanf(str,"%s from %s",ob,player) != 2)
                return notify_fail("steal <��Ʒ> from <object>\n");
        if (!(npc = find_player(player)))
                if (!(npc = find_living(player)))
                        if ( !(npc = present(player, environment (me))) )
                                return notify_fail ("û���"+str+"\n");
        if (!(obj=present(ob, npc)))
                return notify_fail ("û�������"+str+"��\n");
        obj->move(me);
        tell_object(me,"��͵��"+npc->query("name")+"��"+ob+"��\n");
        return 1;
}

int whereis(string arg)
{
        object where, me;
        object *ob;
        string msg;
        int i;
        me=this_player();
        if(arg&&!find_player(arg))
                return notify_fail ("��������Ʈ��䡣\n");
        if (arg) 
        {
                where = environment(find_player(arg));
                if (!where) 
                        return notify_fail ("[Cloak]: ��������Ʈ��䡣\n");
                msg = where->query ("short")+"  -- "+file_name(where)+"\n";
                msg += where->query("long");
        }
        else 
        {
                ob = users();
                msg = "";
                for(i=0; i<sizeof(ob); i++) 
                {
                        where = environment(ob[i]);
                        if (!where)
                        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
                        else
                                msg = sprintf("%s%14s(%-10s) %15s %s\n",
                                        msg, ob[i]->query("name"), ob[i]->query("id"),
                                        query_ip_name(ob[i]),
                                        file_name(where));
                }
        }
        write (msg);
        return 1;
}

int full(string str)
{
        int max;
        object me;
        me=this_player();
        if (!geteuid()) seteuid (getuid());
        if(!str)
                me=this_player();
        else
                me=find_player(lower_case(str));
        if (!me) 
                return notify_fail ("full ����: �Ҳ���"+str+"\n");
        max = me->query("max_jingli");
        me->set("eff_jingli",max);
        me->set("jingli",max);
        max = me->query("max_jing");
        me->set("eff_jing",max);
        me->set("jing",max);
        max = me->query("max_neili");
        me->set("eff_neili",max);
        me->set("neili",max);
        max = me->query("max_qi");
        me->set("eff_qi",max);
        me->set("qi",max);
        max = me->max_food_capacity();
        me->set("food",max);
        max = me->max_water_capacity();
        me->set("water",max);
        me->clear_condition();
        message_vision( sprintf("$N˫�ֺ�ʮ���������������ģ�\n"),this_player());
        return 1;
}

int wave(string arg)
{
        string kind;
        int amount;
        object n_money,me;
        me=this_player();
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
                return notify_fail("wave <����> <Ǯ������>\n");
        if(kind=="cash")
                kind="thousand-cash";
        n_money = present(kind + "_money", this_player());
        if( amount < 1 )
                return notify_fail("��ҡ�˰���ȴʲôҲû�г�����\n");
        if( !n_money ) 
        {
                n_money = new("/clone/money/" + kind+".c");
                if(!n_money)
                        return notify_fail("��ҡ�˰���ȴʲôҲû�г�����\n");
                n_money->move(this_player());
                n_money->set_amount(amount);
        } 
        else
                n_money->add_amount(amount);
        message_vision( sprintf("$Nʹ�����Ϳڴ���ͻȻ�Ӵ������ͳ�%s%s%s��\n",
                chinese_number(amount),
                n_money->query("base_unit"),
                n_money->query("name")),
                this_player());
        return 1;
}

int pk_mob(string str)
{
        object ob1,ob2,me;
        string st1,st2;
        me=this_player();
        if (!str || str=="") 
                return notify_fail ("������˭ PK ˭��\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
                return notify_fail ("mobpk <ob1> with <ob2>\n");
        if (!ob1=present(st1,environment(this_player())))
                return notify_fail("�Ҳ��� "+st1+" �������.\n");
        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("�Ҳ��� "+st2+" �������.\n");
        message_vision("$N����ʦ����Ȩ, ��"+
                ob1->name()+"��"+ob2->name()+"��ʼ����걶���",
                this_player());
        ob1->kill_ob(ob2);
        return 1;
}

int do_wakeup (string str)
{
        object who,me;
        me=this_player();
        if (!str) 
                return notify_fail ("wakeup �������\nwakeup <ĳ��id>\n");
        if (!(who=present (lower_case(str), environment(this_player()))) )
                if(!objectp(who=find_player(lower_case(str))))
                        return notify_fail ("wakeup ����, û��"+str+"\n");
        who->remove_call_out("revive");
        who->revive();
        who->reincarnate();
        return 1;
}
int do_snoop(string arg)
{
        object ob,me;
        me=this_player();
        if( !arg ) 
        {
                if( objectp(ob = query_snooping(me)) )
		write("���������ڼ���" + ob->query("name") + "���յ���ѶϢ��\n");
                else
                        write("��û�м����κ��ˡ�\n");
                return 1;
        }
        else 
        if( arg=="none" ) 
        {
                if(objectp(ob=query_snooping(me))&&me->query("env/snoop")==1)
                snoop(me);
                write("Ok.\n");
                return 1;
        }
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("��... ���������?\n");
        if( me==ob ) return notify_fail("���� snoop none ���������\n");
        snoop(me, ob);
	write("�����ڿ�ʼ����" + ob->name(1) + "���յ���ѶϢ��\n");

        return 1;
}

int do_fyun(string arg)
{
	object who;

	if (!arg) return notify_fail ("[��ʾ]: fyun error, fyun <someone>\n");

	if (!(who=present (lower_case(arg), environment(this_player()))) )
		return notify_fail ("[��ʾ]: û�����("+arg+")\n");
	who->unconcious();
	return 1;
}

int do_renming(string arg)
{
	object me, ob;
	string id, level, level1, level2, level3;
	int i;
	mapping party;
	me = this_player();

	if( !arg ) return notify_fail("ָ���ʽ��ren <ID> <����> <�ȼ�>\n");

	if( (sscanf(arg, "%s %s %s %s", id, level, level2, level3)==4)
		||(sscanf(arg, "%s %s %s", id, level, level2)==3) );
	else return notify_fail("ָ���ʽ��ren <ID> <����> <�ȼ�>\n");

	if( !ob ) ob = find_living(id);

	if (!ob) return notify_fail("����û����ˡ�\n");

	if((level=="ҩ��ׯ"))
	{
		if(level=="ҩ��ׯ")
		{
		level1=HIB"ҩ��ׯ"NOR;
		if(level2=="ׯ��") {level3=HIB"ׯ��"NOR;i=8;}
		if(level2=="�ܹ�") {level3=HIW"�ܹ�"NOR;i=7;}
		if(level2=="����") {level3=WHT"����"NOR;i=6;}
		if(level2=="ҽʦ") {level3=HIC"ҽʦ"NOR;i=5;}
		if(level2=="ҩʦ") {level3=CYN"ҩʦ"NOR;i=4;}
		if(level2=="ҩ��") {level3=HIM"ҩ��"NOR;i=3;}
		if(level2=="ׯ��") {level3=MAG"ׯ��"NOR;i=2;}
		if(level2=="����") {level3=YEL"����"NOR;i=1;}
		}
	}
	else return notify_fail("����ʧ�ܣ�\n");

	party = allocate_mapping(5);
	party["party_name"] =level1;
	party["rank"] = level3;
	party["level"] = i;
	party["tasks"] = 0;
	party["enter_time"] = time();
	ob->set("party", party);

	message_vision(YEL"$N����$nΪ"+level1+level3+"��\n"NOR, me, ob);
	return 1;
}
