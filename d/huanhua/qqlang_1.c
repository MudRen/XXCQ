// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��γ���֮���Գ�Ϊ�����Ⱦ�����Ϊ���غ����У��������ۣ�վ����
����������仨�������ľ�ɫ��������紵�����ǳ���⡣�ӱ��������
����һ��С¥������ׯ�����鷿�����ײ�Ҫȥ���ŵĺá�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"southeast" : __DIR__"hupan_n",
		"west" : __DIR__"qqlang_2",
        "north" : __DIR__"menqian",
	]));

        set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}
