//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��������");
        set ("long", @LONG
���ڳ������ϣ�����Ź�������������׳�ۡ���γ�����������ƽ��
��������ۺͲʴ���⽭�棬���������쿪ʼ�ˡ���Ķ��������������
ͷ�����������������������ˡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"jiangpan4",
		"east" : __DIR__"zgmatou",
       ]));

        set("outdoors", "zigui");
        setup();
}