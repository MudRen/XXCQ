// liangjiushi.c

inherit NPC;
#include <ansi.h>

int ask_me(object who);
void create()
{
        set_name("���ʦ", ({ "niangjiu shi", "shi" }));
        set("gender", "����");
        set("age", 25);

        set("combat_exp", 4000);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_temp("apply/attack",  10);
        set_temp("apply/defense", 10);
        setup();

        set("inquiry", ([
        	"���" : (: ask_me :),
		"����" : (: ask_me :),
	]) );
        add_money("silver",3);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        if( interactive(ob=this_player()) && ob->query_temp("killwei") ) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

	say("���ʦЦ���е�˵��������λ" + RANK_D->query_respect(ob)
	     + "�������ʲô�����ģ������ҡ���\n");
}

int ask_me(object who)
{
        object room;

        if( !who || environment(who) != environment() ) return 0;

        if( !objectp(room = environment()) ) return 0;
	command("say ����׼������Ƶ�ԭ��--��������");
	command("say Ȼ�����������Ѹ�����װ��(zhuang)���С�");
	command("say ���Ѽ���(fire)��");
	command("say �õ����Ӻ���װ��(zhuang)�����С�");
	command("say �ٸ���������(fire)��");
	command("say �ռ���¶�󣬰���õľ��;����ڸ�Ҥ���档�ع����Ǹ����Ϳ�����(ask tang about job)��");
        return 1;
}

