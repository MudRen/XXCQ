// longlin.c  ��������  ����ԭ�ϣ�ֻ�ܱ� wizard ʹ��
// Written by Doing Lu 1998/11/3

inherit ITEM;

#include <ansi.h>

// ������ߴ���ʱ��Ҫ��һ��ԭ��
// ���� material_ attrib = y Ϊ�жϱ�־������Ч����Ϊ:power_point
// �������۵���Ч������ 1000

void create()
{
	set_name(HIC "��������" NOR, ({"beihai longlin", "longlin", "lin"}));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������߸�ֺ�ʱ�ӱ����������ϰ��µ�һƬ�ۼף���˵�������������������ɹ�" HIC "���۱��ס�\n" NOR);
		set("unit", "Ƭ");
		set("material_attrib", "y");
		set("power_point", 1000);
		set("value", 10000000);
	}
}
