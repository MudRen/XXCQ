//changan city

inherit ROOM;
int do_da(string);

void create ()
{
        set ("short", "���䳡");
        set ("long", @LONG
����һ�����������䳡�����䳡����������ں���䤱������Ź���
�ڳ����зֲ���ʮ���ľ׮�������ǲ�ͣ�����ƴ���ľ׮(da zhuang )��
�����䳡��������һ��С�ݣ����ǽ�®�ķ����ݣ���Ҳ���Խ�ȥ��һ����
�ϵķ��ߡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"wuchang1",
		"south" : __DIR__"fangjuku",
	]));

        set("outdoors", "xiao");

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

	if ( !arg || ( arg != "zhuang" ) )
                return notify_fail("�����ʲô��Ҫ��ʹ���ǰ�����ľ׮��(zhuang)�ɡ�\n");

	a = random(20)+20;
	b = random(20)+20;

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

        message_vision("$N�����ɣ�����������һ������ľ׮���ϡ�\n", me);

        if ( (int)me->query_skill("strike", 1) < 101)
        {
                me->improve_skill("strike", ((me->query("int"))+ random(me->query("int"))));
                tell_object(me, "�����������ƴ�����ۣ�\n����Ʒ������ˣ�\n");
        }
        else
        { 
                tell_object(me, "��һ����Щ��ľ׮�Ӵ��ˣ�������Ҳ����ͨ����ľ׮���Ʒ��ˡ�\n");
        }
        return 1;
}