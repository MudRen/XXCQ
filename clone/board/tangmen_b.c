// /clone/board/tangmen_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�������Բ�",({"board"}));
	set("location","/d/tangmen/chashi");
	set("board_id", "tangmen_b");
	set("long", "����һ�����Ĵ����ŵ������Եı���.\n");
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}

