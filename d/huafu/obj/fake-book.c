// fake_book.c

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("һҶ�ؼ�", ({ "yiye book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"������д��:һҶ�ؼ���\n");
		set("value", 0);
		set("material", "paper");
		}
}

void init()
{
	add_action("do_study","study");
	add_action("do_study","du");
	
}

int do_study(string arg)
{
	object me;
	me=this_player();
	if (!arg="yiye book" || !arg="book")
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$N�߿�������ָպ����ĭ��һҳһҳ�ط�����һҶ�ؼ���\n",me);
	me->start_busy(5);
	remove_call_out("is_poisoned");
	call_out("is_poisoned", 10);
	return 1;
}

int is_poisoned()
{
	object me=this_player();
	
      me->apply_condition("yangdu_poison",(int) me->query("kar")+ random(30));
	
	message("channel:chat",
			HIY"���԰ס�"HIC"����ͻȻ����һ������������ץ��ѽ������͵�����ң�\n"NOR,users());
	remove_call_out("mi_tan");
	call_out("mi_tan",10);
	return 1;
}

int mi_tan()
{
	message("channel:chat",
			HIY"��������"HIC"������������ںͻ��ݷ����澭�������ݷ����ϵ�����ȥ�鿴��\n"NOR,users());
	call_out("zi_bai",10);
	return 1;
}

int zi_bai()
{
	message("channel:chat",
			HIY"��������"HIC"���ݷ�������µ�˵�����Һ�ֻ͵ȥ���Ǳ��ٵġ������������Ǳ�������Ϳ���¼ҵ�"HIR"����\n"HIC"            ��λ���Ͼ������ڿ��¶����ˣ���æ���ҽ�ҩ�ء�\n"NOR,users());
	call_out("zi_bai2",10);
	return 1;
}

int zi_bai2()
{
	message("channel:chat",
			HIY"��������"HIC"���ݷ����ٺ١���Ц�˼�����\n"NOR,users());
	call_out("zi_bai3",10);
	return 1;
}

int zi_bai3()
{
	object me=this_player();
	object ob;
	ob=this_object();
	message("channel:chat",
			HIY"�����Ͼ��ӡ�"HIB+ me->query("name") +HIC"�������ش��һ�������°�ĭ�����˹�ȥ��\n"NOR,users());
	destruct(ob);
	return 1;
}

