// bguanli

inherit NPC;

int do_giveto(object me, object obj);

void create()
{
	set_name("�Ҷ�", ({ "jia ding", "ding"}));
	set("long", 
"�Ҷ�xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx��\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 18);
	set("int", 25);
	set("con", 24);
	set("dex", 28);

	set("combat_exp", 30000);

	set_skill("force", 30);
	set_skill("dodge", 60);
	set_skill("parry", 40);
	set_skill("sword", 50);
	set_skill("blade", 40);
	set_skill("strike", 50);

	create_family("�Ĵ�����", 10, "�Ҷ�");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_give","give");
}

int do_give(string arg)
{
	object obj, obj2, me, *inv, who;
	string item;
	int amount, i;

	me = this_player();

	if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if( sscanf(arg, "%s to ding", item) == 1 || sscanf(arg, "ding %s", item)==1 );
		else 
			return notify_fail("��Ҫ��˭ʲô������\n");

	if(!objectp(who = present("jia ding", environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");

	if(sscanf(item, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("������û������������\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else 
			if( amount == (int)obj->query_amount() )
				return do_giveto(me, obj2);
			else
			{
				obj->set_amount( (int)obj->query_amount() - amount );
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
				if (do_giveto(me, obj2))
					return 1;
				else
				{
					obj->set_amount((int)obj->query_amount() + amount);
					return 0;
				}
			}
	}

	if(arg=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			do_giveto(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_giveto(me, obj);
}

int do_giveto(object me, object obj)
{
	string tar, targ;
	int tarm;
	string *duwu = ({
		"","���","��Ы��","��Ҷ��","����","����","ǧ�궾��",
	});
	tar = (string)obj->query("name");
	tarm = (int)me->query_temp("duyao");
	targ = (string)duwu[tarm];

	if( !environment() || base_name(environment()) != query("startroom") )
	{
		write("�Ҷ�˵�������Ǳ�Ǹ��������һ�µ����Ϸ������Ұɡ�\n");
		return 0;
	}

	printf("1%s1 == 1%s1 == %d/%d\n",tar,targ,tarm,sizeof(duwu));

	if ( !(int)me->query_temp("duyao") || !(int)me->query_temp("tangmen") )
	{
		message_vision("�Ҷ��ܹ���Ŀ���$N��Ƿ��˵��������Ӧ��û��������Ĺ����ɣ���\n", me);
		return 0;
	}	

	if ( (tar == targ) && objectp(obj) )
	{
		message_vision("�Ҷ�����$Nһ����˵�������������ˣ������ͽ����Ұɣ���\n", me);
		destruct(obj);
		me->delete_temp("tangmen");
		me->delete_temp("duyao");
		me->add("combat_exp", 150 + random(150));
		me->add("potential", 80 + random(30));
		return 1;
	}
	else
	{
		message_vision("�Ҷ���Ϊ�ѵĿ���$N��Ƿ��˵�������ⲻ����Ӧ���ҵ��Ķ����ɣ���\n", me);
		return 0;
	}
}