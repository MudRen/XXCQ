//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "�ɻ���");
        set ("long", @LONG
�ɻ�����һ��Լ���˿��߲�����ʯ���ţ������Ƿ�Բ�����佻�Ϫ
��Ψһһ���Ŷ����������¾��ǰ���Ʈ���Ľ���佻�Ϫ��Ϫˮ�峺������
Ʈҡ�������������Ե�����С����������������佻������ˡ�"
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"westdown" : __DIR__"hhxroad1",
		"eastdown" : __DIR__"feihua",
       ]));

        set("outdoors", "xiao");
        setup();
}