// Room: /city/kedian.c
// LOAD 

inherit ROOM;

void create()
{
	set("short", "�����ջ");
	set("long", @LONG
���Ǳ����Ǽ��ҿ͵��м۸��������һ�ң�һЩûǮ��ѧ�Ӻ͸�����
״�����˶�ѡ��������ţ�������������ˣ�������ʩҲ��ª������û��
��ʳ��Ӧ������Ҳֻ�д�ͨ�̿���ס��С��æµ�к��Ž��������Ŀ��ˣ�
ǽ�ϻ�����һ������(paizi)����������Сѩ����������
LONG
	);

          set("no_fight",1);
	set("valid_startroom", 1);
         set("resource/water", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "�ͷ�ͨ�̣�ÿҹʮ��������\n",
	]));

	set("objects", ([
        __DIR__"npc/xiaoer" : 1,
        "/topten/topbook" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"nandajie1",
		"enter" : __DIR__"kefang",
		"up" : "/d/wizard/guest_room",
 //        "west": "/d/shequ/jiaowai1",
		"ע��":"/adm/wel1",
	]));
	set("area", "����");
	setup();
	call_other("/clone/board/guangming_b", "???");
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "enter" )
	return notify_fail("��С��һ�µ���������ǰ������һ���������ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "east" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
