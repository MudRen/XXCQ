// ɨ�� �ش���������ĵ��ߡ�
// By ɽèAdx 16:53 99-10-25

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("ɨ��", ({ "saoba" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����Ƶ�ɨ�ѡ�\n");
                set("value", 1);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
	}
        init_hammer(5);
	setup();
}

void init()
{
           add_action("do_job","dasao");
}

int do_job(string arg)
{
        object *inv;
        object me;
         int i, jing;

	me = this_player();
	jing = ( random(me->query("str"))/3 );
	inv = all_inventory(me);
	if (jing <= 0)
		jing = 5;

	if (me->query("jingli")<=jing) {
		message_vision ("$N̫���ˣ�������Ϣһ�£����ܼ����������\n", me );
        	return 1;
	}

	if (!me->query_temp("renwu_name")) {
		message_vision ("$N����ɨ�ѣ�������һ������Ȥ��\n", me);
        	return 1;
	}

	if (me->query_temp("renwu_wancheng") >= 100)
	{
		me->set_temp("renwu_wancheng",100);   //��ʾ�������
		return notify_fail ("����������񣬻�ȥ�����ɣ�\n");
	}

	if(environment(me)->query("short")!=me->query_temp("renwu_name"))
		return notify_fail ("���������������ɨ����\n");

	//�ж��Ƿ�wield�˹���
	if( (string)(inv[i]->query("id"))=="saoba" && 
		(int) inv[i]->query("equipped") ) {

		me->add_temp("renwu_wancheng",jing);
		me->add("jingli", -jing);
		me->improve_skill("healing", (jing/3));
		message_vision ("$N����ɨ�ѣ�һ��ɨ�ŵذ壬һ������ҽʦ�ڸ��˰�����\n", me);
	}
	else {
		return notify_fail ("�������ôɨ�أ�����ץ��\n");
		}
        return 1;
}
