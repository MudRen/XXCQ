// tiebeixin.c ������
// by Load

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(WHT"������"NOR, ({ "tie beixin", "beixin" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����������Ļ��ı��ģ�����ǰ�ĺ󱳲��������˺���\n");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 15);
	}
	setup();
}
