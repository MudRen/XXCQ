// ���ԡ�����һ����
// Room: /city/choushiju.c
// LOAD 1999/1/29 

inherit ROOM;

void create()
{
	set("short", "��ʯի");
	set("long", @LONG
	���ﱾ��һ����ƽ����С�꣬��ӪһЩС�ֻ����������������ֽ������
����ͷ����Сʯ����������֮��������Ϊ��Сʯ������һ���ư˴������֣�����
�����������˲�֪�����˲���������İ���ǳ����ţ�һ�Ѻ��Σ�һ�ų���������
���ı������еľ���ǽ�ϵĸ����ֻ��ˡ�
LONG
	);

	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("no_fight",1);
	set("no_beg",1);

	set("objects", ([
	]));

	set("exits", ([
		"south" : __DIR__"shalan-w2",
	]));

}

