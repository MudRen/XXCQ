//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "�ɻ�����");
        set ("long", @LONG
���Ѿ����˳ɶ���������佻�Ϫ�ϣ���������Ƿ�Բ����֮�ڹ�佻�
Ϫ��Ψһһ���š��ɻ��š��������������佻����ҵģ���������̨�׾�
���ˡ�������һ����·��ͨ����С�򣬸��������ǳ�ȥ����������
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"westup" : __DIR__"feihuaqiao",
		"north" : __DIR__"fhroad1",
		"southeast" : __DIR__"tulu",
       ]));

        set("outdoors", "huayang");
        setup();
	replace_program(ROOM);
}
