//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��������");
        set ("long", @LONG
���ڳ������ϣ�����Ź�������������׳�ۡ���γ�����������ƽ��
��������ۺͲʴ���⽭�棬���������쿪ʼ�ˡ���Ķ�����������ľ�
ʯ��̲��������ͨ��������ͷ��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"jiangpan1",
		"east" : __DIR__"hengtan",
       ]));

        set("outdoors", "zigui");
        setup();
}