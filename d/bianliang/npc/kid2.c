// waiter.c

inherit NPC;

void create()
{
               int value;
                    value = random(10);
           set("age", 8);
            set_name("СŮ��", ({ "kid" }));
          set("age", 8);
         set("long", "����һ��������֪��СŮ�������ں�С���һ���档");
        set("attitude", "peaceful");
         set("max_qi",20);
          set("str", 24);
        set("dex", 16);
            set("combat_exp", 200 + 5 * value);
                 set("shen", 0);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("force", 20);


         setup();
            carry_object("/clone/misc/cloth")->wear();
      add_money("coin", 120 + value);
}
