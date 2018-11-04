// Room: /city/kefang.c
// YZC 1995/12/04 
#define TIME1 10
#define TIME2 15

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ���������ڣ���������һ����ı��ӣ�·;����ңԶ��
�������Ϣһ�ᡣ���ǹҵ�������������á�������������... ...
LONG
	);
	setup();
}

void init()
{
	if(!query("back_flag"))
	{
		call_out("do_go_back",TIME1+TIME2+5);
		set("back_flag",1);
	}
	add_action("do_quit", "quit");
	add_action("do_lian", "dazuo");
	add_action("do_lian", "exercise");
	add_action("do_lian", "tuna");
	add_action("do_lian", "zhoutian");
	add_action("do_lian", "du");
	add_action("do_lian", "learn");
	add_action("do_lian", "xue");
	add_action("do_fight", "fight");
	add_action("do_fight", "kill");
	add_action("do_steal", "steal");
}

int do_go_back()
{
	int i;
	object *inv;
	inv=all_inventory(this_object());
	if(!query("back_flag"))
		return 0;
	message("vision","��������һ�����ף�����������Ҫȥ�ĵط�ѽ��\n"+
		"���һ����ɫ��˵������Ҫȥ�ĵط�ȥ���ˣ���ֻ�а����ͻ�������ˡ���\n\n",this_object());
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->is_character())
		{
			if(!inv[i]->move(inv[i]->query_temp("mache_start")))
				inv[i]->move(inv[i]->query("startroom"));
		}
	}
	this_object()->delete("back_flag");
	return 1;
}
			
int do_quit()
{
	object me;
	me = this_player();
	message("vision", "���ڳ���,���ڲ����˳�!���Ժ�.\n", me );
	return 1;
}

int do_lian()
{
	object me;
	me = this_player();
	message("vision", "������,�������»������Ϣ,С���߻���ħ!\n", me );
	return 1;
}

int do_fight()
{
	object me;
	me = this_player();
	message("vision", "������?С��ˤ��ȥ!\n", me );
	return 1;
}

int do_steal()
{
	object me;
	me = this_player();
	message("vision", "��������?���ð�?\n", me );
	return 1;
}
