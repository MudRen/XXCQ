// Room: jzroad2.c

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֡��м�һ��С·�����߶��Ǻ�ɭɭ�ļ��ɸߵ�������
������ˣ����Կ��������ߺøߵ�һ����ɽ������Ӧ�þ��Ƿ������ĺ�ɽ
�ˡ�
LONG );
	set("exits", ([
		"south" : __DIR__"jzroad1",
		"northeast" : __DIR__"jzroad3",
	]));
	set("outdoors", "feiyu");

	setup();
	replace_program(ROOM);
}


