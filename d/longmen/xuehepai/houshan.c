//houshan��c             ���ź�ɽ

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
������Ѫ���ɺ�ɽ��������ɭ�ֲ������ܶ������������չ�Ҳ����ס
��������Ӱ�߲������к����������׺ݵ�Ŀ��ע�����㣬������ʱ������
��ɱ���㣬�Ͽ��뿪�����!
LONG);
	set("valid_startroom",1);
	set("exits", ([
		"southdown" : __DIR__"hsxiaolu4",
		"west" : __DIR__"zrping",
	]));
	set("outdoors","����");
	setup();
	replace_program(ROOM);
}