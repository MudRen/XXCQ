// chahua.c 
#include <ansi.h>      
#include <armor.h>
inherit HEAD;          
string* titles = ({
	HIR"ץ��������"NOR,
	HIY"ʮ��ѧʿ"NOR,
	HIM"���ɹ���"NOR,
	HIW"������"NOR,
});
void create()
{
	set_name(titles[random(sizeof(titles))], ({ "flower" }));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("value", 0);
                set("material", "plant");
                set("long", "����һ��"+titles[random(sizeof(titles))]+"��\n");
                set("wear_msg", "");
                set("unequip_msg", "$Nժ����ǰ��$n��\n");
                set("armor_prop/armor", 0);
        }
           
        setup();
}	

int wear()
{
	object me = environment();
	int ret;

	message_vision("$N�ó�һ��" + this_object()->query("name") + "������ͷ�ϡ�", me);
	if (ret=::wear()) {
		if (me->query("gender") == "����")
			message_vision("��һ�����������ɣ�\n", me);
		else if (me->query("gender") == "Ů��")
			message_vision("��һ�������μ��ޣ�\n", me);
		else
			message_vision("��һ���������ĵļһ\n", me);
	}
	return ret;
}