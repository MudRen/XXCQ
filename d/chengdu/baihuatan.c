//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "�ٻ�̶");
        set ("long", @LONG
��������վ�İٻ�̶�ǻ����羰�����ġ��Ļ���֮һ��̶����ף�
ˮ�ļ����ɳ��ǣ�̶���ܰٻ�������ÿ�괺�Ķ���������̶����������
�����ǻ���С��������ͨ��佻�Ϫ��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"treeroad2",
		"southeast" : __DIR__"tulu2",
       ]));

        set("outdoors", "huayang");
        setup();
}