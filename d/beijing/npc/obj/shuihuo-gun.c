// shuihuogun.c ˮ���
//ժ�ԡ�����һ�������ٲ�ñ���

#include <weapon.h>
inherit CLUB;

#include <ansi.h>

void create()
{
	set_name(HIR"ˮ���"NOR, ({ "shuihuo gun", "gun", "club" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ͨ��ĳ�����Ѳ����������ץ�ˡ�\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N����һ��$n���������С�\n");
		set("unwield_msg", "$N�����е�$n˳������\n");
	}
	init_club(25);
	setup();
}
