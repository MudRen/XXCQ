// jixuechao.c  ��Ѫ��  ��������
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// ������ߴ���ʱ��Ҫ������ߵ��ߵ���Ч����
// ���� material_ attrib = z Ϊ�жϱ�־���䱶������Ϊ:scale
// ���� x1.5

void create()
{
	set_name(RED "��Ѫ��" NOR, ({"jixue cao", "cao"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����������ѩɽ�ϵ�һ�ֲݣ��������溬�п������ǰ���ɫ�ġ�\n");
		set("unit", "��");
		set("material_attrib", "z");
		set("scale", 3);
		set("value", 1000);
	}
}
