// waiter.c

inherit NPC;

void create()
{
               int value;
                    value = random(10);
            set("combat_exp", 1500 + 5 * value);
         set_name("��Ů", ({ "woman" }));
           set("gender", "Ů��");
     set("long", "һ��Ѱ���ĸ���.");
       set("max_qi",120);
    set("age", 24);
        set("attitude", "peaceful");
          set("str", 24);
        set("dex", 16);
        set("shen", 100);
        set_skill("dodge", 20);
          set("cuff", 20);
        set_skill("parry", 20);
        set_skill("force", 20);

        set("chat_msg", ({
                     "����������Σ��ƺ��������ĺ��ӡ���\n",
        }));

         setup();
          carry_object("/clone/misc/cloth")->wear();
            add_money("silver", 15 + value);
}
