// arrow.c
#include <weapon.h>
#include <ansi.h>
inherit ARROW;
void create()
{
        set_name(HIC"���̼�"NOR, ({ "youren jian", "arrow" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200000);
                set("weight", 6000);
               set("no_break",1);
               set("endure",150);
                set("material", "iron");
                set("long", "���̼�����������Ƶ����͡�\n");
                set("wield_msg", HIC"$N�Ӿ���ȡ��һ�����̼���\n"NOR);
                set("unwield_msg",HIC"$N�����̼����ھ��䡣\n"NOR);
        }
         init_arrow(50);
        setup();
}

