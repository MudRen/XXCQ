// yunjinlou.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",MAG"�ƽ�¥"NOR);
         set("long",@long
�ƽ�¥���踻��, һ�����û���ǿ�ȸ����,����������д��һ������(dui)��
long);
         set("item_desc", ([
             "dui" :	BLINK HIW "\t\t\t��"NOR   BLINK HIY"\t\t��\n"NOR
                         
                    	BLINK HIW "\t\t\tҶ"NOR   BLINK HIY"\t\t��\n"NOR
             
	                BLINK HIW "\t\t\t��"NOR   BLINK HIY"\t\tѩ\n"NOR
             
                     	BLINK HIW "\t\t\t��"NOR   BLINK HIY"\t\t��\n"NOR
                           
                     	BLINK HIW "\t\t\t��"NOR   BLINK HIY"\t\t��\n"NOR
]));                     
	set("valid_startroom", 1);
	set("exits",([
	"north" : __DIR__"houyuan",
	"south" : __DIR__"hxlou",
	"west"  : __DIR__"cl1",
]));
	set("objects",([
	__DIR__"npc/wang" : 1,
]));
	setup();
	replace_program(ROOM);
}
  
