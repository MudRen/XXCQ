// ɨ�� �ش���������ĵ��ߡ�
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("ˮͰ", ({ "tong" }));
        set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ľ�Ƶ�ˮͰ��������ˮ(dashui)����(jiaodi)��\n");
		set("yaowang", 1);
		set("value", 1);
		set("weight", 1000);
	}
}

void init()
{
           add_action("do_dashui","dashui");
           add_action("do_jiaodi","jiaodi");
}

int do_dashui(string arg)
{
	object me=this_player();
	object obj=this_object();

	if (me->query_temp("renwu_wancheng") >= 100)
	{
		me->set_temp("renwu_wancheng",100);   //��ʾ�������
		return notify_fail ("����������񣬻�ȥ�����ɣ�\n");
	}

	if (obj->query("renwu_dashui") )
		return notify_fail ("�Ѿ�����ˮ�ˣ�\n");

	if(!environment(me)->query("resource/water") )
		return notify_fail ("����û��ˮ��\n");

	obj->set("renwu_dashui",1);
	message_vision ("$N����ˮͰ������һͰ��ˮ��\n", me);
        return 1;

}

int do_jiaodi(string arg)
{
        object *inv;
        object me;
        int jing;

	me = this_player();
	jing = ( random(me->query("str"))/3 );
	inv = all_inventory(me);
	if (jing <= 0)
		jing = 5;

	if(environment(me)->query("short")!="���" )
		return notify_fail ("��������������ｽ�ذɣ�\n");

	if (me->query("jingli")<=jing) {
		message_vision ("$N̫���ˣ�������Ϣһ�£����ܼ����������\n", me );
        	return 1;
	}

	if (!me->query_temp("renwu_name1")) {
		message_vision ("$N����ˮͰ�������Լ�һ����ɵ��\n", me);
        	return 1;
	}

	if (me->query_temp("renwu_wancheng") >= 100) {
		me->set_temp("renwu_wancheng",100);   //��ʾ�������
		return notify_fail ("����������񣬻�ȥ�����ɣ�\n");
	}

	if (!this_object()->query("renwu_dashui") )
		return notify_fail ("ˮͰ�ǿյģ���ô���أ�\n");

	this_object()->delete("renwu_dashui");
	me->add_temp("renwu_wancheng",jing);
	me->add("jingli", -jing);
	me->improve_skill("healing", (jing/2));
	message_vision ("$N����ˮͰ��Ͱ�е�ˮ��������У�\n", me);
        return 1;
}
