// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;
void away();

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
"changjian","dandao","gangjian","gangdao","changbian","zhubang","changqiang","qimeigun"
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
	
	set("combat_exp", 1000);
	
	set_skill("force", 10);
	set_skill("strike", 10);
	set_skill("cuff",10);
	set_skill("dodge", 10); 
	set_skill("whip", 10); 
	set_skill("spear", 10); 
	set_skill("axe", 10); 
	set_skill("club", 10); 
	set_skill("stick", 10); 
	set_skill("sword", 10); 
	set_skill("staff", 10); 
	set_skill("blade", 10); 
	set_skill("parry", 10); 
	set_skill("literate", 10); 
	
	setup();

	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/" + weapon[random(sizeof(weapon))])->wield();

	set("chat_chance", 20);
	set("chat_msg", ({
		(: away :),
	}));
        add_money("silver", 30+random(30));
}

void away()
{
	if( living(this_object()) )
	{
		message_vision(this_object()->query("name") + "һ�����Ѿ��������������ʧ�ˡ�\n", this_object());
		destruct(this_object());
	}
	return;
}
