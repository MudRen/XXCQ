// chanhunsi.c  ����˿  ����ԭ��
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// ������ߴ���ʱ��Ҫ��һ��ԭ��
// ���� material_ attrib = y Ϊ�жϱ�־������Ч����Ϊ:power_point
// ��Ч������ 30

void create()
{
	set_name(HIG "����˿" NOR, ({"chanhun si", "si"}));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����ѩɽ����֯��˿���ǳ������ԣ������������������ס�\n" NOR);
		set("unit", "��");
		set("material_attrib", "y");
		set("power_point", 30);
		set("value", 10000);
	}
}
