// arrow.c
#include <weapon.h>
#include <ansi.h>
inherit THROWING;
void create()
{
        set_name("��ڤ����", ({ "youming zhen", "zhen" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("value", 0);
                set("base_unit", "֧");
                set("base_weight", 300);
                set("base_value", 0);
                set("nopawn", 1);
                set("material", "iron");
                set("long", "�������͸����ɫ����Ȼ�о綾��\n");
                set("wield_msg", HIC"$NѸ�ٵشӴ��г��һ֧��ڤ���룡\n"NOR);
                set("unwield_msg",HIC"$N���������ڤ����Żش��С�\n"NOR);
        }
       set_amount(20);
        init_throwing(25);
        setup();
}

