// tongzi3.c ����ͯ�� -- ��
// Written by Doing Lu 1998/11/17

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({ "tongzi"}));
	set("title", "����ͯ��");
	set("nickname", HIY "����������" NOR);
	set("gender", "����");
	set("long", "����³����������ͯ��֮һ����³�ཨ���ĺð���\n");
	set("age", 23);

	set_skill("literate", 100);
	set_skill("drawing", 100);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
