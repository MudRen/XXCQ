//yanwuchang��c           Ѫ�������䳡

inherit ROOM;

void init();
int do_lian(string);

void create ()
{
        set ("short", "���䳡");
        set ("long", @LONG
������Ѫ���ɵ����䳡�������ǰ�ǰ�ʮ����ƾ��ɵĻ����ˣ�����
���ڷų�һ������������ֻҪ�����߽��������Ǿͻ��Զ���������ʱ��
���˱���������������������(jin)�������мܹ���
LONG);
	set("exits", ([
                "southeast" : __DIR__"qixuetang",
        ]));
        setup();
}

void init()
{
        add_action("do_lian", "jin");
}

int do_lian(string arg)
{
        object me;
        int jingli_cost;
        int qi_cost;

        me = this_player();

        if ( !arg || ( arg != "zhen" ) )
                return notify_fail("�����ʲô��\n");

        jingli_cost = (-1) * (5 + random(15));
	qi_cost = (-1) * (1 + random(5));

	if ( me->query("qi") <= ( - qi_cost ))
		return notify_fail("��̫�����ˣ�������Ҫ�������ˡ�\n");

	if ( me->query("jingli") <= ( - jingli_cost ) )
		return notify_fail("��̫ƣ���ˣ�û�о��������ˡ�\n");

	if ( (int)me->query_skill("parry", 1) < 51 )  
        {
		write("���������������£�С��������߽�ľ�����У���һ����ͱ���ı������ף�\n������Ի����м�����һ���˽⡣\n");
	        me->add("jingli", jingli_cost);
	        me->add("qi", qi_cost);
                me->improve_skill("parry", (15 + random(me->query("int") / 2)));
        }
	else
		if ( (int)me->query_skill("parry", 1) < 101 )  
        	{
		write("����������֫�������߽�ľ�����У����ϵ���ľ�˵�Ϯ����\n��Ի����м�����һЩ��ʶ��\n");
		        me->add("jingli", jingli_cost);
		        me->add("qi", qi_cost);
        	        me->improve_skill("parry", (20 + random(me->query("int") / 2)));
	        }
		else
			write("��˦���߽�ľ�����У���û��һ��ľ���ܹ�����������壡\n���������Ѿ�ѧ����ʲô�ˣ�\n");
        return 1;
}
