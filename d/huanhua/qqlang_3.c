// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ߵ������Ѿ����Ǽž��ˣ��������Ϊ佻����ӵ�˯��������
���Ե�ʰɡ������ͺ����˾�����ż�����˾���Ҳ��Ĭ����������������
���Ͽ��Ե�佻��صؼ��춴��
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"boyroom",
		"northeast" : __DIR__"qqlang_2",
		"south" : __DIR__"jiashan",
	]));

        set("objects", ([
		__DIR__"npc/shulin" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;

	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "佻�����" || myfam["generation"] > 4 ) && dir == "south" )
	{
        	if(objectp(present("shu lin", environment(me))))
        		return notify_fail("����������ס����������佻��صأ������Ҵ�����������뿪��\n");
	}

	if (me->query("gender")=="Ů��" && dir == "west")
	{
		return notify_fail("��һ��Ů���ӣ����е�����Ϣ����ʲô��\n");
	}

	return ::valid_leave(me, dir);
}