// gangdao.c



#include <weapon.h>

#include <ansi.h>

inherit F_UNIQUE;

inherit SWORD;



void create()

{

        set_name(HIC"ͭȸ"NOR, ({ "tongque","jian","sword" }));

        set_weight(5000);

        if (clonep())

                set_default_object(__FILE__);

        else {

                set("unit", "��");

                set("long", @LONG

��������𽭺�,��������֮һ��ͭȸ��,�˽�ϸС,ͨ���ɫ,���ּ�

��,��������,��̫������Ϊһ��,ԭΪ"����˫����"����,�󱻲ؽ�

���˹ȷ�������.

LONG);

                set("value", 50000);

                set("no_break", 1);

                set("endure", 150);

                set("material", "steel");

                set("wield_msg", HIY"$N����������аγ�����"HIC"ͭȸ"NOR+HIY"��ֻ������տ��,����͸����ˮ��һ��,"NOR+HIC"ˮ����Ȼ,�������ˡ�\n"NOR);

                set("unwield_msg", HIY"$N����Ľ����е�"NOR+HIC"ͭȸ"NOR+HIY"���뽣�ʣ�ˮ��էȻ��ʧ,���Ǻ���ȴ��δ��ɢ��\n");

        }

        init_sword(50);

        setup();

}


