// Room: houshan.c


inherit ROOM;

void create()
{
        set("short", "��ɽ");
        set("long", @LONG
�����Ǻ�ɽ��һ��Сƽ̨������һ�����˴��Ѿ���������翡���Զ��
�ط������и�С�������ߵ�ɽ·���쵽����Ѿ��������ˡ�
LONG );
        set("exits", ([ 
            "southdown" : __DIR__"jzroad3",
            "northwest"  : __DIR__"xiaohu",
            "northup"  : __DIR__"disanfeng",
		]));
        set("outdoors", "feiyu");

		setup();
        replace_program(ROOM);
}

