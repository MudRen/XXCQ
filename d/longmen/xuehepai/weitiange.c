//weitiange��c  by baby

#include <room.h>

inherit ROOM;

void create()
{	
	seteuid(getuid());
	set("short", "Σ���");
	set("long", @LONG
������Σ����ǻ�Σ¥֮�����������Ը��Ƨ�����壬���Դ˴���
������ǰ����ˣ�Σ���ش����±ߣ����Եø���Ӱ���Ⱥ������˴���
����ã�Ѥ����ʣ��������ƣ��峾���ס����ò��ٵ����ڴ�����Զ����
������Ϧ����ʱ������ڴ�����ɽ��������
LONG);	
	set("objects",([
		"/kungfu/class/xuehepai/hua" : 1,
	]));
	set("valid_startroom",1);
	set("exits",([
		"west" : __DIR__"xuezhutang",
		"south" : __DIR__"zoulang4",
	]));

	setup();
	replace_program(ROOM);
}
