
#include <ansi.h>
inherit F_BUKUAI;

void create()
{
        set_name("����", ({ "bu kuai", "bu" }));
	set("title", "��������");
        set("gender", "����");
        set("age", 30);
        set("str", 30);
        set("dex", 16);
        set("long", "�������Ÿ�����Ҫ���Ĳ���\n");
        set("combat_exp", 20000);
        set("shen_type", 1);
        set("attitude", "heroism");

        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 50);

        set("neili", 1000); 
        set("max_neili", 1000);
        set("jiali", 50);
        
        set("chat_chance",2);
        set("chat_msg",({
     "�������һ����˵�����������ھ�˭Ҳ����ɱ��...˭Ҫ��ɱ���˸������鷳�����������ȥ���Σ���\n",
     BLU"�����������ţ�����ɱ���ҲŲ�����أ�ȴ�������ܹ��ݣ�ֻ����ɱ�˵�����ȥ�Ҳż��ã���˾�����������...�ߺ�...\n"NOR,
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: random_move :),
        }));

        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/armor/tiejia")->wear();
}

void die()
{
	object ob;
	message_vision("$N���ڵ���,�����˼���,���ˡ�\n", this_object());
	ob = new("/clone/npc/bukuai");
	bu_move(ob);
	destruct(this_object());
}
