// Room: /d/shaolin/qfdian.c
// Date: YZC 96/01/19

#include <room.h>
#include <ansi.h>
inherit ROOM;
int consider_lv(object ob,int a);

void create()
{
	set("short", "���䷿");
	set("long", @LONG
���䷿�����ֹ���֮һ�����о�����أ��������ڿ��Ժܿ������
�书����������ʿ��������ĵط����㻷�����ܣ��������������ɼ���
���ıھ���һЩһ�߿����߸ߵ�ľ���������������Կ��������������
��ľ�ˡ�
LONG );
	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"luohan_n",
	]));

	setup();
}

void init()
{
	object me;
	int x;
	x = 11;
	me = this_player();

	if (userp(me) && me->query_temp("kfroom_2"))
		call_out("combat_go", 1, me, x);
	return;
}

int combat_go(object me, int x)
{
	object ob;

	if ( x > 1 && userp(me))
	{
		if (x==11)
			message_vision(HIC"\nһ�߽����䷿,���ܵ�ʮ����ľ���б������˿���������,�ƺ��л��ؿ����ˡ�\n"NOR, me);
		ob = new(__DIR__"npc/muren");
		ob->set("combat_exp",me->query("combat_exp"));
		ob->set("max_qi",me->query("max_qi"));
		ob->set("eff_qi",me->query("max_qi"));
		ob->set("qi",me->query("max_qi"));
		ob->set("max_jingli",me->query("max_jingli"));
		ob->set("eff_jingli",me->query("max_jingli"));
		ob->set("jingli",me->query("max_jingli"));
		ob->set("max_neili",me->query("max_neili"));
		ob->set("neili",me->query("max_neili"));
		ob->set_skill("force", consider_lv(ob, 8.5));
		ob->set_skill("dodge", consider_lv(ob, 8.5)); 
		ob->set_skill("club", consider_lv(ob, 8.5));
		ob->set_skill("parry", consider_lv(ob, 8.5)); 
		ob->move("/d/shaolin/kfroom_2");

		if (!objectp(present(me->query("id"), environment(ob))))
		{
			destruct(ob);
			return 0;
		}
		
		COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), 0);
		me->add("combat_exp", 15+random(15));
		me->add("potential", 9+random(9));
		destruct(ob);

		call_out("combat_go", 5, me, x -= 1);

		return 1;
	}
	else
	{
		message_vision(HIW"\n�����Ļ���������С���������������ѵ�������ˡ�\n"NOR, me);
		message_vision(HIW"\nͻȻ������������ľ�ˣ�����ܳ����䷿��\n"NOR, me);
		me->move(__DIR__"luohan_n");
		me->delete_temp("kfroom_2");
		environment(me)->delete_temp("kfroom_2");
		me->apply_condition("kf_job",12);
	}
	return 1;
}

int consider_lv(object ob,int a)
{
	int level; 
	float exper;

	exper = to_float(ob->query("combat_exp"));
	level = ceil( pow( exper*10.0, 0.333333) );

	level = level * a / 10;

	return level;
}

int valid_leave(object me, string dir)
{
	if( me->query_temp("kfroom_2") && dir == "west")
	{
		me->apply_condition("kf_job",12);
	}
	return ::valid_leave(me, dir);
}