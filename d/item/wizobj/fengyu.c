// fengyu.c  �����ë  ����ԭ�ϣ�ֻ�ܱ� wizard ʹ��
// Written by Doing Lu 1998/11/3

inherit ITEM;

#include <ansi.h>

// ������������ʱ��Ҫ��һ��ԭ��
// ���� material_ attrib = x Ϊ�жϱ�־������Ч����Ϊ:power_point
// �����ë����Ч������ 1000

void create()
{
	set_name(HIY "�����ë" NOR, ({"fenghuang yumao", "yumao", "leaf", "fengyu"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����ɫ�ķ����ë����ҫ������Ĺ�â����˵�����������������Ƴ�" HIY "�����񽣡�\n" NOR);
		set("unit", "��");
		set("material_attrib", "x");
		set("power_point", 1000);
		set("value", 10000000);
	}
}
