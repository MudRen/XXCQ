// /clone/board/tangmen_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("��������Բ�",({"board"}));
        set("location","/d/feiyu/qianting");
        set("board_id", "feiyu_b");
       set("long", "����һ���������������Եı���.\n");
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}
