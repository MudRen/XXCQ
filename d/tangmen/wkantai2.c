//wkantai2.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�����䳡��̨");
	set("long", @LONG
�������ŵ������䳡��̨����̨�ϳ��˼�����λ�⣬�м�������
�Ž��������̫ʦ�Ρ��ۿ�������������λ�ã����������̨�ϡ�
��Ȼ���������ִ�������Ȩ���ǵ���λ��Ҳ�����������վ�ڿ�̨
�ϣ���־��������������棬�������䳡���ϱ�����һ����̨������
�Ƕ����䳡����ڡ�
LONG);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
		"east" : __DIR__"wrukou",
		"north" : __DIR__"wkantai1",
		"south" : __DIR__"wkantai3",
	]));
	setup();
	replace_program(ROOM);
}