// suijiasha.c �Ҳ��������
// by Load

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(WHT"�Ҳ��������"NOR, ({ "jia sha", "cloth", "sha" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ����ɫ�������Ƶĳ������ģ�������һ��ɮ�˶����������ġ�\n");
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 4);
        }
        setup();
}