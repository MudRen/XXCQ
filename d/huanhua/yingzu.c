// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "ӥ����");
	set("long", @LONG
�߽��������Ϳ�����ǰ��һ���˸ߵ�ˮī����ӥ�����ա������ڷ���
ʮ����������ÿ����ǰ��������д��ʲô������û�������õ����£�����
����һ��æµ����ʱ�е��ӴҴ������Ҵ�ȥ��
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"west" : __DIR__"northyuan",
	]));

        set("objects", ([
		"/kungfu/class/huanhua/song" : 1,
	]));

	setup();
	replace_program(ROOM);
}