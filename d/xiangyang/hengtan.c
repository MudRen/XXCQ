//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��ʯ��̲");
        set ("long", @LONG
����������ľ�ʯ��̲�ˣ�˵������һ������ʵҲ������һƬ��ͨ��
��̲��ֻ����Ϊ����һ���ʯ��ס�˰������棬�ű���Ϊ��ʯ��̲������
��ʯ���̲�ܽ������Գ���������ȥ�۾���
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"jiangpan2",
		"north" : __DIR__"jushi",
		"east" : __DIR__"jiangpan3",
	]));

        set("outdoors", "zigui");
        setup();
}