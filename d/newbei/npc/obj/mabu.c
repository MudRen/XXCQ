// bandage.c

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("Ĩ��", ({ "mabu" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", "����һ�鲼ͷ����֪�Ǵ���˺�����ġ�\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
	}
  	init_staff(5);
        setup();
}