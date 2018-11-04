// xiaoer2.c �Ƶ�С��

inherit F_DEALER;
int ask_me1();
int ask_me2();

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("title", "����¥���������");
	set("long",
		"��λ��С����Ц�����æ�����Ѿ��۵���ͷ���ˡ�\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
		"d/bianliang/npc/obj/dhjiudai",
		"d/bianliang/npc/obj/shaoji",
		"d/bianliang/npc/obj/kaoya",
	}));
        set("inquiry", ([
                "����ϯ" : (: ask_me1 :),
                "����" : (: ask_me2 :),
        ]) );
	setup();
	carry_object("clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 

	ob = this_player();

	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, ob);

	add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_qinghe", "qinghe");
}

int ask_me1()
{
	command("say �����ﶨ��ϯ100���ƽ�һ���������˸��粻�ޡ�\n");
	return 1;
}

int ask_me2()
{
	if (this_player()->query_temp("marks/����")) {
		command("say Ŷ������������Ŀ�����ɣ�");
		this_player()->move(__DIR__"sanhelou21");
		return 1;
	}
	command("say �㲢û�б����������簡��");
	return 1;
}

int accept_object(object who, object ob)
{
	if(ob->query("money_id") && (ob->value() >= 1000000)) {
		command("say ��λ�͹٣������ľ�ϯҪ���ʲô�أ�ָ���ʽ��qinghe <����>");
		who->set_temp("marks/����",1);
		return 1;
	}
	return 0;
}

int do_qinghe(string arg)
{
	object me;
	me = this_player();

        if( !me->query_temp("marks/����") ) return 0;

	if( !arg ) return notify_fail("ָ���ʽ��qinghe <����> \n");

	me->set_temp("marks/����", arg);
	command("say ��λ�͹٣���Ҫ���"+arg+"���ã��뵽������Ժ���׼��ȥ��");
	command("say �����ڿ�������(yaoqing)����Ҫ��Ŀ��ˡ�");
	command("say �����������Ը���(answer)�ҿ�ϯ��");
	me->set_temp("marks/����",1);
	me->delete_temp("marks/����");
	me->move(__DIR__"sanhelou21");
	return 1;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "������Ҫ����ϯ�ɣ�\n");
                        break;
                case 1:
                        say( "С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "������������\n");
                        break;
        }
}
