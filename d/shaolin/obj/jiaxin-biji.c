// jiaxin-biji.c ����ݩ��
// by Load

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(WHT"����ݩ��"NOR, ({"jiaxin biji", "biji", "jiaxin"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����̬���ɱ��£�������ۣ����ֱ��з�ζ�ļ���ݩ����\n");
		set("unit", "��");
		set("value", 1);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
