// ɽèADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"��ӭ����Сѩ����"NOR);
	set("long",
"����������ĳ�����ɣ������Ȱ�"+HIC"(bai)"NOR+"��ʦ��������Ը���ѧϰ"+HIC"(xue)\n"NOR
"Ҳ����ͨ��������ʽ�������"+HIC"(du)"NOR+"��"+HIC"(study)"NOR+",Ҳ������ͬ�ŵ�ʦ�ֵ��ֽ̡�\n"
    );
        

        set("exits", ([
                "south":__DIR__"welx",
                "west" :__DIR__"wel1",
        ]));
        set("objects",([
                __DIR__"npc/jieyinshi3":1,
                ]));
        set("no_fight", 1);
        
	setup();
        replace_program(ROOM);
}
