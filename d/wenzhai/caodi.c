// caodi.c �ݵ�


inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
������һƬ�ݵأ��ݺ��̣���ǳ����Ȼ���ھ��������޼��������ĺ�
�á��ݼ�ɢ����һЩ�滨��΢�紵�����ҷ��˱ǡ�������ʱ���С�������
����������������һЩ��ͷ���İ�ɫ���۷��ڲݵ��Ϸ���������
LONG
        );
        set("valid_startroom",1);
        set("outdoors", "wenzhai");
        set("exits", ([
                "out" : __DIR__"damen",
                "east"  : __DIR__"chanting",
                "south" : __DIR__"dating",
        ]));

        set("objects", ([
                __DIR__"npc/mifeng" : random(5),
        ]));

        setup();
        replace_program(ROOM);
}
