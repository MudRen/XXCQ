// tangltt

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int do_pull();
void close(object room);

void create()
{
	set_name("����̫̫", ({ "tangltt", "tang", "tai"}));
//	set("nickname", "Сʦ��");
	set("long", 
"�Ʒ���Ľ�С�����ļ�Ϊ���㣬�ִ�����Ӣ�����徢����������\n"
"�������ų���������Ң˴֮Ů�����ֵ�����̫̫�����²��������ŵ�λ�ĸߡ�\n");
	set("gender", "Ů��");
	set("age", 89);
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
	set("combat_exp", 2000000);
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
	set("inquiry", (["����ү��" : (:do_pull:),]));
	setup();

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query ("family/family_name") != "�Ĵ�����" || (int)ob->query ("combat_exp") < 600000 )
	{
        	command("say �㻹���Ȱ�Ң˴Ϊʦ��ѧЩ���ŵĻ�������ɣ�\n");
                return;
        }

    command("say �ðɣ��ӽ�����������ҵĹ��ŵ����ˡ�\n");
    command("recruit " + ob->query("id"));
}

int do_pull()
{
	object me, room;
	me = this_player();
	room = environment(this_object());
	message_vision(YEL"\n����̫̫һת���ڴ�ͷ�⶯��һ�¡�\nֻ�������̡��������촲�ŵĵ����ƿ���һ�����ڡ�\n"NOR, me);
	room->set("exits/down", "/d/tangmen/didao1");
	remove_call_out("close");
	call_out("close", 3, environment(this_object()));
	return 1;
}

void close(object room)
{
	message("vision",HIR"�����һ�����죬���ǰ����ֱ������ˡ�\n"NOR, this_player());
	room->delete("exits/down");
}