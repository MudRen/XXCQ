// menfang.c  �ŷ�
// mlf��ƣ�lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","��������");
	set("long",@LONG
"\n                          "HBBLU+HIR"����\n\n"NOR
    �����Ƿ����ܲ������Ĵ��ţ�����������������ͷ��ʯʨ�ӡ�������
����һ����ң����顰�������������֣��ҵ����Ҵ�����������������
�ų����ţ����ڷ��ζ������ӵܴ���Ǿ��ǵ��о�֮ͽ����������Ҳ����
�����֡�
LONG
	);
	set("outdoors","huafu");
	set("valid_startroom",1);
	set("exits",([
		"north" : __DIR__"huayuan",
	]));
	set("objects",([
		__DIR__"npc/qi" : 1,
	]));
//	set("no_clean_up",0);
	setup();
	replace_program(ROOM);
}


		
	
	
