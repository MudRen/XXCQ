// yanziwu.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",WHT"������"NOR);
         set ("long",@long
��������Ļ��������֮��, Ļ������Ϧ�մ�����ĺ���, �����ռ�ʽ΢, 
�������ȴһ��һ����⸴���ࡣ���书�������Ա�֮��, ��ʩ����, �˵�
ʮ��������
long);
         set("exits",([
        "north" : __DIR__"houyuan1",
        "south" : __DIR__"houting",
]));
        set("dest_room", "/u/beyond/workroom");
	set("objects",([
	__DIR__"npc/murong-fu" :1,
]));
        setup();
        replace_program(ROOM);
}
