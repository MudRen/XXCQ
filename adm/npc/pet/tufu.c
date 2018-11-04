// ɾ�����NPC
// By ɽèAdx @ snow 99-12-12

inherit NPC;

void create()
{
        set_name("����", ({ "tufu" }) );
        set("gender", "����" );
        set("age", 35);
        set("long", "һ����������ӣ��ͺ���ļһ\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 25000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);

        setup();
        add_money("silver", 2);
        add_money("coin", 500);
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_sha","sha");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 2:
                        say( "�����ֿ�����, Ц�ŵ�����λ"  
                                + RANK_D->query_respect(ob)
                                + "��Ҫ��������? \n");
                        break;
        }
}

int do_sha(string arg)
{
	object me;
	object obj;
	string file;
	me = this_player();
	if(!arg) return notify_fail("ָ���ʽ��sha <name>\n");
	        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û��"+arg+"��\n");
	if(base_name(obj) == "/adm/npc/pet/pet" && obj->query("owner") == me->query("id")
	&& obj->query("possessed") == me)
	{
	message_vision("$N������˵�����Ҵ����$n�����Լ����̶��֣�\n",me,obj);
	message_vision("$N����һ����һ��ľ������$n��ͷ��һ����\n",this_object(),obj);
	message_vision("$N�����������������ᡭ��\n",obj);
	obj->die();
	me->delete("pet");
	seteuid(ROOT_UID);
	file = obj->query_save_file()+".o";
	rm(file);
	seteuid(getuid());
	destruct(obj);
	return 1;
	}
	return notify_fail("�㲻������ô����\n");
}
