// poison_dust.c

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{

	set_name(WHT"���ɢ"NOR, ({ "ruangu san", "san" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ����ɫ��ҩ�ۡ�\n" );
		set("unit", "��");
		set("base_value", 700);
       set("base_unit", "��");
		set("base_weight", 30);
       set("yaowang", 1);
       set("nopawn", 1);
       set("no_pawn", 1);
       set("value", 0);
	}
	set_amount(1);
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
	add_action("do_pour", "pour");
}

int do_pour(string arg)
{
	string me, what;
	object ob;
	function f;

	if( !arg
	||	sscanf(arg, "%s in %s", me, what)!=2
	||	!id(me) )
		return notify_fail("�����ʽ: pour <ҩ> in <��Ʒ>��\n");

	ob = present(what, this_player());
	if( !ob )
		return notify_fail("������û��" + what + "����������\n");
	if( !ob->query("liquid/remaining") )
		return notify_fail(ob->name() + "��ʲôҲû�У���װЩ��ˮ�����ܻ�ҩ��\n");
	f = (: call_other, __FILE__, "drink_drug" :);
	ob->set("liquid/drink_func", bind(f, ob));
	ob->add("liquid/slumber_effect", 100);
	message_vision("$N��һЩ" + name() + "����" + ob->name() 
		+ "ҡ���˼��¡�\n", this_player());
	add_amount(-1);
	return 1;
}

int drink_drug(object ob)
{
	this_player()->apply_condition("slumber_drug",
		(int)this_player()->query_condition("slumber_drug") 
		+ (int)ob->query("liquid/slumber_effect") );
	return 0;
}
