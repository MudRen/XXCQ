// gongdanmu.c  ����ĸ  ��������
// Written by Doing Lu 1998/11/9

inherit ITEM;

#include <ansi.h>

// ������ߴ���ʱ��Ҫ������ߵ��ߵ���Ч����
// ���� material_ attrib = z Ϊ�жϱ�־���䱶������Ϊ:scale
// ���� x2.5

void create()
{
	set_name(HIY "����ĸ" NOR, ({"gongdan mu", "mu", "dan"}));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����ˮ���ͽ�Ļ�����������ණ������������ǿ�ȡ�\n");
		set("unit", "��");
		set("material_attrib", "z");
		set("scale", 5);
		set("value", 10000);
	}
}
