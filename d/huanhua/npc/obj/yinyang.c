// gangdao.c

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;

void create()
{
	set_name(HIB"��"HIW"��"NOR+CYN"��"NOR, ({ "yinyang jian","yinyang", "jian","sword" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
�˽�����ʱ����âͨ�ף�����ʱ������ȫ�ڣ�������ֻ��һ�����ֽ���
���С���������������������������ë�����Գ��־��ɷ��ӣ���ʹ���
��������һ�����������������⡣
LONG);
		set("value", 20000);
		set("no_break", 1);
		set("endure", 150);
		set("material", "steel");
		set("wield_msg", CYN"$N������н�������"HIB"���"NOR+CYN"�Ľ�������������֮�¾�Ȼ���ͨ��"HIW"ɷ�ס�\n"NOR);
		set("unwield_msg", "$N�����ս�����һ���֣�"HIW"ɷ��"NOR"�Ľ������ֹ���"HIB"��ڡ�\n"NOR);
	}
	init_sword(60);
	setup();
}