//huayuan.c		�Ĵ����š���԰

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����ڵĵص��г���, �㷢���Լ�����������һ�������µ�С��
԰��, ��÷����, ���ɴ��, ���õ��ľ߽���, ����ȥ��һ����ʯС
�ݡ�
LONG);
	set("exits", ([
			"east" : __DIR__"andao2",
			"south" : __DIR__"shiwu",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}