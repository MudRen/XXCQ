// tianchansi.c  ���˿  ����ԭ��
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// ������ߴ���ʱ��Ҫ��һ��ԭ��
// ���� material_ attrib = y Ϊ�жϱ�־������Ч����Ϊ:power_point
// ��Ч������ 75

void create()
{
	set_name(HIW "���˿" NOR, ({"tiancan si", "su"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��������³���˿���ǳ������ԡ�\n" NOR);
		set("unit", "��");
		set("material_attrib", "y");
		set("power_point", 75);
		set("value", 20000);
	}
}
