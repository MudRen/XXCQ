// Room: /d/gvmt/jianyu_do.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����һ�ŷ�");
	set("long", @LONG
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ
���Կ�������ƺ��м�����Ӱ��������ת��ͷȥ������������ס
���������ŵص����㡣�ıڱ�����ֻ��һ��С�ţ����Ͽ��˸���
�ƴ�Ķ��������ͷ��õġ��ű���һ�Ѷ�������ȥ�����ݵ�ɢ��
������ϸ��ȴ��һ�߰׵÷����Ŀݹǡ�
LONG
	);
	set("valid_startroom",1);
     set("no_fight",1);
	set("no_steal",1);
        set("objects",([
                __DIR__"npc/bukuai" : 1,
        ]));
	setup();
}

void init()
{
	object ob;
	
	if (interactive(ob = this_player()))
    {	
		ob->set("no_get_from",1);
		message("vision",
				HIY "ֻ���η����ſ��һ�죬�������˽�����\n\n" NOR, 
				environment(ob), ob);
		tell_object(ob, "����������ٺٵ�Ц�ţ���������������������...��\n");
		ob->set("startroom", "/d/sroom/jianyu");
		if( (int)ob->query_condition("jianyu") <= 0 )
			ob->apply_condition("jianyu",45);//���δ���ó���ʱ�䣬������Ϊ45
	}
}
