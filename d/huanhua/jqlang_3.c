// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ߵ������Ѿ����Ǽž��ˣ��������Ϊ佻����ӵ�˯��������
���Ե�ʰɡ������ͺ����˾�����ż�����˾���Ҳ��Ĭ����������������
�������Ե�佻��صؼ��춴��
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"girlroom",
		"southeast" : __DIR__"jqlang_2",
		"north" : __DIR__"jiashan",
	]));

        set("objects", ([
		__DIR__"npc/zhenfeng" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;

	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "佻�����" || myfam["generation"] > 4 ) && dir == "north" )
	{
        	if(objectp(present("zhen feng", environment(me))))
        		return notify_fail("���������ס����������佻��صأ������Ҵ�����������뿪��\n");
	}

	if (me->query("gender")=="����" && dir == "west")
	{
		return notify_fail("��һ�����ˣ���Ů������Ϣ����ʲô��\n");
	}

	return ::valid_leave(me, dir);
}