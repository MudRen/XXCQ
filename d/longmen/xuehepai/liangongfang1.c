//liangongfang��c         ����Ѫ����--������

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
������Ѫ���ɶ����������������ϱ�ĵط��ְ�������࣬ԭ����
��Ϊ���������ڵ��������ڹ����ķ��ľ��ң�Ѫ���ڹ�ǿ��������������
��������ȫ��������û�˸��ڴ˴�������
LONG);
        set("valid_startroom",1);
	set("exits", ([
		"west" : __DIR__"zoulang4",
	]));
        set("area", "����");
	setup();
	replace_program(ROOM);
}