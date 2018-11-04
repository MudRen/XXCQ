// xian. ���ϰ�

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���ϰ�", ({ "hu laoban", "hu" }));
	set("title", "����¥�ϰ�");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 45);
	set("long", "���ϰ��Ǹ����ú������Ƶ������ˣ���Ӫ����¥���ж�ʮ���ꡣ\n");
	set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	setup();
        add_money("gold", 1);
	carry_object("clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_invite", "yaoqing");
        add_action("do_jieshu", "jieshu");
        add_action("do_answer", "answer");
}

int do_invite(string arg)
{
	object me, ob;
	me = this_player();

        if( !me->query_temp("marks/����") ) return 0;

	if( !arg ) return notify_fail("ָ���ʽ��yaoqing <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob) return notify_fail("����û����ˡ�\n");

	if (ob==me) return notify_fail("�����Լ������ðɣ�\n");

	if(ob->query_temp("marks/����"))
		return notify_fail("���Ѿ��������ˣ�\n");

	ob->set_temp("marks/����",1);
	write(HIG "������"+ob->name(1)+"�μ�������������¥����ᡣ\n"NOR);
	tell_object(ob, sprintf(BLINK HIG"%s������μ�����������¥�����"+
		me->query_temp("marks/����")+"��ᡣ\n"NOR, me->name(1)));
	return 1;
}

int do_answer()
{
	object me,item;
	string msg;
        me = this_player();
	msg = me->query("name")+"����������¥�ٰ����"+me->query_temp("marks/����")+"��Ὺʼ�ˣ�\n";

        if(me->query_temp("marks/����")) {
		if( present("table", (environment(me))) ) {
			command("say ���ھ�ϯ���ڽ��������Ե�һ�£�");
			return 1; }
        message("channel:chat",BLINK HIG+"��ͨ�桿"+msg+NOR, users() );
        command("say �ðɣ����ڿ�ϯ��ף��ҳԸ����Ը��ã�һ���ݲŵù飡");
        command("haha ");
        command("say С�����ϲˣ�");
        message_vision("��С����һ����Ͷ����������ڵ�ɽ�亣ζ�ϵ���ŵ���Բ��(table)�ϡ�\n",me);
	me->set_temp("marks/��ʼ",1);
	item = new(__DIR__"table");
        item->move(environment(me));
        return 1;
	}
        else return 0;
}       

int do_jieshu()
{
	object me;
	string msg;
	me = this_player();
	msg = me->query("name")+"����������¥�ٰ����"+me->query_temp("marks/����")+"�������ˣ�\n";

	if(!me->query_temp("marks/��ʼ")) return 0;

        if(me->query_temp("marks/����")) {
	message("channel:chat",BLINK HIG+"��ͨ�桿"+msg+NOR, users() );
		command("say �ðɣ�����������ӭ�´�������ˣ�");
		command("ok ");
		command("say С������ʰһ�£�");
		message_vision("��С�����˹����Ѿ�ϯ��ʰ�ˡ�\n",me);
		me->delete_temp("marks/����");
		me->delete_temp("marks/��");
		me->delete_temp("marks/����");
		me->delete_temp("marks/����");
		me->delete_temp("marks/��ʼ");
		destruct( present("table", (environment(me))) );
		return 1;
	}
        else return 0;
}       
