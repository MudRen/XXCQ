// Npc: ����
// Date: by godzilla 1999.11.18

inherit NPC;
int ask_zhao();
void create()
{
	set_name("����", ({ "pu ren", "ren" }));
        set("gender", "����");
        set("age", 30+random(30));       
        set("str", 17);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("combat_exp", 2000);
        set("attitude", "peaceful");
        set("max_qi",800);
        set("max_jingli",800);
        set("neili",600);
        set("max_neili",600);
        
        set_skill("dodge", 20);
        set_skill("unarmed",20);
        set_skill("parry",20);
        
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set("inquiry", ([
        "��ʲô"       : (: ask_zhao :),
        "������": "������������������������ɵ��ӵ����֣��������û�����ֵĵ��ӻ������������ɵ���",
         ]));
        set("chat_chance",2);
        set("chat_msg",({
                "������������������ˣ����Ѿ����˰��춼�Ҳ����������ˡ���\n",
                "�����������������������������������������ǣ���ش󰡣���\n",
                "�����ڲݴ���æµ�������š�\n",
        }) );        
        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
}
int ask_zhao()
{
	object me;
	me=this_player();
	if(me->query("family/family_name")!="������")
	{
		command("say û...ûʲô������������ˣ����������ɵļ����¡�\n");
		return 1;
	}
	me->set_temp("do_find_ce",1);
	command("say �ˣ������ɵĻ����ᶪ�ˣ��������������أ���Ϊ"+RANK_D->query_respect(me)+"�������Ұ�(search)��\n");
	command("say ����ҵ�������������û��������֣�û�о��ڲ���д�ϴ���(write) ��\n");
	return 1;
}	