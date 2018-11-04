// jieyinshi.c �ӿ�ͯ��
// netkill 1998/9/4

#include <ansi.h>
inherit NPC;
int panchan();

string ask_me(string name);

void create()
{
        set_name("�ӿ�ͯ��", ({ "tong zi", "tong" }));
        set("long", "����һλר�ŽӴ�����ҵ�ͯ��\n");
        set("gender", "����");
        set("age", 18);

        set("shen_type", 1);
         set("inquiry", ([
		"�̲�" :   (: panchan :),
		"ʳ��" :   (: ask_me, "jitui" :),
		"ˮ" :   (: ask_me, "jiudai" :),
        ]) );
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
                say("ͯ��˵���������û���̲��Ļ�����������Ҫ"+HIW"(ask tong about �̲�)"NOR+"��\n");
                say("           �����û�гԵģ���������Ҫ"+HIW"(ask tong about ʳ��)"NOR+"��\n");
                say("           �����û��ˮ����������Ҫ"+HIW"(ask tong about ˮ)"NOR+"��\n");
}

int panchan()
{
	object ob,me=this_player();
        int i=me->query_temp("silver");
        if  ( i < 10 )
        {
        ob=new("/clone/money/silver");
        ob->move(me);
        message_vision("�ӿ�ͯ�Ӹ�$NһЩ������\n",me);
        i=i+1;
        me->set_temp("silver", i);
        }
        else return 0;
        return 1;
}

string ask_me(string name)
{
	object ob;

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���Ȱ����ϵĳ��ˣ�chi jitui��������Ҫ��\n"+
		"����Ե���ˮ�ĵط�װˮ��zhuang jiudai��\n";

	ob = new(__DIR__"obj/" + name);
	ob->move(this_player());

	message_vision(YEL"�ӿ�ͯ�Ӹ�$Nһ��" + ob->query("name") + "��\n"NOR, this_player());

	return "����";
}
