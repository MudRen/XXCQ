// waiter.c

inherit NPC;

void create()
{
               int value;
                    value = random(10);
                 set("combat_exp", 1500 + 5*value);
         set_name("�ο�", ({ "you ke" }));
    set("age", 24);
        set("gender", "����");
          set("long", "����һλ�������۹������οͣ��糾���ӡ�");
        set("attitude", "peaceful");
          set("str", 24);
         set("max_qi", 300);
        set("dex", 16);
         set("shen", 1000);
        set_skill("cuff", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("force", 20);

        set("chat_msg", ({
                      "�ο�˵��������Ȼ���ƺ�ΰ���������Ҫ�ö��ˡ���\n",
        }));

         setup();
                  carry_object("/clone/misc/cloth")->wear();
              add_money("silve", 10 + value);
}
