// zoulang1.c ����1
// mlf ���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
	 ��ò������߳�����ǰ���Ȼ���ʣ�����һ����ΡȻ�������Ǿ�
�Ƿ��ζ��������ͷ֮һ�ģ��������컨�ݷ��ճ��칫֮����ֻ�л�����
�ĵ�����Ӳ������ɳ���˵ء�
LONG
	);
	set("outdoors","huafu");
	set("valid_startroom",1);
	set("exits",([
		"west" : __DIR__"huazhen4",
		"north" : __DIR__"neitang",
	]));
	setup();
	replace_program(ROOM);
}
