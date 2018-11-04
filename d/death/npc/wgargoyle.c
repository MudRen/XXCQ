// wgargoyle.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;
int ask_me();
int ask_bing();
object creat_weapon();

string *death_msg = ({
	HIW "���޳�˵����ι�������ģ����ʲô���֣�\n\n" NOR,
	HIW "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,
	HIW "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,
	HIW "���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,
	HIW "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n"
		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});

void create()
{
	set_name("���޳�", ({ "white gargoyle", "gargoyle" }) );
	set("long",
		"���޳�������������ͷ�����㣬���׵����Ͽ������κ�ϲŭ���֡�\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
//		(: this_object(), "random_move" :),
		"���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",
		"���޳��ѳ�������ͷ��������������������Լ��ְ��ֳ�����ָ��\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
	set("max_jing", 900);
	set("max_qi", 900);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);

	set("inquiry", ([
		"��ħ����"       : (: ask_me :),
		"����"           : (: ask_bing :),
	]));

	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object())
	||	wizardp(previous_object()) ) return;
	call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	int i;
	object *inv,me;
	me = this_player();
	if( !ob || !present(ob) ) return;
	
	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();
	
        inv =  all_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
                DROP_CMD->do_drop(ob, inv[i]);
	ob->move(REVIVE_ROOM);
	ob->set("startroom",REVIVE_ROOM);
	message("vision",
		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
		"�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
	
}

int ask_me()
{
        mapping my_fam;
 
        object  me;
	int my_age, already_age;

	me = this_player();
        my_fam = (mapping)me->query("family");
	my_age = me->query("age");
	already_age = (int)me->query("already_age");

        if (my_fam["family_name"] != "ؤ��")
		return notify_fail("�㲻��ؤ��ĵ��ӣ�������ħ���塣\n");

	if( already_age >= my_age)
		return notify_fail("��������ħ��������Ѿ������ˣ�\n");

	if( (int)me->query("max_neili") < 50)
		return notify_fail("����������������ħ����󷨣�\n");

	if(random(5) >= 2)
	{
		me->add("con",1);
		me->add("con_improve_time", 1);
		me->add("max_neili", -50);
		me->set("already_age", my_age);
	        message_vision(HIY"ֻ�����޳��������еĿ�ɥ�����૵����˼��������ڵ������ͻȻ��\n" +
			"��һ�����磬�������ͷ������ֻ���û������Ǳ�������һ��ů���С����\n" +
			"���������ˣ�\n"NOR, me);
	}
	else
		message_vision(HIY"ֻ�����޳��������еĿ�ɥ�����૵����˼���������ʲôҲû������\n"NOR, me);
	return 1;
	
}

int ask_bing()
{
	object me,weapon,obj;
	string w_id;
	me = this_player();
	w_id = me->query("weapon/����");
	if( (me->query("weapon/����")) ) {
		if( objectp(obj = present(w_id, me)) ) {
			say("���޳���ɫһ���������������������ֱ�ô��������ʲô��\n");
		}
		else	{
		weapon = creat_weapon();
		weapon->move(me);
		message_vision(HIY "ֻ�����޳��������еĿ�ɥ�����૵����˼��������Ȼһ��������ڵ�����\n"+
				"��������������$N�����岻���ˣ�\n" NOR, me);
		}
		return 1;
		}
	else	{
		message_vision(HIY "���޳�ŭ��һ����������թƭ����!!\n" NOR, me);
		message_vision(HIR "���������޳���ͷ�$N\n" NOR, me);
		return 1;
	}
}

object creat_weapon()
{
	object me,weapon;
	string mask;	//the verible that record the type of weapon
	me = this_player();
	mask = me->query("weapon/����");
	switch(mask)	{
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_sword",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_blade",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_club",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_staff",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_whip",1);
			return weapon;
	}
}
