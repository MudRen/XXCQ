// gangdao.c

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;

void create()
{
	set_name(HIC"����"NOR, ({ "changge","jian","sword" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
������߰����¾ɡ����⣬ֻ�н����һ������������š�һ���Ʋ�����ˮ
�⵫���綾��������ĺ�â��
����һ�����������������ﴳ���������彣�����Ž����裡
LONG);
		set("value", 50000);
		set("no_break", 1);
		set("endure", 150);
      set("no_get","���˵Ķ����Ͳ�Ҫ����!\n");
      set("no_give","�����������������");
		set("material", "steel");
		set("wield_msg", CYN"$N�������а����������������г��"HIC"����"NOR+CYN"�Ž�����������һ��"HIB"���⡣\n"NOR);
		set("unwield_msg", "$N�����е�$n���뽣�ʣ�����ϸ���ð����ѽ�����������\n");
	}
    init_sword(100);
	setup();
}
