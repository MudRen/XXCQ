// dhjiudai.c  �񻨾ƴ� by load

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(CYN"�񻨾ƴ�"NOR, ({"jiudai", "dai"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������ȥ�൱�߹�ĵ񻨾ƴ���һ���Ǹ��˲��õġ�\n");
		set("unit", "��");
		set("value", 120);
		set("max_liquid", 20);
         set("container",1);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "��Ҷ��",
		"remaining": 20,
		"drunk_apply": 20,
	]));
}

