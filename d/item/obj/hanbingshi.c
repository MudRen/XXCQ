// hanbingshi.c  ����ʯ  ����ԭ��
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// ������������ʱ��Ҫ��һ��ԭ��
// ���� material_ attrib = x Ϊ�жϱ�־������Ч����Ϊ:power_point
// ��Ч������ 75

void create()
{
	set_name(HIG "����ʯ" NOR, ({"hanbing shi", "shi"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ���̵�͸����ʯͷ��������ģ��ǳ����졣\n" NOR);
		set("unit", "��");
		set("material_attrib", "x");
		set("power_point", 75);
		set("value", 20000);
	}
}
