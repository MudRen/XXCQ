// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��ü��");
	set("long", @LONG
��ü����û�е�ƣ�������ģ���ֻ��ģ���Ļ��ӣ��������ܵİ���
�ǳ��ļ򵥣�ͻȻ�㿴���ڰ����������ϸ��ˣ�һ�����������ϣ���Ŀ��
����һ��վ��������ߣ��������Ŀ��ɲ�ǵĶ��ӣ�ͻȻ����һ�䣬��
æ��Ŀ���ƿ��ˡ�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"luohua",
	]));

	setup();
	replace_program(ROOM);
}
