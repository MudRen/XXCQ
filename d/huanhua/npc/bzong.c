#include <ansi.h>
inherit NPC;

string *name_1 = ({
"��","��","��","��","��","Ǯ","��","��","֣","��","��","κ","��","��",
"��","��","��","��","��","����","˾��","˾ͽ","���","³","Τ","Ľ��"
});

string *name_2 = ({
"��","��","���","��","��ͥ","��","��","����","����","��","����","һɽ",
"����","�ϵ�","�ź�","����","����","����","����","��","��","��","��","��",
"��","��","�̲�","�߻�","��Ӣ","Ӣ","����","��","չ��","�Ʒ�","����","â",
"����","����","��"
});

string *name_3 = ({
"����","����","�ٶ�","��ȭ","����","��Ӱ","����","һ��","����","����",
"����","ѪӰ","����","ǧ��","�쵶","����","��ɱ","���","�ɵ�"
});

string *weapon = ({
"changjian","dandao","gangjian","gangdao","zhubang","changqiang"
});

string *place = ({
"gate","hanghe","southyuan","yingzu","wuroad2",
"tingyulou","jiantian","menqian","wuchang1","southlang"
});

void create()
{
        set_name(name_1[random(sizeof(name_1))] + name_2[random(sizeof(name_2))], ({"bang zhong", "zhong", "bang"}));
        set("gender", "����");
        set("age", 26);
        set("title", "Ȩ����" + name_3[random(sizeof(name_3))] + "�ֶ����");
        set("long", 
                "����һ����������ļһ��������Ŀ����㡣\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 15);
        set("con", 20);
        set("dex", 25);
        set("bac", 15);

        set("qi", 300);
        set("max_qi", 300);
        set("jingli", 200);
        set("max_jingli", 200);
        set("neili", 100);
        set("max_neili", 100);
        
        set("combat_exp", 100000+random(10)*5000*random(10));
        
        set_skill("force", 100);
        set_skill("strike", 100);
        set_skill("cuff",100);
        set_skill("dodge", 100); 
        set_skill("whip", 100); 
        set_skill("axe", 100); 
        set_skill("club", 100); 
        set_skill("stick", 100); 
        set_skill("sword", 100); 
        set_skill("staff", 100); 
        set_skill("blade", 100); 
        set_skill("parry", 100); 
        set_skill("literate", 100); 
        
        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/" + weapon[random(sizeof(weapon))])->wield();

        add_money("silver", 100+random(30));
}

void init()
{
	add_action("do_sha","sha");
}

int do_sha(string arg)
{
	   mapping fam;
      object ob,ob2,me = this_player();
	   fam = me->query("famliy");
	   

        if (!id(arg))
        return notify_fail("��Ҫɱ˭��\n");

        if( !fam = me->query("family") || fam["family_name"]!="佻�����")
                return 1;

	     this_object()->set("combat_exp",me->query("combat_exp")+5000);
	     this_object()->set("max_qi",me->query("max_qi"));
	     this_object()->set("eff_qi",me->query("eff_qi"));
	     this_object()->set("qi",me->query("qi"));
		
	   me->set_temp("obj",this_object()->query("name"));
	   me->kill_ob(this_object());
	   kill_ob(me);
         ob = new("/d/huanhua/npc/bzong");
         ob2 = new("/d/huanhua/npc/bzong");
         ob->move("/d/huanhua/"+place[random(sizeof(place))]);
 //       ob2->move("/d/huanhua/"+place[random(sizeof(place))]);
	   return 1;
}
