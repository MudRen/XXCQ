// xd.c
#include <ansi.h>

inherit ROOM;  

void create()
{
         set("short",HIB"С����"NOR);
         set("long",@long
��һ���ϰ�ȥ, ��������������������, ������һ����֪����С�����
���ϡ�������ľ���̣�ͤ����鿴������ȣ�����Ʈ��һ�����㡣�����һ��
��һ��͸������ˮ��ɽ�壬����С�ɱ��µ���ɫ��
long);
         set("exits", ([
             "south" : __DIR__"xs",                    
]));                                        
	set("outdoors", "����Ľ��");                         
         setup();
         replace_program(ROOM);
}
