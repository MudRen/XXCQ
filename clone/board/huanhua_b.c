// /clone/board/kedian_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("佻���®���԰�", ({ "board" }) );
	set("location", "/d/huanhua/tingyudoor");
	set("board_id", "huanhua_b");
	set("long", "������԰���Ҫ����������һ��������õģ��Ͻ���ˮ��\n" );
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}