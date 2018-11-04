// gangdao.c

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
int do_chou(string arg);
int do_shou(string arg);

void create()
{
	set_name(YEL"����"NOR, ({ "tiaozhou" }));
	set_weight(9000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
һ������ͨͨ�����㡣
LONG);
		set("value", 100);
		set("nopawn",1);
		set("material", "wood");
		set("wield_msg", CYN"$N�������е����㵱��������\n"NOR);
	}
	init_sword(5);
	setup();
}

void init()
{
	add_action("do_chou","chou");
	add_action("do_shou","shou");
}

int do_chou(string arg)
{
	object me, ob;

	me = this_player();
	ob = this_object();

	if (!arg || (arg!="jian" && arg!="sword") || ob->query("val"))
		return notify_fail("��Ҫ��ʲô��\n");

	message_vision(YEL"$N����������������һ�ѶϽ���һ���޹�ɫ���¾ɡ������ơ������һ��ĶϽ���\n"NOR, me);
	ob->set_name(YEL"���ɲ���"NOR, ({ "gusong canque","canque", "jian","sword" }));
	set("long", @LONG
����һ���޹�ɫ���¾ɡ������ơ������һ��ĶϽ���
LONG);
	ob->set("value", 50000);
	ob->set("nopawn",1);
	ob->set("no_break", 1);
	ob->set("endure", 150);
	ob->set("val",1);
	ob->set("material", "steel");
	ob->set("wield_msg", HIY"$N�������е�"NOR + YEL"���ɲ���"HIY"�������������������������\n"NOR);
	ob->set("weapon_prop/damage",70);
	return 1;
}

int do_shou(string arg)
{
	object me, ob;

	me = this_player();
	ob = this_object();

	if (!arg || (arg!="jian" && arg!="sword") || !ob->query("val"))
		return notify_fail("��Ҫ��ʲô��\n");

	message_vision(YEL"$N�����ɲ��������ջ����ǰ�����ͨͨ�������С�\n"NOR, me);
	ob->set_name(YEL"���ɲ���"NOR, ({ "gusong canque","canque", "jian","sword" }));
	ob->set_name(YEL"����"NOR, ({ "tiaozhou" }));
	ob->set("long", @LONG
һ������ͨͨ�����㡣
LONG);
	ob->set("value", 100);
	ob->set("material", "wood");
	ob->set("val",0);
	ob->set("wield_msg", CYN"$N�������е����㵱��������\n"NOR);
	ob->set("nopawn",1);
	ob->set("weapon_prop/damage",5);
	return 1;
}
