// NPC ������ ��ϰhealing������
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit NPC;
//inherit F_DEALER;

void create()
{
	set_name("������", ({ "buwawa", "bu", "wawa" }) );
	set("gender", "����" );
	set("age", 22);
	set("combat_exp", 100);
	set("attitude", "friendly");

	setup();
}

void init()
{
	add_action("do_lianxi", "lianxi");
}

int do_lianxi(string arg)
{
	object me;
	int i;
	me=this_player();
	i=(int)me->query_skill("healing",1);

	if(me->query("party/party_name")!=HIB"ҩ����"NOR
         || (int)me->query_skill("healing",1)>=60) {
		return notify_fail("�㲻��ʹ�ò����ޣ�\n");
	}

          if( (int)me->query_skill("healing",1)<40) {
                 return notify_fail("�㲻��ʹ�ò����ޣ�\n");
         }

	if (!id(arg))
		return notify_fail("ָ���ʽ��lianxi <ID> \n");

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("����æ���أ�\n");

        if( me->query("jingli")<=i )
                return notify_fail("��̫���ˣ���Ϣһ����ɣ�\n");

	message_vision ("$N����һ֧���룬�ڲ������������ž���ͼ���Ȼ��ţ�\n", me);
	me->improve_skill("healing", (i/2));
	me->add("jingli", -i);
	me->start_busy(3);

	return 1;
}

