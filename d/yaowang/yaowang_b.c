// /clone/board/dali_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ҩ�������԰�", ({ "board" }) );
     set("location", "/d/yaowang/dating");
         set("board_id", "yaowang_b");
	set("long", "����һ����ҩ�������½��������԰塣\n" );
	setup();
	set("capacity", 300);
	replace_program(BULLETIN_BOARD);
}
