// Room: /welcome/npc/smith.c
//By adx @ CuteRabbit 15:57 99-5-18

inherit F_DEALER;

void create()
{
        set_name("����", ({ "tiejiang", "smith" }));
	set("title", "�������ϰ�");
	set("shen_type", 1);

        set("gender", "����" );
        set("age", 33);
        set("long", "����������ǯ��סһ����ȵ�����Ž�¯�С�\n");

        set("combat_exp", 400);
	set("attitude", "friendly");
        set("vendor_goods",({
		__DIR__"obj/changbian",
		__DIR__"obj/changjian",
		__DIR__"obj/changqiang",
		__DIR__"obj/dagger",
		__DIR__"obj/duanjian",
		__DIR__"obj/gun",
		__DIR__"obj/qimeigun",
        }));

	setup();

        carry_object("/clone/misc/cloth")->wear();
	add_money("silver",1);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

/*
int buy_object(object who, string what)
{
        if( what=="hammer" ) return 300;
        if( what=="changjian" ) return 700;
        return 0;
}

void compelete_trade(object who, string what)
{
        object ob;
        
        if( what=="hammer" )  ob = new("clone/weapon/hammer");
        if( what=="changjian" )  ob = new("clone/weapon/changjian");
        ob->move(who);
        if( what=="hammer" )
message_vision("$N����$nһ������Ĵ�����������\n", this_object(), who);
        if( what=="changjian" )
message_vision("$N����$nһ����������ĳ�����\n", this_object(), who);
}
*/ 
