// /clone/board/lpc_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ȼ��޸������¼��", ({ "board" }) );
	set("location", "/d/wizard/lpcroom");
	set("board_id", "lpc_b");
	set("long", "���λ��ʦ�������˵Ĺ��������﹫��������\n"+
		"��ǿ��ʦ֮�乤����һ���ԣ�\n" );
	setup();
	set("capacity",100);
	replace_program(BULLETIN_BOARD);
}

