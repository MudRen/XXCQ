// waiter.c
inherit NPC;

void create()
{
        set_name("������", ({ "zhou tiejiang", "zhou", "tiejiang", "smith"
}) );
        set("gender", "����" );
        set("title","����");
        set("age", 42);
        set("long",
                "��������ʮ���꣬���û�����������\n");
        set("combat_exp", 10000);
        set("attitude", "peaceful");

        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("literate", 40);

        set("max_qi", 600);
        set("max_jingli", 600);


        set("vendor_goods", ({
                __DIR__"obj/bishou",
                __DIR__"obj/tiefu",
                "/clone/weapon/changjian",
        }));
        setup();

        carry_object(__DIR__"obj/cloth")->wear();

}

 void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

