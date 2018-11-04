//  modify by mulan
// Date: YZC 96/01/19

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/shaolin/other.h"
void recover_ob();

void create()
{
	set_name("���", ({
		"tian guan",
		"tian",
		"guan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);


	set("nickname", HIB"�����޺�"NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 800000);
	set("score", 500000);

	set_skill("force", 130);
	set_skill("wuxiang-shengong", 130);
        set_skill("banruo-changong",130);
	set_skill("dodge", 110);
	set_skill("shaolin-shenfa", 110);
	set_skill("strike", 130);
	set_skill("parry", 110);
	set_skill("huoyan-dao", 130);
    set_skill("buddha", 130);
	set_skill("literate", 110);

	map_skill("force", "wuxiang-shengong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "huoyan-dao");
	map_skill("parry", "huoyan-dao");

	prepare_skill("strike", "huoyan-dao");

	create_family("������", 36, "����");

	setup();

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "strike.fen" :),
		(: recover_ob :)
	}) );

        carry_object("/d/shaolin/npc/obj/heijiasha")->wear();
        carry_object("/d/shaolin/npc/obj/sengxie")->wear();
}

void recover_ob()
{
	command("yun recover");
	return;
}
void check(object me)
{
        object ob;
        mapping my_fam;

        ob = this_object();

        my_fam = me->query("family");

        if ( my_fam && my_fam["master_id"] == ob->query("id")
                && me->query_skill("wuxiang-shengong",1) > 120
                && me->query_skill("buddha",1) > 120
                && (me->query_skill("weituo-gun",1) > 120 || me->query_skill("luohan-quan",1)> 120)
                && !me->query("bai_mu")
                && environment(me)==environment(ob))
        {
                command("pat " + me->query("id"));
                command("say ���ڷ��ù���ѧ�����ɣ�Ϊʦ�ܽ�����Ѿ������ˡ�");
                command("say ��ȥ���Ű�����ʦ�岮�����߿�����λľ�ֱ���ʦ��Ը������ɡ�");
                command("say �Ժ�Ҫ����Ϊʦ�Ľ̻壺�˳���Ⱦ�����⿪�������ޡ�ȥ�ɡ�");
                me->set("bai_mu", 1);
        }
}

void check_shou(object me)
{
        object ob;
        mapping my_fam, ob_fam;
        string name, new_name;

        ob = this_object();
        name = me->query("name");

        my_fam = me->query("family");
        ob_fam = ob->query("family");

        if (my_fam){
        if ( me->query("bai_tian") && (ob_fam["generation"] + 2 == (my_fam["generation"] )) )
        {
                command("say " + me->query("name") + "����ʦ��" + my_fam["master_name"] + "�����Ƽ����㡣");
           if (me->query_skill("wuxiang-shengong",1)<60)
                {
           command("say �ҵĹ�����Ҫһ��������������������ѧ���˵ġ�");
                        command("say �㻹��ȥ�����������ֱ����Ӱɡ�");
                        return;
                }
                else 
                {
                        me->delete("bai_tian");
                        new_name = "��" + name[2..3];
                        me->set("name", new_name);
                        command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ���������ֱ����� !");
                        command("recruit " + me->query("id"));
                        return;
                }
        }
        else if (ob_fam["generation"] + 1 == (my_fam["generation"] ))
        {
      if (me->query_skill("wuxiang-shengong",1)<60)
                {
           command("say �ҵĹ�����Ҫһ��������������������ѧ���˵ġ�");
                        command("say �㻹��ȥ�����������ֱ����Ӱɡ�");
                        return;
                }
                command("recruit " + me->query("id"));
        }
        else
        {
                command("say " + me->query("name") + "��δ����ʦ���Ƽ����Ҳ������㣬���ȥ�ɡ�");
                return;
        }
        }
}
