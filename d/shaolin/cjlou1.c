// Room: /d/shaolin/cjlou1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�ؾ����¥");
	set("long", @LONG
ǧ������������ִ��ԭ����֮ţ�����Դ�Ħ�������£������˲ı���
�������в��ٸ�ɮ�������棬�㼯�����ճ��������µ�������ʮ������
�����־����������ڴˡ���¥���濪����ȷ��ͨ�硣�м����������Ŵ���
�ܡ���������а������Թ��Ķ�����λ��ɮ��ִ�������ڱ�Ŀ��˼��
LONG );
	set("valid_startroom", 1);

	set("exits", ([
		"down" : __DIR__"cjlou",
	]));

	set("objects",([
		__DIR__"npc/tieting" : 1,
	]));

	setup();
}