// tanglyz

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����ү��", ({ "tanglyz", "tang", "yezi"}));
//	set("nickname", "Сʦ��");
	set("long", 
"�Ʒ���Ľ�С�����ļ�Ϊ���㣬�ִ�����Ӣ�����徢����������\n"
"�������ų���������Ң˴֮Ů�����ֵ�����̫̫�����²��������ŵ�λ�ĸߡ�\n");
	set("gender", "����");
	set("age", 91);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 18);
	set("int", 25);
	set("con", 24);
	set("dex", 28);

	set("max_qi", 5000);
	set("max_jingli", 2000);
	set("max_douzhi", 1000);
	set("douzhi", 1000);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 50);
	set("combat_exp", 2500000);
	set("score", 10000);

	set_skill("force", 300);
//	set_skill("zixia-shengong", 30);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("blade", 300);
	set_skill("strike", 300);
/*	set_skill("hunyuan-zhang", 50);
	set_skill("huashan-jianfa", 50);
	set_skill("huashan-shenfa", 50);
	set_skill("fanliangyi-dao", 30);

	map_skill("force", "zixia-shengong");
	map_skill("blade", "fanliangyi-dao");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");
*/
	create_family("�Ĵ�����", 2, "����");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query ("family/family_name") == "�Ĵ�����" && (int)ob->query ("combat_exp") > 1000000 )
	{
		message_vision("����ү��΢΢һЦ����$N˵��:�����ʦ�Ļ�ȥ����̫̫�ɣ����Ѿ�����ͽ���ˣ���",ob);
		message_vision("����ү��΢΢һ�٣��ֵ�:����������Ȼ���Ѿ��ҵ��������ˣ��Ҿ�ָ���㼸�аɣ���",ob);
/*
	�˶������������ү�ӵ���ָ��Ĺ���!!!!

*/
	}
	else
		if ( (string)ob->query ("family/family_name") != "�Ĵ�����" )
		{
			message_vision("\n����ү��΢΢һЦ����$N˵��:���㲻֪�������������ң��������յ������\n",ob);
			message_vision("����ү��΢΢һ�٣��ֵ�:����������Ȼ���Ѿ��ҵ��������ˣ��ͺȱ������߰ɣ���\n",ob);
			tell_object(ob, "����ү�Ӽ�����Щ��ԥ��˵��:�������Ǽ�����󣬺��˿��Թ̱���Ԫ����ϰ��֮�˿��Ǵ������氡����\n\n");
			write(YEL"��Ҫ����������ѡ��y)/n ��"NOR);
			input_to("accept_cha", 1, ob, 1);
		}
		else
			tell_object(ob, "����ү����ϧ�Ķ���˵:����ϧ��Ĺ��򻹲����ң�����ʹ���ҵľ��������Ժ������ɣ���\n");
	return;
}

void accept_cha(string want, object ob, int forever)
{
	if ( want == "" || want == "y" || want == "Y" )
	{
		message_vision("����ү��΢һ̧�֣�����һ�Ҷ���$N������һ����裡\n",ob);
		tell_object(ob, "ֻ����ˮ������������ɫ����ð����������Ƭ��֪����ҶƬƯ�ڱ��У������������˱ǡ�\n");
		message_vision("$N���豭���������ĺ���һ�ڡ�\n", ob);
		call_out("dead", 120, ob);
	}
	else
	{
		message_vision("\n����ү�Ӳ�Ȼ��ŭ����$N�ȵ�:����������㲻Ҫ����Ҫ�Ҷ������������ǲ��ܱ�����֪���ģ���\n",ob);
		this_object()->kill_ob(ob);
		ob->fight_ob(this_object());
	}
}

int dead(object ob)
{
	tell_object(ob,HIR"�㸹��ͻȻ�絶��һ����ʹ��ԭ�����о��Ǿ綾......\n����ǰһ�ڣ�һͷ�Ե��ڵ���......"NOR);
	tell_room( environment(ob), HIR + ob->query("name") + "ͻȻһͷ�Ե��ڵ��ϣ�"NOR, ob);
	ob->die();
	tell_room( environment(this_object()), "����ү�ӳ�̾һ��:������������ô�ᴳ�������أ���");
}