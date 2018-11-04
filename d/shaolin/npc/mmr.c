// sample master.c code
// xiake island master.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void away();

void create()
{
	set_name("������", ({"mengmian ren", "mengmian", "ren"}));
	set("gender", "����");
	set("age", 26);
	set("long", 
		"һ��������ĺ����ˣ�һ�������������ӡ�\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("bac", 20);

	setup();

	set("chat_chance", 20);
	set("chat_msg", ({
		(: away :),
	}));
}

void away()
{
	if( living(this_object()) )
	{
		message_vision(HIW"�����������һ�������������ֲ�����ˡ�Ȼ��Ҵҵ��뿪�ˡ�\n"NOR, this_object());
		destruct(this_object());
	}
	return;
}

void unconcious()
{
	message_vision(HIC"\n������Ծ��սȦ��һ��ȭ���������ֹ��������鴫���ٻᡣ��˵�ռ���ææ�뿪�ˡ�\n\n"NOR,this_object());
	destruct(this_object());
	return;
}