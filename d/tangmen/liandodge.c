//liandodge.c		�������䳡

inherit ROOM;

void init();
int do_lian(string);

void create ()
{
        set ("short", "���䳡");
        set ("long", @LONG
����һ���������䳡�������ǰ�ĳ�����������һ����ľ׮��
�������ŵ�����������ʩչ�Ṧ�����ɿ���Ĵ����ߣ�����ʱҲ
�м���ˤ��������Ū�ı������ס���Ҫ���¾�Ҳ��ȥ���� (yue)��
�����Ṧ���ɡ�
LONG);
//	set("outdoors", "wenjia");
	set("exits", ([
                "north" : __DIR__"nzlange3",
        ]));
        setup();
}

void init()
{
        add_action("do_lian", "yue");
}

int do_lian(string arg)
{
        object me;
        int jingli_cost;

        me = this_player();

        if ( !arg || ( arg != "zhuang" ) )
                return notify_fail("�����ʲô��\n");

        jingli_cost = (-1) * (5 + random(15));

	if ( me->query("jingli") <= ( - jingli_cost ) )
		return notify_fail("��̫ƣ���ˣ�û�о��������ˡ�\n");

	if ( (int)me->query_skill("dodge", 1) < 51 )  
        {
		write("�����˵������һ��������һ���ϰ���ľ׮�����ǽ���һ��ˤ��������\n��������Ṧ������һ���˽⡣\n");
	        me->add("jingli", jingli_cost);
                me->improve_skill("dodge", (15 + random(me->query("int") / 2)));
        }
	else
		if ( (int)me->query_skill("dodge", 1) < 101 )  
        	{
			write("������������һ����Ծ��һ��ľ׮��ֻ�Ǹе���Ϣ�������ͣ�\n����Ṧ������һЩ��ʶ��\n");
		        me->add("jingli", jingli_cost);
        	        me->improve_skill("dodge", (20 + random(me->query("int") / 2)));
	        }
		else
			write("���������ľ׮�Ϸɱ���Ծ���е��Ѿ�û�����ѡ�\n���������Ѿ�ѧ����ʲô�ˣ�\n");
        return 1;
}