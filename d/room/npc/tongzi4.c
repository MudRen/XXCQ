// tongzi4.c ����ͯ�� -- ˮ
// Written by Doing Lu 1998/11/17

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ˮ��", ({ "tongzi"}));
	set("title", "����ͯ��");
	set("nickname", HIB "�����ɹ�ˮ" NOR);
	set("gender", "Ů��");
	set("long", "����³����������ͯ��֮һ����³�ཨ���ĺð���\n");
	set("age", 21);

	set_skill("literate", 100);
	set_skill("drawing", 100);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
