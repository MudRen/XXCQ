// xuantieshi.c  ����ʯ  ����ԭ��
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// ������������ʱ��Ҫ��һ��ԭ��
// ���� material_ attrib = x Ϊ�жϱ�־������Ч����Ϊ:power_point
// ��Ч������ 100

void create()
{
	set_name(WHT "����ʯ" NOR, ({"xuantie shi", "shi"}));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ��������ʯͷ���������������ۣ��������ַǳ����ء�\n" NOR);
		set("unit", "��");
		set("material_attrib", "x");
		set("power_point", 100);
		set("value", 40000);
	}
}
