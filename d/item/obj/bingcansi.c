// bingcansi.c  ����˿  ����ԭ��
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// ������ߴ���ʱ��Ҫ��һ��ԭ��
// ���� material_ attrib = y Ϊ�жϱ�־������Ч����Ϊ:power_point
// ��Ч������ 100

void create()
{
	set_name(HIG "����˿" NOR, ({"bingcan si", "si"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�ּ����ı����³���˿���������ԣ��������ָ���Ҳ�����ϡ�\n" NOR);
		set("unit", "��");
		set("material_attrib", "y");
		set("power_point", 100);
		set("value", 40000);
	}
}
