// chiwusha.c  ����ɳ  ��������
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// ������ߴ���ʱ��Ҫ������ߵ��ߵ���Ч����
// ���� material_ attrib = z Ϊ�жϱ�־���䱶������Ϊ:scale
// ���� x2

void create()
{
	set_name(HIR "����ɳ" NOR, ({"chiwu sha", "sha"}));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�ֳ��Ŀ����������������ණ���������������ԡ�\n");
		set("unit", "��");
		set("material_attrib", "z");
		set("scale", 4);
		set("value", 2000);
	}
}
