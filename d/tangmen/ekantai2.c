//ekantai2.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "�����䳡��̨");
	set("long", @LONG
�������ŵĶ����䳡��̨����̨�ϳ��˼�����λ�⣬�м�������
�Ž��������̫ʦ�Ρ��ۿ�������������λ�ã����������̨�ϡ�
��Ȼ���������ִ�������Ȩ���ǵ���λ��Ҳ�����������վ�ڿ�̨
�ϣ���־����������Ķ��棬�Ƕ����䳡���ϱ�����һ����̨������
�Ƕ����䳡����ڡ�
LONG);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
		"west" : __DIR__"erukou",
		"north" : __DIR__"ekantai1",
		"south" : __DIR__"ekantai3",
//Ϊ��λ����ʾ�ĺã����ﲻӦ��ͨ����䳡��ͨ��
		"east" : __DIR__"ejiaowu",

	]));
	setup();
	replace_program(ROOM);
}