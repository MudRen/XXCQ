// Room: /d/shaolin/chufang.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ƣ��������ڣ���ζ�˱Ƕ�������ǽ��һ�����ɳ�����̨��֧
��ʮ���ڴ��������һ�ڷ����Ϸ������˴��������ն��£��ֳ�ľ����
���衣�����շ���ɮ���⣬��λ��ͷ��æ��������н������¯�����ܡ�
һλ����ɮ�������شߴ��š�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"fanting1",
	]));
	set("sljob2",1);
	set("objects",([
		__DIR__"npc/shaofan-seng" : 1,
	]));

	setup();
}