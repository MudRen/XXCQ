// Room: /d/playtown/biwuchang.c ���䳡
// Build 199.12.10 bmw

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
������Ҵ���Ĵ�������͹��еĵط���ʱ����������������໥��
�裬�������Ϊ������һ�����ص�ԭ��ɣ��������Ǻܴ�û��ʲô�磬һ
���СС�Ķ��������ﶼ�������������Զ�ĵط�����һ��Сʯ����bei��
,�ƺ�����ܾá�
LONG );
	set("outdoors", "playertown");
	set("exits", ([
		"south"  : __DIR__"miao",
	]));
	setup();
	replace_program(ROOM);
}
