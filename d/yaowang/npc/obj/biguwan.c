//By ɽèadx @ CuteRabbit 20:50 99-6-17

#include <ansi.h>
inherit ITEM;

void create()
{
     set_name(HIG"�ٹ���"NOR, ({ "bigu wan", "wan" }));
	set("unit", "��");
	set("long", "һ�ű���ɫ��ҩ�裬��\n");
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

	if( me->query("food") >= ( (me->query("str")*10)+100)
		&& me->query("water") >= ( (me->query("str")*10)+100) )
		return notify_fail("���ƺ���������\n");

	me->add("food", i);
	me->add("water", i);
	me->add("neili", i);
       message_vision(HIG"$N����һ�űٹ��裬�پ�һ������֮���Ӹ�������\n"NOR, me);
	destruct(this_object());
	return 1;
}
