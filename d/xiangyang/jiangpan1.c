//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��������");
        set ("long", @LONG
���ڳ������ϣ�����Ź�������������׳�ۡ�������ֵ������������
����������ǵĸ��˼Ҷ��˳������￴���ۣ���������ľ������ȫ���
���������۵������ۣ�������������⡣����������������ͷ��������
��һ�Һ�����
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"zgmatou",
		"east" : __DIR__"jiangpan2",
		"south" : __DIR__"heshen",
       ]));

        set("outdoors", "zigui");
        setup();
}