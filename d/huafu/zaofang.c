// zaofang.c  �㷻
// made by lks

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","�㷻");
        set("long",
"��һ������һ��Ũ�ҵľ����˱Ƕ��������ݷ��������������������
���ǻ�����Ƶĵط����㷻��Ϊ��Ҥ�ͽ��ң���Ϊ����������֮�á���ʱ
��ֵ���ݷ����٣����������ر�æµ��\n"
	);
	set("exits",([
		"east"  : __DIR__"huayuan",
		"down" : __DIR__"gangyao",
		"enter"  : __DIR__"jiaoshi",
	]));
	set("valid_startroom",1);
	setup();
}

int valid_leave(object me,string dir)
{
            object ob;

            if ( (!(ob=present("gaoliangfan",me))) && (dir=="enter") )
            return notify_fail("��ԭ�ϻ�û���ã���ȥҲ�ǰ״\n");

            return ::valid_leave(me,dir);
}

