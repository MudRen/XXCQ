// common_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("����ѩ������������", ({ "board" }) );
        set("location", "/d/shequ/jiaowai1");
        set("board_id", "fang_b");
        set("long",     "����һ���������Լ��µ����԰塣\n" );
        setup();
 set("capacity", 90)
;
        replace_program(BULLETIN_BOARD);
}
