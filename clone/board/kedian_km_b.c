// /clone/board/news_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ջ���Բ�",({"board"}) );
	set("location","/d/kunming/kedian");
	set("long","����һ������������ջ�Ŀ������ԵĲ��ӡ�\n");
        setup();
        set("capacity",200);
        replace_program(BULLETIN_BOARD);
}
