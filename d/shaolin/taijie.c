// Room: /d/shaolin/taijie.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "̨��");
	set("long", @LONG
����ɽ�ŵ��ǰ����ƽ�е���ʯ̨��ͨ��ǰ����һ����̨��̨����
�����ο������룬���꣬�ɺ׵����ޣ���̬���涯�ˡ���̨���з��Ÿ���
�˸ߵ���ͭ����¯��ǰ����Ÿ���̨����λ����������Ӱݡ�����ǰ��
�������
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"smdian",
		"northup" : __DIR__"twdian",
	]));
	set("outdoors", "shaolin");
	set("objects",([
		__DIR__"npc/tiejian" : 1,
	]));

	setup();
	replace_program(ROOM);
}