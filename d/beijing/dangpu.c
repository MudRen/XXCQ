// Room: /city/dangpu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	���Ǿ���Ψһ��һ�ҵ��̣���Ϊ�ھ��ǿ����̣�����Ҫ�����ÿͻ�������
��Ҫ�����������µĹ�ϵ����ҵ��̵����ϰ����ھ��ǿ���ҵ��̳��Ｘʮ�꣬
��Ȼ�к�̨֧�ţ�������˭���Ͳ��ö�֪�ˡ��߽����̣�һ����߸ߵĹ�̨������
����ǰ����̨���������ϰ壬һ˫�������۾��������´������㡣
LONG
	);
	set("no_fight", 1);
	set("no_beg",1);

	set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/liu" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"shalan-w1",
	]));

	setup();
	replace_program(ROOM);
}

