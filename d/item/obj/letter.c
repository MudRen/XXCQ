// �ż� Īа���������ǵ��ż�
// Written by Doing Lu 1998/11/2

inherit ITEM;

void create()
{
	set_name("�ż�", ({"item permit", "letter"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����Īа������д���ţ�����Դ�����ȥ�ҵ��Ӵ�����ߡ�\n");
		set("unit", "��");
		set("value", 0);
		set("wield_msg", "");
		set("unwield_msg", "");
	}
}
