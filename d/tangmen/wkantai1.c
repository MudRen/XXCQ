//wkantai1.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�����䳡��̨");
	set("long", @LONG
�������ŵ������䳡��̨����Ȼ���ڿ����������˵�����ﲻ��
��ѵ�λ�ã����������ǺȲ�������ĵط�����Ϊ��������ģ�ͨ��
�����ŵ������ӣ�����㣬��嶯��Ҳ���м��顣���棬��������
�����м俴̨��
LONG);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
		"south" : __DIR__"wkantai2",
	]));
	setup();
	replace_program(ROOM);
}