//zoulang1��c             Ѫ����--����

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ѫ�����ڵص����ȣ������Ǵ���ʯ���ɵ����ӣ��������һЩ
����ͼ�����еĻ�����һЩ���ľ��Σ��ɼ�Ѫ���ɵ��ܹ��ɽ��������ˡ�
����Ѫ���ɵ��ӴӲ��������������˴˴��Եø�����ɭ�ֲ�������ʱ
����Ӱ�����Ʈ�������˲�������ֹ����
LONG);
	set("valid_startroom",1);
	set("outdoors","����");
	set("exits", ([
		"east" : __DIR__"gongfengtang",
		"westup" : __DIR__"qixuetang",
	]));
	setup();
}
