// /clone/board/news_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("�������Բ�", ({ "board" }) );
        set("location", "/d/welcome/wel1");
        set("long", "����һ����ǰ�����ֹ����ҵĿ������Եı��ӡ�\n" );
        setup();
        set("capacity",200);
        replace_program(BULLETIN_BOARD);
}
