// waiter.c

inherit NPC;

void create()
{
               int value;
                    value = random(10);
          set("combat_exp", 2000 + 5 * value);
          set_name("��å", ({ "liu mang" }));
    set("age", 24);
        set("gender", "����");
        set("long", "һ������ȥ�������������ˣ�������ҵ�������ܡ�");
        set("attitude", "peaceful");
          set("str", 24);
        set("dex", 16);
        set("shen", -800);
        set_skill("cuff", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("force", 20);

        set("chat_msg", ({
                "��å������Σ���֪����ʲô����\n",
        }));

         setup();
            carry_object("/clone/misc/cloth")->wear();
      add_money("silve", 15 + value);
}
