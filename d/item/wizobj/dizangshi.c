// dizhangshi.c  �ز�֮ʯ  ����ԭ�ϣ�ֻ�ܱ� wizard ʹ��
// Written by Doing Lu 1998/11/3

inherit ITEM;

#include <ansi.h>

// ������������ʱ��Ҫ��һ��ԭ��
// ���� material_ attrib = x Ϊ�жϱ�־������Ч����Ϊ:power_point
// �ز�֮ʯ����Ч������ 1000

void create()
{
	set_name(YEL "�ز�֮ʯ" NOR, ({"dizang zhishi", "shi"}));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����Եظ���ʯͷ���������ģ���ҫ�Ź���Ĺ�â����˵�ز����������Ƴ�" YEL "ڤ��ħ�ȡ�\n" NOR);
		set("unit", "��");
		set("material_attrib", "x");
		set("power_point", 1000);
		set("value", 10000000);
	}
}
