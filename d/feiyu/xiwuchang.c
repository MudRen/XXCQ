// Room : xiwuchang.c	
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
//

inherit ROOM;

void init();
int do_tiao(string);

void create ()
{
        set ("short", "�����䳡");
        set ("long", @LONG
����һ�����������䳡�����ӵ����뾹��һ��������ľ׮�Ĵ�ɳ��
���������������������ϰ�Ṧ������ľ׮��������ȥ������ʱҲ�м�
��ˤ������������������ɳ�ء�����Ҫˤ�˵ġ���Ҳ����ȥ��ľ׮������
����(tiao)��
LONG);
//	set("outdoors", "feiyu");
	set("exits", ([
                "north" : __DIR__"cailiaofang",
                "south" : __DIR__"fanting",
                "east" :__DIR__"qianting", 
                "west" :__DIR__"wroad", 
        ]));
        setup();
}

void init()
{
        add_action("do_tiao", "tiao");
}

int do_tiao(string arg)
{
        object me;
        int jingli_cost;

        me = this_player();

        if ( !arg || ( arg != "muzhuang" ) )
                return notify_fail("������ʲô��\n");

        jingli_cost = (-1) * (10 + random(5));

	if ( me->query("jingli") <= ( - jingli_cost ) )
		return notify_fail("��̫���ˣ�Ҫ��Ϣһ�����\n");

	if ( (int)me->query_skill("dodge", 1) < 11 )  
        {
		write("��������һ������һ��������һ���ϰ���ľ׮�����ǽ��²�ͣ�ĻΣ���Щˤ��������\n��������Ṧ������һ���˽⡣\n");
	        me->add("jingli", jingli_cost);
                me->improve_skill("dodge", (5 + random(me->query("int") / 2)));
        }
	else
		if ( (int)me->query_skill("dodge", 1) < 31 )  
        	{
			write("������ȫ��һ����Ծ��һ��ľ׮���Զ��˶٣���������������һ����\n����Ṧ������һЩ��ʶ��\n");
		        me->add("jingli", jingli_cost);
        	        me->improve_skill("dodge", (10 + random(me->query("int") / 2)));
	        }
		else
			write("���������ľ׮�Ϸɱ���Ծ���е��Ѿ�û�����ѡ�\n���������Ѿ�ѧ����ʲô�ˣ�\n");
        return 1;
}