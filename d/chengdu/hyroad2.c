//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "����������");
        set ("long", @LONG
��վ�ڻ���������ڣ��������Ѿ�û�з����ˣ�ֻ��һ��·ͨ��һƬ
���ֶ�������Ƕ�ʮ�����ϵķ��ӱ������������ϵĻ���С����·
��������һ����վ�����治ʱ������˻����������һ����������Ҳ��ʱ
�ĳ����͵��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"hyroad1",
		"north" : __DIR__"hyyizhan",
		"east" : __DIR__"hyroad3"
       ]));

        set("outdoors", "huayang");
        setup();
}
