// Room: /d/shaolin/guangchang3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���޳�");
	set("long", @LONG
���ǽ���Ժǰ�����޳���������ȫ�½�ͨ���ܼ��ĵط���ֻ��һ�Ӷ�
ɮ������ȥȥ�����Ÿ��ַ�ɫ���е�Я������ǹ�������ȵȱ�����������
�˽ý�����̬ׯ�ء�����Ĵ������ն������������ն��á�����ͨ��ի
����
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"guangchang2",
		"north" : __DIR__"guangchang4",
		"northup" : __DIR__"pdtang",
		"west" : __DIR__"fanting",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
}