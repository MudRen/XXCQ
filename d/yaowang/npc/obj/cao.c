// �ݲ� ҩ��ׯ��ҩ�ĵ��ߡ�
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"�ݲ�"NOR, ({"ku cao", "kucao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ÿ�ή�Ĳ�ҩ���Ѿ�û���ˡ�\n");
		set("dig", 1);
		set("value", 0);
		set("weight", 100);
	}
	setup();
}
