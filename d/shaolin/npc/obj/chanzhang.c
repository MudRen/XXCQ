// chanzhang.c ����
// by Load

#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(CYN"����"NOR, ({ "chan zhang", "zhang", "staff" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����������������ȣ�Լ��ʮ����Ǽ����ֵ��ر�����\n");
                set("value", 800);
		set("rigidity", 150);
                set("material", "iron");
                set("wield_msg", "$N˫��һ���Ѿ�ʰ��һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n˳�����\n");
        }
        init_staff(25);
        setup();
}