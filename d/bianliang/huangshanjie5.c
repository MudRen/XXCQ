// huangshanjie5.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "������");
	set("long", @LONG
վ������������ʹ���������������ԭ������¥�������ڽֵ���
�棬�������ϵľ�¥���������У��������˽���������·�Ķ������һ��
�������������ӣ���������һ�����ġ������֡�·�ı��洫���������
�������������Ǿ��ǹ㳡��
LONG);	
	set("valid_startroom",1);
	set("exits", ([
		"north" : __DIR__"huangshanjie4",
		"south" : __DIR__"guangchang",
         "west" : "/d/bianliang/jiulou/sanhelou",
		"east" : __DIR__"huang_dangpu",
	]));

	set("outdoors", "bianliang");

	set("area", "����");

	setup();

	replace_program(ROOM);
}
