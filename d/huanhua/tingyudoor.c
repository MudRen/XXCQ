//changan city

inherit ROOM;

void create ()
{
        set ("short", "����¥��ǰ");
        set ("long", @LONG
����¥��佻���®�Ӵ���͵ĵط����������վ������¥��¥�£���
����¥�����ܵ񻨣���Ϊ�����������״����ܽ��������۵Ĺ�â���Ĵ���
�ӡ�ʮ���֮һ������������Ӵ������õĿ��ˡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"enter" : __DIR__"tingyulou",
		"east" : __DIR__"qianroad2",
	]));

        set("objects", ([
                 __DIR__"npc/qiuyue": 1,
	]));

        set("outdoors", "xiao");

        setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;

	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "佻�����" ) && dir == "enter" )
	{
        	if(objectp(present("qiu yue", environment(me))))
        		return notify_fail("����������ס��ǫ��˵��������¥����ׯ������֮�������˲������ڣ�\n"
			+ RANK_D->query_respect(me) +"����Ϊ��ʦ��������ȥ�ϡ���ƫԺ�ɡ�\n");
	}

	return ::valid_leave(me, dir);
}