// /clone/board/tangmen_b.c

inherit BULLETIN_BOARD;

void create()
{
          set_name("Ѫ���ɵ������Բ�",({"board"}));
           set("location","/d/longmen/xuehepai/qixuetang");
          set("board_id", "xuehe_b");
         set("long", "����һ����Ѫ���ɵ������Եı���.\n");
	setup();
	set("capacity", 50);
	replace_program(BULLETIN_BOARD);
}

