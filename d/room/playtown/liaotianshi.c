// Room: /d/playertown/liaotianshi.c ������
// Build 1999.12.10 bmw

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����һ������ͨ�ķ��䣬����ֻ�����صذ���һЩ������Ϣ����
��һ������������к��ſ��ˡ������ﵽ���ۼ���һȺȺ���ˣ��໥
����Ž����š��ڷ�����ұ���һ��С���䣬ż����һЩƣ�������
�ұߵķ�����ȥ��
LONG );
	set("no_fight", 1);

        set("exits", ([
                "north"  : __DIR__"miao",
        ]));
        setup();
        replace_program(ROOM);
}
