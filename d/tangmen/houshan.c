//houshan.c		�Ĵ����š���ɽ

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
���������Ƹ��ɽ��������ɭ�ֲ����������ִ��������չ�Ҳ��
��ס��������Ӱ�߲������к����������׺ݵ�Ŀ��ע�����㣬������
ʱ��������ɱ���㣬�Ͽ��뿪����ɣ�
LONG);
	set("exits", ([
			"northdown" : __DIR__"shanshi1",
			"westdown" : __DIR__"exiaolu2",
			"eastup" : __DIR__"shandao1",
			"southdown" : __DIR__"shanshi6",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}