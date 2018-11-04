// dizi.c ����      

inherit NPC;

#include <ansi.h>
#include "dizi.h"
int ask_command();  
int do_clone(object me);
int do_push(string);
int ask_job();       
void check_fight(object ob);

void create()
{           
	object me = this_player();
	object ob = this_object();
	seteuid(getuid());
	set_name ("����", ({ "dizi" }));
        set("long", "����"+me->name(1)+"���״����ӣ�����Ľ���������£�����Ҳ���Ų���һ����Ц�ݡ�\n");
        set("age", 20+random(10));
	set("attitude", "friendly");
	set("gender", me->query("gender"));                           
	set("per", me->query("per"));
	set("shen_type", 0);
	set("no_return", 1);
       	set("inquiry",
                ([
                        "job" : (: ask_job :),
                        "command" : (: ask_command :),
     	]));

        set_skill("strike",100);
        set_skill("finger",100);
        set_skill("dodge",100);
        set_skill("force", 100);
	set_skill("canhe-zhi", 100);
	set_skill("murong-jianfa",100);
        set_skill("shenyuan-gong", 100);
	set_skill("yanling-shenfa", 100);
	set_skill("xingyi-zhang",100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("literate", 100);
        set_skill("murong-daofa", 100);
        set_skill("blade",100);

        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("strike", "xingyi-zhang");
        map_skill("parry", "canhe-zhi");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");
	prepare_skill("strike","xingyi-zhang");

        create_family("����Ľ��", 4,"����");
       	setup();
	carry_object("/clone/misc/cloth")->wear();       	
}
