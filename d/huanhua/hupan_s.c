//changan city

inherit ROOM;

void create ()
{
        set ("short", "�仨����");
        set ("long", @LONG
�س����ߵ��仨���ĺ��ߣ��仨�������ذ��İ���������������ÿ��
�仨���ڣ����涼Ҫ�������������һ�����������Ҳ������������š�һ
�������ƺ����������������Ͽ��Ե������䳡�͹����
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"southwest" : __DIR__"jqlang_1",
		"north" : __DIR__"hupan_n",
		"east" : __DIR__"southlang_2",
	]));

        set("objects", ([
                 __DIR__"npc/haishen": 1,
	]));

        set("outdoors", "xiao");
        setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;

	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "佻�����" ) && dir == "southwest" )
	{
        	if(objectp(present("hai shen", environment(me))))
        		return notify_fail("����������ס��ǫ��˵���������ﲻ������룬��λ"+ RANK_D->query_respect(me) +"��ذɡ�\n");
	}

	return ::valid_leave(me, dir);
}