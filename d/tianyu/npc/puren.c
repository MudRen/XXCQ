// Npc: ����
// Date: by godzilla 1999.11.18

inherit NPC;

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
        
        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
}
