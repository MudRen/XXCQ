// heizhenshi.c  ����ʯ  ����ԭ��
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// ������������ʱ��Ҫ��һ��ԭ��
// ���� material_ attrib = x Ϊ�жϱ�־������Ч����Ϊ:power_point
// ��Ч������ 30

void create()
{
	set_name(YEL "����ʯ" NOR, ({"heizhen shi", "shi"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ��������ʯͷ���置���������������ĵ���\n" NOR);
		set("unit", "��");
		set("material_attrib", "x");
		set("power_point", 30);
		set("value", 6000);
	}
}
