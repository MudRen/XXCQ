// yitian-jian ���콣

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(YEL"��罣"NOR,({ "jinhong jian","sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
                set("material", "steel");
                set("long", "����һ���ĳ������Ľ��ɫ��������������������������罣���š�\n");
                set("wield_msg", HIY "ֻ����ৡ���һ�������������һ����磬$n�ڿ��з�������$N���С�\n" NOR);
                set("unwield_msg", HIY "��罣��ৡ��ط����˽��ʡ�\n" NOR);
                }
        init_sword(110);
        setup();
}
