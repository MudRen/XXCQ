// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ÿһ����ͷ�߼�������һ���������Ȼ������ʧ�ޡ���
�ò�������ȴ�����ʢ��Ϊ�˱��ӳ��������ģ�����ͽ��ϵľ��񶼾���
����������ݣ�����û�к��У�ֻ��һ����ٵ���ף���������֡�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"north" : __DIR__"jiangpan1",
	]));

	set("objects", ([
		__DIR__"npc/miaozhu": 1,
	]));

	setup();
	replace_program(ROOM);
}