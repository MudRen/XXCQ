// huangjiasha.c ��������
// by Load

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(YEL"�Ʋ�����"NOR, ({ "jia sha", "sha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ���Ʋ���͵����ģ��������µͱ�ɮ�˴����·���");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}