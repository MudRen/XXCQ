// ���� �ɽ������Ǵ���ĵ��ߴ���
// Written by Doing Lu 1998/11/2

inherit ITEM;

// �������ɵ���ʱ�����ݣ�ֻ��һ��������Ԥ���趨
// �����������ڴ�����������ɵ���ʱ���趨
// ���ɵ��ߺ����object��destruct
// �������ǵ��ߴ����ñ�־�� item_origin ����

void create()
{
	set_name("����", ({"jian pi", "pi"}));	// �ڳ������޶�
	set_weight(100);			// �ڳ������趨
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���Ǹɽ��ĵ��Ӵ���Ĺ�����\n");
		set("unit", "��");
		set("no_sell", 1);
                set("no_pawn", 1);
		set("nopawn", 1);
		set("item_origin", 1);		// ������Ա������ǵ��ߴ���
		set("item_type", "weapon");	// ������Ա�������������
		set("type", "club");		// ������Ա������ǹ���/�� include ���ļ�
		set("inherit", "CLUB");		// ������Ա�����Ӧ�ü̳� CLUB
		set("ctype", "��");		// club ������

		set("material1", "");		// �ڳ������趨
		set("mat_attr1", 0);		// �ڳ������趨
		set("material2", "");		// �ڳ������趨
		set("mat_attr2", 0);		// �ڳ������趨
		set("value", 0);		// �ڳ������趨
		set("wield_msg", "");		// �ڳ������趨
		set("unwield_msg", "");		// �ڳ������趨
		set("point", 0);		// �ڳ������趨
		set("owner", "");		// �ڳ������趨
		set("ownerid", "");		// �ڳ������趨
	}
}
