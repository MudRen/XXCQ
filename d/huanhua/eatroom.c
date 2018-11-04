// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��®����");
	set("long", @LONG
���ǽ�®�ķ��������ڵİ���ǳ��򵥣�ֻ�����Ŵ���Բ����Χ��
��Χ�ļ�ʮ��ľ�Ρ����ڽ�®��û�й̶��Ŀ���ʱ�䣬���Լ�����ʱ����
�����ڳԷ��������������һ��ľ�ţ�������ǳ����ˡ�������ļҶ���
�ҴҵĽ���������Ϊ�Է����˶����׷����ˣ��������˲���������Ҳ��
�������һЩ(serve)��
LONG
	);

	set("no_fight", 1);

	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"southyuan",
        "south" : __DIR__"churoom",
	]));

        set("objects", ([
                 __DIR__"npc/eatding": 1,]));

	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if (  (dir == "east")
	   && ( present("tang", this_player())
	        || present("chao fan", this_player()) ) 
	   && objectp(present("jia ding", environment(me))) )
	{
	 message_vision("�Ҷ���$Nһ���ֵ���ׯ���Ը�����ʳ���ô���������", me);
	 return notify_fail("\n");
	}

	return ::valid_leave(me, dir);
}
