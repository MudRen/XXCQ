// ���� ҩ��ׯ��ҩ�ĵ��ߡ�
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(BLU"����"NOR, ({"xiong zhang"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "����һֻ�����ơ�\n");
		set("yaowang", 1);
		set("value", 1000);
		set("weight", 1000);
	}
	setup();
}
