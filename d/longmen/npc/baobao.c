// xian. ���ϰ�

inherit F_DEALER;

void create()
{
        set_name("����", ({ "bao bao", "bao" }));
        set("title", "��¥�ϰ�");
        set("shen_type", 1);

        set("str", 20);
        set("gender", "����");
        set("age", 45);
        set("long", "������Ӫ�洫�����ľ�¥���ж��ꡣ\n");
        set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set("vendor_goods", ({
                __DIR__"obj/hdjiudai",
                __DIR__"obj/kaoya",
        }));

        setup();
        add_money("gold", 1);
        carry_object("/clone/misc/cloth")->wear();
}

