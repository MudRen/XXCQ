//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG
��Ȼ�����������������Ǽҽ���Ǯׯ������������ϵ�Ӧ������·��
����ҵ���¥�ˣ�����С����������ڣ��������ķ���ǽҲ��Զ������
�������ص�����Ʒ����
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"zgnorth",
		"south" : __DIR__"chaoyang2",
	]));

        set("outdoors", "zigui");
        setup();
}