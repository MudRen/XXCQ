// Room: /d/murong/boat.c

inherit ROOM;

int do_turn(string);
int do_save();
int do_quit();
int do_goto();
int do_home();
int do_gg();
int do_tiaowang();

void create()
{
	set("short", "����");
	set("long", @LONG
С���Ѿ�������ãã���ϡ����ܳ���ż���ӹ�ͷ���ĺ����⣬��ֻʣ��
��������������С�������ھ۾������ҡ���ֵ��ҹ��ˡ���������Ϯ�����㲻
���е�һ˿���⡣
LONG
	);
	set("objects", ([
		__DIR__"npc/shaogong.c":1,
	]));
	set("no_fight",1);
	set("no_sleep_room",1);
	set("outdoors","����Ľ��");

	setup();
}

void init()
{
	object ob = this_player();

	if (!userp(ob)) return;
	if (query_temp("busy")) {
		if (!wizardp(ob)) {
			message_vision("������$N�ȵ�����ô���������\n",ob);
			message_vision("����һ����$N���䵽���\n",ob);
			ob->unconcious();
			ob->move(__DIR__"xd");
			message("vision","��Ȼ�̲���һ����ˮ�ݵð����ļһ�嵽�˰��ߡ�\n",environment(ob),ob);
			return;
		}
		else {
			message_vision("�������εض�$N˵��������ʦ���Ǻã��������԰�����\n",ob);
			return;
		}
	}
	set_temp("busy", 1);
	add_action("do_turn","turn");
	add_action("do_turn","zhuan");
	add_action("do_save","save");
	add_action("do_quit","quit");
	add_action("do_goto", "goto");
	add_action("do_gg", "gg");
	add_action("do_home", "home");
	add_action("do_tiaowang","tiaowang");
	ob->delete_temp("mr_dir");
	ob->set_temp("mr_locx", 1);
	ob->set_temp("mr_locy", 1);
	
	call_out("time_limit1", 300, ob);
	call_out("location", 3, ob);
}

int abs(int num)
{
	if (num < 0) return (0 - num);
	else return num;
}

int do_save()
{
	write("���ﲻ׼���̣�\n");
	return 1;
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}

int do_goto()
{
	if (wiz_level(this_player()) > 0)
		delete_temp("busy");
	return 0;
}

int do_home()
{
	if (wiz_level(this_player()) > 1)
		delete_temp("busy");
	return 0;
}

int do_gg()
{
	if (wiz_level(this_player()) > 2)
		delete_temp("busy");
	return 0;
}

void time_limit1(object ob)
{
	if (!present(ob, this_object())) return;
	message_vision("������$N˵�����͹٣������Ͽ�����Ҫ����ˣ����ǻ�ȥ�ɣ�\n", ob);
	call_out("time_limit2", 120, ob);
}

void time_limit2(object ob)
{
	if (!present(ob, this_object())) return;
	message_vision("������$N˵�����͹٣��ٻ���ȥ���ǿɶ�Ҫ���������ˣ��㲻Ҫ���һ�Ҫ�ģ�\n", ob);
	write("������Ҳ�������������ֱ�����˰��ߡ�\n");
	ob->delete_temp("mr_dir");
	remove_call_out("location");
	delete_temp("busy");
	ob->move(__DIR__"xd");
	ob->delete("mr/x");
	ob->delete("mr/y");                
	ob->delete_temp("mr_locx");
	ob->delete_temp("mr_locy");	
}

int do_turn(string arg)
{
	string dir;
	object ob = this_player();

	switch(arg) {
		case "e": 
		case "east": 
			dir = "��";
			break;
		case "w": 
		case "west": 
			dir = "��";
			break;
		case "n": 
		case "north": 
			dir = "��";
			break;
		case "s": 
		case "south": 
			dir = "��";
			break;
		default:
			return notify_fail("��Ҫ���ĸ����򿪣�\n");
	}
	ob->set_temp("mr_dir", arg[0..0]);
	message_vision("$N������˵����" + dir + "����\n", ob);
	message_vision("������$NӦ�����õģ�����λ��(location)����Ȼ�����������Ҫ������(tiaowang)Ҳ�������\n",ob);
	return 1;
}

int do_tiaowang()
{
	int viewdist = 4;
	object ob = this_player();

	if ((abs(ob->query_temp("mr_locx") - ob->query("mr/x"))
	+ abs(ob->query_temp("mr_locy") - ob->query("mr/y")) <= viewdist) ) 
	{
		message_vision("����ָ��Զ����$N˵�����͹٣��Ǳ߾����������ˣ�����ͻ���ȥ��\n", ob);
		write("����һ����ˣ����������ػ����˰��ߡ�\n");
		remove_call_out("time_limit1");
		remove_call_out("time_limit2");
		ob->move(__DIR__"ab1");
		delete_temp("busy");   
		ob->delete("mr/x");
		ob->delete("mr/y");        
		ob->delete_temp("mr_locx");
		ob->delete_temp("mr_locy");		
		return 1;
	}
	return notify_fail("�㼫ĿԶ�������ǳ��˺�����ï�ܵĺɻ���ȴʲôҲ��������\n");
}

void location(object ob)
{
	int locx=ob->query_temp("mr_locx");
	int locy=ob->query_temp("mr_locy");
	string dir = ob->query_temp("mr_dir");

	if (!present(ob, this_object())) {
		delete_temp("busy");
		remove_call_out("time_limit1");
		remove_call_out("time_limit2");
		return;
	}
	if (!dir) {
		call_out("location", 3, ob);
		if (!random(3))
			message_vision("�������ͷ��ض�$N˵���͹ٵ����߲��߰���\n", ob);
		return;
	}
	switch (dir) {
		case "e": 
			dir = "��";
			if (locy > 0) locx++;
			break;
		case "w": 
			dir = "��";
			if (locx == 1) message_vision("������$N˵���͹�,Ҫײ�������ˡ�\n", ob);
			if (locx > 0 && locy > 0) locx--;
			break;
		case "n": 
			dir = "��";
			if (locy == 1) message_vision("������$N˵���͹�,Ҫײ�������ˡ�\n", ob);
			if (locy > 0 && locx > 0) locy--;
			break;
		case "s": 
			dir = "��";
			if (locx > 0) locy++;
			break;
	}
	if (locx < 1 || locy < 1) message_vision("С��ͣ���˰��ߡ�\n", ob);
	else message_vision("С��������" + dir + "��ǰ����\n", ob);
	if (locx == ob->query("mr/x") && locy == ob->query("mr/y"))
	{
		message_vision("������$N˵�����͹٣������뵽�ˣ����´��ɡ�\n", ob);
		remove_call_out("time_limit1");
		remove_call_out("time_limit2");
		ob->move(__DIR__"ab1");
		delete_temp("busy");
		ob->delete("mr/x");
		ob->delete("mr/y");	
		ob->delete_temp("mr_locx");
		ob->delete_temp("mr_locy");			
		return;
	}
	ob->set_temp("mr_locx", locx);
	ob->set_temp("mr_locy", locy);
	call_out("location", 2, ob);
}
