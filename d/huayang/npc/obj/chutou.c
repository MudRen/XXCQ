// bigaxe.c

#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
	set_name(YEL"��ͷ"NOR, ({ "chu tou", "chu", "tou" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ľ����ͷ�ĳ�ͷ������ȥ�ܽ�ʵ��\n");
		set("value", 1000);
		set("distance", 3);
		set("wield_msg", "$N�ó�һ��$n��һ��û���ȣ���������Լ����ϡ�\n");
		set("unwield_msg", "$N�������е�$n�����������ز��˲�����\n");
	}
	init_axe(20);
	setup();
}
