// jinjia.c ���

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
        set_name(HIR"�������"NOR, ({"hongjin pifeng","hongjin", "pifeng"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("unit", "��");
		set("long", "һ���ϵȺ�����Ƶ����磬���к��ա���ѻ������������Ķ�������\n");
                set("material", "cloth");
                set("value", 5000);
		set("wear_msg","��ৡ�һ���죬$Nһ�ӱۣ���"HIR"�������"NOR"�������ϣ�������ʱ�������࣡\n");
                set("armor_prop/armor", 5);
		set("armor_prop/dodge", 10);
        }
        setup();
}


