//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "��������");
        set ("long", @LONG
���ڳ������ϣ�����Ź�������������׳�ۡ����ڹ��˾�ʯ��̲����
ˮ����ļ���������Ҳû��ʲô��ֻ�ˡ����������������ľ�ʯ��̲��
��������������ͷ�ĳ������ϣ�����һ����·ͨ�򼸻��˼ҡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"hengtan",
		"east" : __DIR__"jiangpan3",
		"south" : __DIR__"tulu1",
       ]));

        set("outdoors", "zigui");
        setup();
}