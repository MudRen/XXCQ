// ɽèADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",WHT"��ӭ����Сѩ����"NOR);
    set("long",
"���������Ĵ��ţ�̤���㽫������ѩɽ����һ��ѧϰ�������\n"
"�����漼�ܣ�����ǵöౣ���������"+HIC"(save)"NOR+",����������뿪��"+HIC"(quit)\n"NOR
",�����ĵط����Կ������ļ�"HIC+"(help)"NOR+"���㻹������ʱ��"HIC"(map here)"NOR"�鿴��ͼ\n"
"ף�������졣\n"
    );
        

        set("exits", ([
		"south": __DIR__"dating",
        ]));
        set("objects",([
                __DIR__"npc/jieyinshix":1,
                ]));

        set("no_fight", 1);
        setup();
}
int valid_leave(object me, string dir)
{       
         if ( dir=="south") {
		me->set("newbie",1);
	}
        return ::valid_leave(me, dir);
}