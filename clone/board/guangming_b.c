// /clone/board/kedian_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����ջ���԰�", ({ "board" }) );
	set("location", "/d/bianliang/guangming");
	set("board_id", "guangming_b");
	set("long", "������԰���Ҫ����������һ��������õģ��Ͻ���ˮ��\n" );
	setup();
     set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}

