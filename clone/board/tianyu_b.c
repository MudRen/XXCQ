// /clone/board/tangmen_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���������Բ�",({"board"}));
        set("location","/d/tianyu/qianyuan");
        set("board_id", "tianyu_b");
       set("long", "����һ���������ɵ������Եı���.\n");
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}
