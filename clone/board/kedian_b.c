// /clone/board/kedian_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�����ջ���԰�", ({ "board" }) );
	set("location", "/d/beijing/kedian");
	set("board_id", "kedian_b");
	set("long", "������԰���Ҫ����������һ��������õģ��Ͻ���ˮ��\n" );
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}

