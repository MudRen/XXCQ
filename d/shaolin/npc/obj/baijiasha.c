// baijiasha.c �ײ��ڱ�����
// by Load

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"�ײ�"HIB"�ڱ�"HIW"����"NOR, ({ "jia sha", "sha", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "����һ������ȥ����ͨͨ�İײ����ģ���ʵ�����ޱȣ�ֻ�����ֳ��ϲſɴ��š�\n");
                set("material", "cloth");
		set("value", 10000);
                set("armor_prop/armor", 50);
        }
        setup();
}

