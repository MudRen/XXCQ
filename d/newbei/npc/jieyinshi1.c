// jieyinshi.c �ӿ�ͯ��
// CLEANSWORD 1996/2/2

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("�ӿ�ͯ��", ({ "tong zi" }));
        set("long", "����һΪר�ŽӴ�����ҵ�ͯ��\n");
        set("gender", "����");
        set("age", 18);

        set("shen_type", 1);
        setup();

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
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
		say("ͯ��˵������λ"+ RANK_D->query_respect(ob)
                 + ",��ӭ����Сѩ���磬������������ߣ�������������ߡ�\n");
}
