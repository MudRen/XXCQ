//fangjvfang.c		�Ĵ����š����߷�

inherit ROOM;

void create()
{
	set("short", "���߷�");
	set("long", @LONG
�������������ŵķ��߷�������ܴ󣬿�ǽ�ڷ��ż���ľ�ܣ���
�����һЩ�����þߣ�����������ֹ����ϰ���˵��Լ������������
ɫ�ģ�Ī�����������Ŷ��е�¹Ƥ���ס�
LONG
	);
	set("exits", ([
		"north" : __DIR__"nzlange2",
	]));
	set("objects", ([
		"/clone/weapon/changjian" : 4]));

	set("no_fight", 1);
	set("area", "����");	
	setup();
	replace_program(ROOM);
}