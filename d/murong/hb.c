// hb.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",GRN"����"NOR);
         set("long",
"�׻�˵��"+BLINK HIC+"��������, �����պ�"+NOR+"���������Ǵ��������"+BLINK HIM+"̫��"+NOR+"�������̲���\n"
"Ư��һҶҶ��"+BLINK HIW+"С��"+NOR+", һ�����ö���С�������ź��ϵ���粻ʱƯ����Ķ��С�\n"
);
         set("outdoors","����Ľ��");      
         set("exits", ([
             "east" : __DIR__"hb1",
	     "west" : "/d/suzhou/qingshidadao",
]));
         setup();
         replace_program(ROOM);
}
