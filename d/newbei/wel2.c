// ɽèADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"��ӭ����Сѩ����"NOR);
	set("long",
"�������Ӷ��˿�����"+HIC"(eat xxxx)"NOR+"ָ��Զ��������˻�������"+HIC"(drink xxxx)"NOR+"\n"
"ָ���ˮ�������ж����������"+HIC"(get xxxx��get all)"NOR+"����������Ȼ������û���ȥ\n"
"��"+HIC"(buy xxxx)"NOR+"ȥ��Щ����Ҫ�Ķ�������Ҳ���԰��㲻�õĶ���������"
HIC"(sell)"NOR+"�����\n"
"�����ˣ�����˯��һ��"+HIC"(sleep)"NOR+"����Ȼ������ҵ���˯���ĵط���\n"
);
        
        set("exits", ([
                "south":__DIR__"wel3",
        ]));
        set("objects",([
                __DIR__"npc/jieyinshi2":1,
                ]));
	set("no_fight", 1);
        
	setup();
        replace_program(ROOM);
}
