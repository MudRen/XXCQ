// Room: /d/shaolin/twdian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������µ��е�����������������ƣ�᣽Ƕ��ˡ�����ǰ��
Ҫ��ʢ�Ķࡣ��ǰ�����Ÿ�����ӣ��ƺ���Զ��Ц��������շ��Ĵ���
���������ԣ���ִ�������˳�������������ϰ������ļ����ߣ����յ���
��վ������Τ�ԡ�ֻ���������ף�����Ӣ�����������ݣ�˫�ֺ�ʮ����
���ƺ�����ϡ��������߸���һ��ƫ�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"east" : __DIR__"twdian1",
		"west" : __DIR__"twdian2",
		"southdown" : __DIR__"taijie",
		"north" : __DIR__"guangchang2",
	]));
	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));

	setup();
	replace_program(ROOM);
}