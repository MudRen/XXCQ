//eting.c		�Ĵ����š���ƫ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ƫ��");
	set("long", @LONG
���������Ƹ󶫲��ƫ����һЩ���ŵ���ϲ�������ﺣ����գ�
������̸�����ڰ������������Σ�����Ϫ����������ľ�дС�һ���
����������Ϣ������Ʈ��������е�����Ϊ֮һˬ��
LONG);
	set("exits", ([
			"west" : __DIR__"lianyunge",
	]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}