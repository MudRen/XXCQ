// gangdao.c



#include <weapon.h>

#include <ansi.h>

inherit F_UNIQUE;

inherit SWORD;



void create()

{

        set_name(HIR"̫��"NOR, ({ "taier","jian","sword" }));

        set_weight(5000);

        if (clonep())

                set_default_object(__FILE__);

        else {

                set("unit", "��");

                set("long", @LONG

��������𽭺�,��������֮һ��̫����,�˽�����ϸС,ͨ����,��

�ּ���,��ͭȸ����Ϊһ��,ԭΪ"����˫����"����,�󱻲ؽ����˹ȷ�

������.

LONG);

                set("value", 50000);

                set("no_break", 1);

                set("endure", 150);

                set("material", "steel");

                set("wield_msg", CYN"$N����������аγ�����"HIR"̫��"NOR+CYN"��ֻ������տ��,����һ��ȼ�յĻ���,"NOR+HIR"����ȼ��,��˸���ѡ�\n"NOR);

                set("unwield_msg", CYN"$N����Ľ����е�"HIR"̫��"NOR+CYN"���뽣�ʣ����էȻ��ʧ,��������ȴ���ɱ��ˡ�\n");

        }

        init_sword(50);

        setup();

}


