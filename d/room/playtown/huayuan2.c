// Room: /d/playertown/huayuan2.c ��԰
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
������һ����שС���ϣ����������������������������������
�м����洬���ڴ��棬����ǻ���س��Ÿ裬����һ�������������
�������ϱ�����һƬƬ���̵Ĳ�ƺ�����漸�Է����������ǣ���ͷ
�����ţ�ż��������һ��ɬЦ��
LONG );
        set("outdoors", "playertown");
//      set("no_clean_up", 0);
        set("exits", ([
                "east"  :	__DIR__"huayuan3",
                "south"	:	__DIR__"huayuan1",
        ]));
        setup();
        replace_program(ROOM);
}
