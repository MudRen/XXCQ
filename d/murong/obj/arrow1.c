// arrow.c ��
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name(HIC"�����"NOR, ({ "arrow" }));
        set_weight(2000);		                      	
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY"����һ���þ������ļ�������β�����ż�ֻ��ɫ��ë��\n"NOR);
		set("value", 10000);
                set("material", "iron");            
		set("base_value", 200);
                set("base_unit", "֧");
                set("base_weight", 50);	                
	}                                                       
	set_amount(40);
        setup();
}