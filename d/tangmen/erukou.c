//erukou.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�����䳡���");
	set("long", @LONG
�������ŵĶ����䳡��ڡ��ſ������һ�������ң��������䳡��
��������д�ÿ������������Ʊ��ˣ��·��Ǽ�����ʱ���Ժ�ն����İ�
��������������սʷ�ĻԻ͡�����Ķ��棬�Ƕ����䳡�Ŀ�̨��������
һ����ʯС·��
LONG);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
		"east" : __DIR__"ekantai2",
		"west" : __DIR__"nzlangn1",
	]));
	setup();
	replace_program(ROOM);
}