// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ۣ��������Ȩ�����Ե�ʣ�����������佻�������ϲ
�����ĵط��������ڣ����˴ҴҵĽŲ�������Ҳ����������Ц���ˡ���
�����߳��������仨��Ժ����ü������仨��Ժ�ڡ�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"qqlang_1",
		"southwest" : __DIR__"qqlang_3",
		"north" : __DIR__"luohua",
	]));

        set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}