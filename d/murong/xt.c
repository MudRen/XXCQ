// xt.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"С��"NOR);
	set("long",@long
���߽����СС������, �����������һ����̴ľ�輸�ͼ�����������
�ӣ���̴ľ�Ĳ輸�ϰڷ��Ų���ͼ�ֻ���񱭣�ר���������á����̲�ס��
���������ϣ���ƣ�������ĵõ���ֵ���Ϣ��
long);
         set("exits",([
             "north" : __DIR__"cf",
             "west" : __DIR__"xj1",
]));
	set("objects",([
	__DIR__"npc/abi" : 1,
	__DIR__"obj/xiangcha" : 2,
]));
         setup();                     
         replace_program(ROOM);
}
