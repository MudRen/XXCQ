// waiter.c

inherit NPC;

void create()
{
         int value;

         value = random(10);
       set_name("С�к�", ({ "kid" }));
           set("age", 8);
        set("gender", "����");
          set("long", "����һ��������֪��С�к������ں�С���һ���档");
        set("attitude", "peaceful");
        set("max_qi",50);
          set("str", 24);
        set("dex", 16);
          set("combat_exp", 200 + 5 * value);
                 set("shen", 0);

        set("chat_msg", ({
        }));

         setup();
           add_money("coin", 120 + value);
          carry_object("/clone/misc/cloth")->wear();
}
