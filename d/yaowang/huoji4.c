// NPC ���
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit NPC;
//inherit F_DEALER;

int ask_me();
void create()
{
	set_name("���", ({ "huo ji", "huo", "ji" }) );
	set("title", HIB"ҩ����"NOR+YEL"����"NOR);
	set("gender", "����" );
	set("age", 22);
	set("combat_exp", 100);
	set("attitude", "friendly");

        set("inquiry", ([
		"����" : (: ask_me :),
		"��ҩ" : (: ask_me :),
        ]));

	set("foor_count", 35);
	setup();
        add_money("silver", 5);
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	object ob, me;
	me = this_player();

	if( me->query("party/party_name")!=HIB"ҩ����"NOR ) {
		command("say �㲻������Ļ�ƣ����ֻ���ô��������أ�\n");
		return 1; }

	if (query("foor_count") < 1) {
		command("��Ǹ�������ò���ʱ�������Ѿ�û�в����ˡ�\n");
		return 1; }

	if (  present("cao zi", me) ) {
		command("���������ϲ���������������Ҫ�ˣ���̰�ģ�\n");
		return 1; }

	add("foor_count", -1);
	ob = new(__DIR__"obj/caozi");
	ob->move(me);
	message_vision(YEL"��Ƹ���$Nһ�Ų��ѡ�\n"NOR, me);
	return 1;
}
