// Room: /d/shaolin/wuchang3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ���
��̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡�м������Ų���ľ�˺�
�ݰС����߽��ϻ���������ɳ�ӣ�ʮ����ɮ��������ϰ���ա����������
��һ����ɮ����
LONG
	);
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"fzlou",
		"north" : __DIR__"guangchang5",
		"northup" : __DIR__"dmyuan",
	]));

	set("outdoors", "shaolin");

	set("objects",([
		"/kungfu/class/shaolin/tiewu" : 1,
	]));

	setup();
}