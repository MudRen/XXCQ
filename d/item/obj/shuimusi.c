// shuimusi.c  ˮĸ˿  ����ԭ��
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// ������ߴ���ʱ��Ҫ��һ��ԭ��
// ���� material_ attrib = y Ϊ�жϱ�־������Ч����Ϊ:power_point
// ��Ч������ 50

void create()
{
	set_name(HIW "ˮĸ˿" NOR, ({"shuimu si", "si"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�����ɶ���һ��ˮĸ���ɵ�˿���������ԡ�\n" NOR);
		set("unit", "��");
		set("material_attrib", "y");
		set("power_point", 50);
		set("value", 18000);
	}
}
