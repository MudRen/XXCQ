//ejiaowu.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�����䳡");
	set("long", @LONG
�������ŵĶ����䳡��һƬ����ƽ̹�Ŀյأ����ʺϱ����书��
��Ҫ��ƽ���������壬���Ŷ��ھ��еı����ᣬ��һ�����������
����С��ϳ����࣬�ŷ��˼��������ܡ��ϳ������棬������������
̨������ʱ���Ǿ��춯�صĺȲ�����ȫ���������
LONG);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
		"west" : __DIR__"ekantai2",
	]));
	setup();
	replace_program(ROOM);
}