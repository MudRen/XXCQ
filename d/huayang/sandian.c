// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "ɡ��");
	set("long", @LONG
���ǳ��ɶ����ڵ�����ɡ���⼸ʮ��Ψһ��һ��ɡ�꣬��������Ӧ��
�Ǻܲ���ģ�������Ȩ���������®��ʹ�ø����ľ���Ҳ������������
��ɡ�������Ҳһ��ǧ�ɡ�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"hyroad4",
	]));

	set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}