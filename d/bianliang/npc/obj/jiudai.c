// wineskin.c  �ƴ�

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(YEL"ţƤ�ƴ�"NOR, ({"jiudai", "dai"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�ƵĴ�ƴ���Ҳ��������װˮ��\n");
		set("unit", "��");
		set("value", 300);
		set("max_liquid", 15);
         set("container",1);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "�յ���",
		"remaining": 15,
		"drunk_apply": 20,
	]));
}
