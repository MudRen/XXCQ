//bingqifang.c		�Ĵ����š�������

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ŵı�����������ܴ�ȴ������һ����ɱ֮������
ǽ�ڷ��ż��������ܣ�����һ����������ڷ���һЩ�������Ƶİ���
�ͱ����������ļ������������ǽ����г��õı�����
LONG
	);
	set("exits", ([
		"south" : __DIR__"nzlange2",
	]));
	set("objects", ([
		"/clone/weapon/changjian" : 4]));

	set("no_fight", 1);
	set("area", "����");	
	setup();
	replace_program(ROOM);
}