// /clone/board/news_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���ŷ�����", ({ "board" }) );
        set("location", "/d/wizard/newsroom");
        set("long", "����һ����ʦ�Ƿ������ŵķ����塣\n" );
        setup();
        set("capacity",200);
        replace_program(BULLETIN_BOARD);
}
