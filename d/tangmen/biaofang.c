//biaofang.c		�Ĵ����š��ڷ�

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������ŵİ�������һ̤�����ű�е�һ������ӭ����������
�����еļ����޴��������Ŀ�����������������������ţ�������
�������ڸߣ����ŵ����ڸ�����������ȫ���ע�Ĵ�����ʲô��
LONG);
	set("exits", ([
			"southeast" : __DIR__"houroad3",
	]));
	set("objects", ([__DIR__"npc/tangbiao" : 1,]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}