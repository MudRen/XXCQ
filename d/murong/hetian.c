// hetian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"����"NOR);
	set("long",
"ԲԲ��һ�������, ���ü��������м���"GRN"С��"NOR"��С�����ƺ���ЩС
�ڵ����ƶ�����֪����ʲôˮ�����ҰѼ? ���ߵ�ǳ̲���п�"HIM"ë����"NOR"(tree), ǳ̲��
��Զ������һ��Ƭ�����͵�"GRN"����"NOR".������Ŵ���ȥ��һ�ơ�\n"
);
	set("no_clean_up", 0);
	set("item_desc", ([
"tree" :("һ����ڴֵ�����, �����кö��ë��(tao), �����Կ��ܲ�����(climb)��ȥ��\n"),
"boat":("һֻ��ˮ��ҡҡ�λεĴ��������е�����(jump)��ȥ��\n"),
"tao":(HIM"�Ѿ���͸�˵��Ҷ����Ϳ�������������ˡ�\n"NOR),
]));

	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_jump","jump");
}       

int do_jump(string arg)
{
	if(!arg||arg!="boat")
		return notify_fail("��Ϲ����С�ĵ���ˮ���ˡ�\n");
	message_vision("$N����Ľ⿪���ӣ�һ��������ͷ��ȥ��\n", this_player());
	this_player()->move(__DIR__"boat1");
	message_vision(BLU"$N���˺ô󾢲���ס����. ���ŵøϽ���������.\n"NOR, this_player());
	return 1;
}

int do_climb(string arg)
{
	object ob, me;
	me = this_player();
	if (!arg|| arg!="tree")
		return notify_fail("��Ҫ��������?\n");

	switch(random(6))
	{
		case 0: 
		case 1:
		case 2:
		message_vision(HIR"$Nһ����������, ž��һ��һ����֦����, ������ϵ�������.\n"NOR,me);
		break;
		case 3:
		case 4:
		message_vision(HIR"$Nһ��С�İ��ֹ�����Ƥ, �Ͻ���������.\n"NOR,me);
		break;
		case 5:
		message_vision(HIG"$N���˾�ţ����֮������ժ����һ��"HIM"��������ë��.\n"NOR,me);
                ob=new("/u/ievolo/food/maotao");
		ob->move(this_player());
		break;
}
return 1;
}
