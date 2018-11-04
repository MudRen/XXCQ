// huoji. ҩ�̻��

inherit NPC;

void kai(object me, int a, int b, int c, int vager, object mtype);

void create()
{
	set_name("˾ͽͨ", ({ "situ tong", "situ", "tong"}));
	set("str", 35);
	set("gender", "����");
	set("title", "����ķ��ϰ�");
	set("age", 35);
	set("long", "����һ����������ӵ��������ӣ���Ȼ����������Ц�ݣ�����Ƿ��Ǯ��ʱ�򡭡���\n");
	set("combat_exp", 250);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

        add_action("do_gamble", "gamble");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "˾ͽͨ������Ц�Ķ���˵����λ" + RANK_D->query_respect(ob)
				+ "�������Ѱɣ���Ӯ��\n");
}

int do_gamble(string arg)
{
	int a,b,c;
	int wager;
	string wtype2, wtype0, sb;
	object mtype, me;
	int min, max;
	min = 100;
	max = 100000;

	me = this_player();

	if (!arg || sscanf(arg, "%s %d %s", wtype0, wager, wtype2) !=3)
		return notify_fail("�Ĳ��������ʽ�ǣ�gamble big|small <amount> <type>\n"
		"���磺Ѻʮ�����ӡ��󡱵������ʽΪ��gamble big 10 silver��\n");

	mtype = present(wtype2 + "_money", me);

	if (this_object()->query("doing"))
		return notify_fail("��û�����������������\n");

	if (!mtype)
		return notify_fail("������û�����ֻ��ҡ�\n");

	if ((int)mtype->query_amount() < wager)
		return notify_fail("˾ͽͨ������һ�۵���û��ô��"
		+ mtype->query("name") + "Ҳ��Ѻ����ô����թ�ģ�\n");

	if( wager*(mtype->query("base_value")) < min ||	wager*(mtype->query("base_value")) > max )
		return notify_fail("˾ͽͨ��Ǹ��Ц��Ц��С��ֻ��Ѻһ�����ӵ�ʮ�����ӣ�����������\n");

	if ( (wtype0 != "big") && (wtype0 != "small") )
		return notify_fail("��Ҫ�Ĵ��Ƕ�С?\n");

	a = random(6) + 1;
	b = random(6) + 1;
	c = random(6) + 1;

        if ( ( (a == b) && (b == c) ) ||
             ( (a+b+c) > 10 && (wtype0 == "small") ) ||
             ( (a+b+c) < 11 && (wtype0 == "big") ) )
		me->set_temp("status", 1);

	if (wtype0=="small") sb = "С";
	else sb = "��";

	message_vision("���ã�����������������Ѻ��Ǯ��˾ͽͨͻȻ�е�����" + me->query("name")
		+ chinese_number(wager) + mtype->query("base_unit") + mtype->query("name")
		+ "Ѻ" + sb + "������\n", me);
	message_vision("˾ͽͨ������ҡ�ε���ͲͻȻ����������һ�ۣ���ž����\n", me);
	message_vision("ȫ������ס�˺�����Ψһ��������������������Ͳ�����ص�ײ������\n", me);
	this_object()->set("doing",1);
	call_out("kai", 5, me, a, b, c, wager, mtype);
        return 1;
}

void kai(object me, int a, int b, int c, int wager, object mtype)
{
	string str;

	message_vision("\n����Ͳ�ڽ���û��������˾ͽͨ������һ������������������������Ͳ����������\n", me);

	if ((a == b) && (b == c)) str = "��Сͨɱ";
	else if ((a+b+c) > 10 ) str = "��С���";
	else if ((a+b+c) < 11 ) str = "�Դ���С";

	message_vision("ɨһ�����ӣ�˾ͽͨ����������" + chinese_number(a) + "��" + chinese_number(b) + "��" + chinese_number(c) + "��" + str + "����\n", me);

        if ( me->query_temp("status"))
	{
        	message_vision("˾ͽͨ��������ļ�����������" + chinese_number(wager) +
			mtype->query("base_unit") + mtype->query("name") + "û��ϵ���´�һ����Ӯ����\n\n", me);
                mtype->set_amount((int)mtype->query_amount() - wager);
                mtype->move(me);
	}
	else
	{
		message_vision("˾ͽͨ��$Nһ���ֵ�������ϲ��ϲ��Ӯ��" + chinese_number(wager) +
			mtype->query("base_unit") + mtype->query("name") + "��������ʤ׷������\n\n", me);
		mtype->set_amount((int)mtype->query_amount() + wager);
		mtype->move(me);
	}
	me->delete_temp("status");
	this_object()->delete("doing");
	return;
}