// qilinxue.c  ����֮Ѫ  �������ϣ�ֻ�ܱ� wizard ʹ��
// Written by Doing Lu 1998/11/3

inherit ITEM;

#include <ansi.h>

// ������ߴ���ʱ��Ҫ������ߵ��ߵ���Ч����
// ���� material_ attrib = z Ϊ�жϱ�־���䱶������Ϊ:scale
// ����֮Ѫ���� x10

void create()
{
	set_name(HIG "����֮Ѫ" NOR, ({"qilin zhixue", "xue"}));
	set_weight(5);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ�ε���ɫ������Ѫ����˵̫���Ͼ�������" HIG "�����" NOR "ʱ����һ�ζ��������޼᲻�ݵı��\n");
		set("unit", "��");
		set("material_attrib", "z");
		set("scale", 20);
		set("value", 10000000);
	}
}
