//By ɽèadx @ CuteRabbit 20:50 99-6-17

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIM"�컯��"NOR, ({ "zaohua dan", "dan" }));
        set("unit", "ö");
	set("long", "����һö�ۺ�ɫ�ĵ�ҩ����˵����������Ч��\n");
	set_weight(1000);
     set("yaowang", 1);
	set("nopawn", 1);
	set("no_pawn", 1);
	set("value", 0);
        setup();
}

void init()
{
	object me, ob;
	int obj;

	me = this_player();
	ob = this_object();
	obj = (int)me->query_skill("healing");

	if( me->query_temp("liandan")==1
		&& ob->query("value")==0 )
	{
		if(obj<60) {
			ob->set("value", (random(2000)+2000)); }
		if(obj>=60 && obj<80) {
			ob->set("value", (random(4000)+4000)); }
		if(obj>=80 && obj<100) {
			ob->set("value", (random(8000)+7000)); }
		if(obj>=100 && obj<150) {
			ob->set("value", (random(15000)+15000)); }
		if(obj>=200) {
			ob->set("value", (random(20000)+30000));
			}
	}
        add_action("do_eat", "eat");
        add_action("do_eat", "chi");
}

int do_eat(string arg)
{
	object me = this_player();
	int i = this_object()->query("value")/10;

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");

	if( me->query("eff_qi") == me->query("max_qi")
		&& me->query("eff_jingli") ==  me->query("max_jingli")
		&& me->query("qi") ==  me->query("max_qi")
		&& me->query("jingli") ==  me->query("max_jingli") )
		return notify_fail("���ƺ�����Ҫ�����컯����\n");

	if( me->query("eff_qi")+i >= me->query("max_qi") ) {
		me->set("eff_qi", me->query("max_qi"));
	} else { me->set("eff_qi", (me->query("eff_qi")+i) );}

	if( me->query("qi")+i >= me->query("max_qi") ) {
		me->set("qi", me->query("max_qi"));
	} else { me->set("qi", (me->query("qi")+i) );}

	if( me->query("eff_jingli")+i >= me->query("max_jingli") ) {
		me->set("eff_jingli", me->query("max_jingli"));
	} else { me->set("eff_jingli", (me->query("eff_jingli")+i) );}

	if( me->query("jingli")+i >= me->query("max_jingli") ) {
		me->set("jingli", me->query("max_jingli"));
	} else { me->set("jingli", (me->query("jingli")+i) );}

	message_vision(HIM"$N��һ�ھͰ��컯��������ȥ����ɫ�������ö��ˡ�\n"NOR, me);
	destruct(this_object());

	return 1;
}
