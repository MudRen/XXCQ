#include <ansi.h>
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name(HIW"��ü��"NOR, ({ "qimei gun", "gun" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ľ���������ٿ���ü�����غ��ˣ��ɹ�����Ƭ���ˡ�\n");
                set("value", 200);
		set("rigidity", 120);
		set("rendu", 140);
                set("material", "wood");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_club(10);
        setup();
}