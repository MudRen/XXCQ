// changqiang.c

#include <weapon.h>

inherit SPEAR;

void create()
{
	set_name("���ǹ", ({ "diangang qiang","qiang" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "steel");
		set("distance", 4);
		set("long", "һ�˾��ִ��Ƶ��������Եĵ��ǹ��\n");
		set("wield_msg", "$N����һ��$n��˳�ֶ��˸�ǹ����\n");
		set("unwield_msg", "$N����һ������$n��غ�����\n");
	}
	init_spear(30);
	setup();
}
