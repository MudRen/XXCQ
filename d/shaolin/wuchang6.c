// Room: /d/shaolin/wuchang3.c
// Date: YZC 96/01/19

inherit ROOM;
int do_da(string);

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ������䳡����������޴�Ļ�����ʯ���̾͡���ǧ���
��̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡�м������Ų���ľ׮��׮
�϶���һЩǧ��ֽ,ʮ����ɮ������ֽ(da zhi )��ϰȭ����������ǳ�����
�����ָ��ֵİ����á��ϱ����������ȡ�
LONG
	);
	set("valid_startroom", 1);
	set("exits", ([
		"west" :__DIR__"banruo",
		"south" : __DIR__"zoulang1",
		"east" : __DIR__"wuchang1",
		"north" : __DIR__"zoulang5",
	]));

	set("outdoors", "shaolin");

	set("objects",([
		"/kungfu/class/shaolin/tianheng" : 1,
        "/kungfu/class/shaolin/tiancheng" : 1,
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

	if ( !arg || ( arg != "zhi" ) )
                return notify_fail("�����ʲô��Ҫ��ʹ�ǧ��ֽ(zhi)�ɡ�\n");

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

        message_vision("$N���һ�����ںü��ƣ�һȭ����ǧ��ֽ�ϡ�\n", me);

        if ( (int)me->query_skill("cuff", 1) < 101)
        {
                me->improve_skill("cuff", ((me->query("int"))+ random(me->query("int"))));
                tell_object(me, "����������Щ���ۣ���Ļ���ȭ������һЩ������\n");
        }
        else
        { 
                tell_object(me, "��һȭ����ǧ��ֽ�����ˣ�����������������ûʲô�����ˡ�\n");
        }
        return 1;
}
