inherit BULLETIN_BOARD;

void create()
{
        set_name("���ֺ��¼ҹ�����",({"board"}));
        set("location","/d/wenjia/square");
        set("board_id", "wenjia_b");
        set("long", "����һ�鹩���ֺ��¼ҵ������Ե�ľ�ơ�\n");
        setup();
        set("capacity", 50);
        replace_program(BULLETIN_BOARD);
}
