// chanting.c ����
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"�����ǻ����Ĳ��������ڻ��������˽�����ʳ�����Ե��ӵĻ�ʳҲ��
��һ���ֳ�ʦ�����ղ�������ֻҪ��һ��(chifan)Ӷ�˾ͻ����Ͽɿڵ�
���ˡ�\n"
	);
	set("valid_startroom",1);
	set("no_fight",1);
	set("exits",([
		"north" : __DIR__"liangong2",
		"east" : __DIR__"caifang",
	]));
	setup();
}

void init()
{
	add_action("do_chifan","chifan");
}

int do_chifan()
{
	object ob=this_player();
	int shiwu,yinshui;
	shiwu = ob->max_food_capacity();
        yinshui = ob->max_water_capacity();
        
        ob->set("food", shiwu);
        ob->set("water", yinshui);
        
        message_vision("$N�����Ķ��ӣ����˸����á�\n",ob);
        return 1;
}
