// /clone/board/wiz_b.c

// inherit W_BOARD;
inherit BULLETIN_BOARD;

void create()
{
	set_name("��ʦ���Բ�", ({ "board" }) );
	set("location", "/d/wizard/wizard_room");
	set("board_id", "wiz_b");
	set("wiz_board",1);
	set("long", "����һ��ר����ʦʹ�õ����԰塣\n" );
	setup();
          set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}
