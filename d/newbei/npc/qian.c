// Room: /welcome/npc/qian.c
//By adx @ CuteRabbit 15:57 99-5-18

inherit F_BANKER;

void create()
{
        set_name("Ǯ�ۿ�", ({"qian yankai", "qian", "yankai"}));
        set("title", "Ǯׯ�ϰ�");
        set("nickname", "������");
        set("gender", "����");
        set("age", 34);
        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);
        set("qi", 500);
        set("max_qi", 500);
        set("jing", 100);
        set("max_jing", 100);
        set("shen", 0);

        set("combat_exp", 50000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 2);
        set("chat_msg", ({
        "Ǯ�ۿ�������˵�����������Ѿ����ϰ������ʷ���ڽ��Ͽ���˵�ǵ�һ�ҡ�\n",
        "Ǯ�ۿ�Ц��˵�����ڱ����Ǯ����Ϣ��ȡǮ��ʮ��֮һ�����ѣ��͹������Ű�ɡ�\n"
        }));
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);
        setup();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver",5);
}