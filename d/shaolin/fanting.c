// Room: /d/shaolin/fanting.c
// Date: YZC 96/01/19

inherit ROOM;

string* names = ({
	__DIR__"obj/mala-doufu",
	__DIR__"obj/bocai-fentiao",
	__DIR__"obj/shanhu-baicai",
	__DIR__"obj/liuli-qiezi",
});

void create()
{
	set("short", "ի��");
	set("long", @LONG
�����������ȫ����ɮ��ի�ĵط���ի���������������ǧ��ͬʱ
���͡��Ӷ�����һ���Ű����˳����Ĳ����ͳ��ʣ���λС����������æµ
�Ų�����ի�����ϰ��˼��趹��������������Լ���Ѽ����ζ��ʳ��
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"east" : __DIR__"guangchang3",
		"north" : __DIR__"fanting1",
	]));
	set("objects",([
		__DIR__"obj/qinghulu" : 1,
                names[random(sizeof(names))]: 5,
                names[random(sizeof(names))]: 5,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

