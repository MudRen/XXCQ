//qilingbang��c            

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "Ȩ������̳");
	set("long", @LONG
������Ȩ�������̳,����Ȩ�����صء�Ϊ��ֹ�����Ϯ��Ҫ���˵�
�ؿ����ء�������һ��ׯ�أ��ֺܵ��ŵĽ����������ú�ᣰ������Եü�
Ϊɭ�ϣ������ϵ��������緢�ġ��������¡��ĸ�����.
LONG);
	set("exits", ([	
        	"north" : __DIR__"zhuang",
        	"south" : __DIR__"damen",
	]));
        set("objects",([
          __DIR__"npc/yan" : 1,
          __DIR__"npc/yu" : 1,
          __DIR__"npc/zuo" : 1,
       ]));
	setup();
	replace_program(ROOM);
}
