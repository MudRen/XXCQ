// Room: /city/sanhelou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����¥�������Ǿ�¥�������������ϵ�һ�ң����������ڳǣ�����
�๫�ӹ�Ա������˵ĵط�������Ҳ�Ǿ��Ǽ������̸�г�ѡ�ĵط���¥
�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�
¥����������
LONG
	);
	set("no_fight",1);
	set("valid_startroom", 1);
	set("exits", ([
		"up" : __DIR__"sanhelou2",
		"east" : "/d/bianliang/huangshanjie5",
	]));

	set("objects", ([
		__DIR__"xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}
