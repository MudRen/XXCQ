// ���� 
// ������������أ������ܻ߷����������˽�����ʲô�ġ�
// jackyboy@cuterabbit Studio 1999/6/6
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����", ({ "yu zu","yu","zu" }) );
	set("long",
		"������������Ź�ɱ����\n");
	set("age",34);
	set("attitude", "peaceful");
	setup();
set("combat_exp",200);
	carry_object(NCLOTH)->wear();
}
