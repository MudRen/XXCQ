//By adx by snow 99-12-5

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"��ѩ�ϲ���"NOR);
	set("long",
"���߽�һ�䲻��ķ�����������ѩɽ���ϲ�������һ�㶼��������ͽ,\n"
 "�������ѧʲô�书�������������ϰѧϰ�书"+HIC"��xue jiaoxi xxxx����\n"NOR
"�����뿪�����Ժ���ֻ����ʦ��ѧ�书��������Ҫ�Ȱ�ʦ"+HIC"��bai xxxx��\n"NOR
 "�����Ҫ�뿪������ѩɽ�����ȵõ���ϰ��ͬ��"+HIC"(fight jiaoxi).\n"NOR
	);
        set("exits", ([
                "north":__DIR__"dating",
        ]));
        set("objects",([
                __DIR__"npc/jiaoxi":1,
                ]));
	setup();
        replace_program(ROOM);
}
