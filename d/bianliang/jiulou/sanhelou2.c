// Room:
// ɽèAdx 99-11-22 

inherit ROOM;

void create()
{
	set("short", "����¥��¥");
	set("long", @LONG
����������������ѧʿ������������ʫ��������������Ҳ������߳�
�ȱ������ס����ҪԱ���Ӹ�����������ĥʱ�⣬��վ��¥������������
һ���޾���ͬ�������������Ӱ��Զ���������������ܳ缹ֻ�����Ŀ���
������¥���ƹ���ϰ������������д����ˡ�
LONG
	);

         set("valid_startroom", 1);
	set("objects", ([
		__DIR__"xiaoer" : 1,
	]));

         set("area", "����");
	set("exits", ([
		"down" : __DIR__"sanhelou",
	]));

	setup();
	replace_program(ROOM);
}
