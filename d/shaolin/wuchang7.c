// Room: /d/shaolin/wuchang3.c
// Date: YZC 96/01/19

inherit ROOM;
int do_da(string);

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µĶ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ��
�Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡�м������Ų���ľ��
��ʮ����ɮ�����ڻ���ľ��(da muren)��ϰ���ա�������ǳ�����������
���ֵİ����á��ϱ����������ȡ�
LONG
	);
	set("valid_startroom", 1);
	set("exits", ([
		"east" :__DIR__"luohan",
		"south" : __DIR__"zoulang4",
		"west" : __DIR__"wuchang2",
		"north" : __DIR__"zoulang8",
	]));

	set("outdoors", "shaolin");

	set("objects",([
		"/kungfu/class/shaolin/tianlong" : 1,
        "/kungfu/class/shaolin/tianguan" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_da", "da");
}

int do_da(string arg)
{
	object me;
	int a, b;

	me = this_player();

	if ( !arg || ( arg != "muren" ) )
                return notify_fail("�����ʲô��Ҫ��ʹ���ǰ�����ľ��(muren)�ɡ�\n");

	a = random(20)+25;
	b = random(20)+25;

        if((int)me->query("jingli") < a)
	{
                return notify_fail("�����ھ����޷����У����������˰ɣ�\n");
                return 1;
	}
        if((int)me->query("qi") < b)
	{
                return notify_fail("�㶼�������ˣ���ЪЪ�ɣ�\n");
                return 1;
	}

        me->add("jingli", -a);
        me->add("qi", -b);

        message_vision("$N���ľ�������ɣ�����������һ��һ�Ƶ���ľ�˴�ȥ��\n", me);

        if ( (int)me->query_skill("strike", 1) < 101)
        {
                me->improve_skill("strike", (me->query_int()+ random(me->query("int"))));
                tell_object(me, "������ƴ�����ۣ������Ʒ�����һ���Ľ����ˣ�\n");
        }
        else
        { 
                tell_object(me, "��һ����Щ��ľ�˴��ˣ�������Ҳ����ͨ����ľ�����Ʒ��ˡ�\n");
        }
        return 1;
}
