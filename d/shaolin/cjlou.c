// Room: /d/shaolin/cjlou.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�ؾ���һ¥");
	set("long", @LONG
����Ϊ��ԭ�𷨵���Դ�������´˴��ؾ�֮�������º�����ƥ������
�����������飬�߼��������ܣ���ܼ��������һ��ͨ�еĿ�϶������
������м䣬����ط������ɳ���������Ŀ�⼰�����㿴�����Ϸ��˼���
�𾭡�
LONG );
	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"zhulin5",
		"up" : __DIR__"cjlou1",
	]));

	set("objects",([
		__DIR__"obj/jing1" : 2,
	]));

	setup();
}