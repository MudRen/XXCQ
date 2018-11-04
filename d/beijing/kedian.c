// Room: /city/kedian.c
// LOAD 

inherit ROOM;

void create()
{
	set("short", "�����ջ");
	set("long", @LONG
	���Ǳ������ļҿ͵��м۸��������һ�ң�һЩûǮ��ѧ�Ӻ͸�����״��
���˶�ѡ��������ţ�������������ˣ�������ʩҲ��ª������û�з�ʳ��Ӧ����
��Ҳֻ�д�ͨ�̿���ס�����������Ǯ�ˣ������������͵꿴һ����������������
һ�Ҹ����ڿ͵���¿�����վ��ǽ�ϻ�����һ������(paizi)��
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "�ͷ�ͨ�̣�ÿҹʮ��������\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
		"north" : __DIR__"shalan-w2",
		"west" : __DIR__"bjyizhan",
		"enter" : __DIR__"kefang",
		"up" : "/d/wizard/guest_room",
	]));

	setup();
	
	"/clone/board/kedian_b"->foo();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "enter" )
	return notify_fail("��С��һ�µ���������ǰ������һ���������ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "north" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
