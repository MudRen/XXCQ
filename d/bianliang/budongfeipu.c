// budongfeipu.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "��������");
	set("long", @LONG
ת��һ��С��������ˮ�����������ֻ��һ��������Ƶ��ٲ���к��
�£�ˮ���ɽ����Ĺ�ˮ�����ɣ�εΪ��ۡ���ɽ���Ƶ����ң��������о�
�⣬���Ǳ������ĺá�

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"south" : __DIR__"huangkudajie10",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}
