//lianyunge.c		�Ĵ����š����Ƹ�

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "���Ƹ�");
	set("long", @LONG
���������Ƹ�������һ�������������Ľ�����������ʮ����
����ÿ�������϶����������ĵ������롢���Ϭ�����ѵ���ʮ����
��ͬ���������ޡ��컨��������˸��پ�����ġ��ơ��֣�������̾
���ǵذ��Ͼ�Ҳʮ�ֱ���Ŀ��������ʥ���칬����������������̫
���Ͼ�������շ��ڵ�¯�ﰾ���ĵ��ֹ������ƾ�����Ʒ�����Ǹ�
���˾�����ǣ��ذ岢����Ϊ��Щ��̶���˿����͹��ƽ��������ʮ
��ƽ���������ڼ����һ�㣡
LONG);
	set("exits", ([	
			"east" : __DIR__"eting",
			"west" : __DIR__"wting",
			"north" : __DIR__"nzlang1",
			"south" : __DIR__"shuige2",]));
	set("objects", ([__DIR__"npc/tangyaoshun" : 1,]));
//	set("length",20);
	set("valid_startroom",1);
	set("area", "����");
	setup();
	replace_program(ROOM);
}