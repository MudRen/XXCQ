// Room: ǰԺ
// Date: by godzilla 1999.11.18

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
Ժ�Ӳ�����ȱ�����޵����ɾ���Ժǽ�ǰ���һ�������ܣ�����
�Ϲ����˸�ʽ�����Ľ����Ա߻����Ž����õ����ߣ��ұ��и�С�ţ�
��ʱ�Ĵ����ﴫ�����������������һ��ƫԺ��
LONG );
        set("outdoors", "tianyu");
        set("valid_startroom", 1);
	set("exits", ([
	        "south" : __DIR__"qingshilu", 
		"north"  : __DIR__"dating",
		"west" : __DIR__"pianyuan",
		"east" :__DIR__"chufang",
	]));
	set("objects",([
	        __DIR__"obj/jia" : 1,
	        ]));
	create_door("east","ľ��","west",DOOR_CLOSED);
	setup();
        call_other("/clone/board/tianyu_b", "???");
}
