#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ò���ֻ���������輸�����������ֻ�������������˯����
�������Ǹ�СԺ�ӡ�
LONG);
        set("exits", ([
              "south" : __DIR__"tangwu",
          "east" : __DIR__"shuifang",
              "north" : __DIR__"yuanzi",
        ]));
        setup(); 
      replace_program(ROOM);
}
