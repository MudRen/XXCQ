//lianthrow.c		�������䳡

inherit ROOM;

void init();
int do_lian(string);

void create ()
{
        set ("short", "���䳡");
        set ("long", @LONG
����һ���������䳡�������߰��ż���ľ�ܣ�ÿһ��������
�ֳ�ʮ����С��ÿһ���ж����Ų�ͬ�İ�������Ķ��棬Ҳ���ǹ�
�����Ǳ��м���ľ��ģ�ͣ�ͷ�����������Ƕ������ɼ������������
����ϰ(zhi)�ƼҳưԽ����İ����ַ���
LONG);
//	set("outdoors", "wenjia");
	set("exits", ([
                "south" : __DIR__"nzlange3",
        ]));
        setup();
}

void init()
{
        add_action("do_lian", "zhi");
}

int do_lian(string arg)
{
        object me;
        int jingli_cost;

        me = this_player();

        if ( !arg || ( arg != "biao" ) )
                return notify_fail("�����ʲô��\n");

        jingli_cost = (-1) * (5 + random(15));

	if ( me->query("jingli") <= ( - jingli_cost ) )
		return notify_fail("��̫ƣ���ˣ�û�о��������ˡ�\n");

	if ( (int)me->query_skill("throwing", 1) < 51 )  
        {
		write("���ľ��������һö�������ںü�����ľ����ȥ�����͡���һ�������ˣ�\n������԰����ַ�������һ����ʶ��\n");
	        me->add("jingli", jingli_cost);
                me->improve_skill("throwing", (15 + random(me->query("int") / 2)));
        }
	else
		if ( (int)me->query_skill("throwing", 1) < 101 )  
		{
			write("���ľ��������һö������˦����ľ����ȥ�����͡���һ�������ˣ�\n��԰����ַ�����һЩ��ʶ��\n");
		        me->add("jingli", jingli_cost);
                	me->improve_skill("throwing", (20 + random(me->query("int") / 2)));
		}
		else
			write("����������һö������ľ����ȥ�����͡���һ������ü�ģ�\n���������Ѿ�ѧ����ʲô�ˣ�\n");
        return 1;
}