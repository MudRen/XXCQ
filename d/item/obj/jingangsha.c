// jingangsha.c  ���ɰ  ��������
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// ������ߴ���ʱ��Ҫ������ߵ��ߵ���Ч����
// ���� material_ attrib = z Ϊ�жϱ�־���䱶������Ϊ:scale
// ���� x3

void create()
{
	set_name(HIC "���ɰ" NOR, ({"jingang sha", "sha"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ����ֵĿ�ʯ����˵��������ණ����������������ǿ�ȡ�\n");
		set("unit", "��");
		set("material_attrib", "z");
		set("scale", 6);
		set("value", 25000);
	}
}
