// gangzhang.c ����

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("ʯ��", ({ "shichu" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ص�ʯ�ƣ�ҩ��һ�㶼������ҩ��\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
	}
        init_hammer(5);
	setup();
}
