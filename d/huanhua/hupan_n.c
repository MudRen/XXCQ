//changan city

inherit ROOM;

void create ()
{
        set ("short", "�仨����");
        set ("long", @LONG
�س����ߵ��仨���ĺ��ߣ��仨�������ذ��İ���������������ÿ��
�仨���ڣ����涼Ҫ�������������һ�����������Ҳ������������š�һ
�������ƺ��������������򱱿��Ե���ƺ�С������ü��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"northwest" : __DIR__"qqlang_1",
		"south" : __DIR__"hupan_s",
		"east" : __DIR__"northlang_2",
	]));

        set("objects", ([
                 __DIR__"npc/yanjun": 1,
	]));

        set("outdoors", "xiao");
        setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;

	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "佻�����" ) && dir == "northwest" )
	{
        	if(objectp(present("yan jun", environment(me))))
        		return notify_fail("���������ס��ǫ��˵���������ﲻ������룬��λ"+ RANK_D->query_respect(me) +"��ذɡ�\n");
	}

	return ::valid_leave(me, dir);
}