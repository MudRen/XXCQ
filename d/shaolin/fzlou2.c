// Room: /d/shaolin/fzlou2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ҳ����࣬����һ����һ���ţ�һ����������ǽ��д�Ŵ���
һ���������֡�һλ��ü��Ŀ�Ļ�����ɮ�������������ϴ������������
����ȴ̧Ҳ��̧һ��ͷ��
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"fzlou1",
	]));
	set("objects",([
		"/kungfu/class/shaolin/tianzheng" : 1,
	]));
	setup();
	replace_program(ROOM);
}

