//wrukou.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�����䳡���");
	set("long", @LONG
�������ŵ������䳡��ڡ��ſ������һ�������ң��������䳡��
��������д�ÿ������������Ʊ��ˣ��·��Ǽ�����ʱ���Ժ�ն����İ�
��������������սʷ�ĻԻ͡���������棬�������䳡�Ŀ�̨��������
һ����ʯС·��
LONG);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
		"east" : __DIR__"nzlangn1",
		"west" : __DIR__"wkantai2",
	]));
	setup();
	replace_program(ROOM);
}