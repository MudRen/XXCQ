// Room: /d/shaolin/dmyuan2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "��ĦԺ��¥");
	set("long", @LONG
����һ�����ӵĵ��á����׵�ǽ�Ϲ����˸����书ͼ�ף����ٰ����
ü����ɮ����������ͼ�׻���֮ǰ���ƺ��ڿ��˼�����ϱ�ɽǽ�Ǹ߼���
���Ĵ���ܣ��߽�ϸ���������Ǹ��Ÿ��ɵ��书���ţ������а��ż��Ű�
��ڭ�ͼ����ţ���λ��ɮ�����붨�С�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"down" : __DIR__"dmyuan",
	]));
	set("objects",([
		"/kungfu/class/shaolin/muye" : 1,
	]));
	setup();
}
