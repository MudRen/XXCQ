// sickle.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("����", ({ "lian dao", "dao", "blade", "lian" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 200);
		set("distance", 1);
		set("material", "iron");
		set("long", "����һ��ũ���г�����������\n");
		set("wield_msg", "$N���һ��$n�������У������ϻ����ŵ��ݡ�\n");
		set("unwield_msg", "$N�����е�$n��������\n");
	}
	init_blade(5);
	setup();
}
