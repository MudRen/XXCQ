// Room: /welcome/houyuan.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"��ѩ��Ժ"NOR);
	set("long",
"������ѩɽ�ĺ�Ժ��Ժ����ֲ������滨�ܣ����������Ů���ӵ���Ϣ��\n"+
"����������е��ӵ���Ϣ�ҡ�Ժ������һ��ˮ��������������������\n"+
"����װˮ��"+HIC"��zhuang xxxx��������\n"NOR
	);
	set("exits", ([
	"west" :__DIR__"bingqiku",
	"east" :__DIR__"houting",
	"north" :__DIR__"nan-xiuxi",
	"south" :__DIR__"nv-xiuxi",
	"northwest" :__DIR__"liangong3",
	"southwest" :__DIR__"liangong4",
	]));
	set("resource/water", 1);
	set("outdoors", "welcome");
	setup();
}

int valid_leave(object me, string dir)
{       
	if ( ((dir=="south")||(me->query("gender")!="����")) &&
		((dir=="north")||(me->query("gender")!="Ů��")) )
	{
	return notify_fail ("�㿴������ߴ��䣡\n");
	}
        return ::valid_leave(me, dir);
}
