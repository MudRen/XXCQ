//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "�ɻ�����");
        set ("long", @LONG
�������վ���Ĵ�佻�Ϫ�ϣ���Ķ����Ƿ�Բ����֮�ڹ�佻�Ϫ��Ψ
һһ���š��ɻ��š�����������һ����ʯ�ף�����ʯ����ȥ�Ϳ��Ե�佻�
�����ˡ����ﻹ������Ϫ���ϱ���ȥ������Ϫ����һЩ佻���Ѿ����ϴ��
�������������������˶�������
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"westup" : __DIR__"hhroad",
		"eastup" : __DIR__"feihuaqiao",
		"north" : __DIR__"hhxroad3",
		"south" : __DIR__"hhxroad2",
       ]));

        set("outdoors", "xiao");
        setup();
}