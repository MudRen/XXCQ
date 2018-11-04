// Room: /d/shaolin/guangchang1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
    set("short", "ɽ�Ź㳡");
    set("long", @LONG
������������ǰ�Ĺ㳡�������㳡�ɴ�����ʯ�̳ɣ���Ϊƽ̹����
�������Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г��˳������㳡��Χ
�������ܵ������֣��Ľ��ϸ����˼���ʯ�����ּ�����Ϊģ������ǰ����
ǽ���ߣ��������ݣ�����һ�����������������ߵ����ɼľ��ͭ���š�
�Ϸ�һ����ң����ɷ�������š������¡��������֡���ǰ����������վ
�ż���ɮ�ˡ�
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"shijie11",
		"north" : __DIR__"smdian",
	]));

	set("outdoors", "shaolin");
	set("objects",([
        	"/kungfu/class/shaolin/tongzhi" : 1,
		"/kungfu/class/shaolin/tonghui" : 1,
	]));
	setup();
	"/clone/board/shaolin_b"->foo();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "������" ) && dir == "north")
	{
		if (me->query("shen") < 0)
		{
			if(objectp(present("tong zhi", environment(me))))
				return notify_fail("ͭ��˫��һ�񣬺�üŭĿ��˵�������аħ������������ҹ�����\n�Ժ��ٸ��߽�����һ��������ʱ�ʹ�����ǵĹ��ȣ�\n");
			else if(objectp(present("tong hui", environment(me))))
				return notify_fail("ͭ��˫��һ�񣬺�üŭĿ��˵�������аħ������������ҹ�����\n�Ժ��ٸ��߽�����һ��������ʱ�ʹ�����ǵĹ��ȣ�\n");
		}
		if (me->query("gender") == "Ů��")
		{
			if(objectp(present("tong zhi", environment(me))))
			{
	        		return notify_fail("ͭ�Ǻ�ʮΪ��˵������λŮʩ��������ذգ����´Ӳ��Ӵ�Ů�͡�\n");
			}
			else if(objectp(present("tong hui", environment(me))))
			{
				return notify_fail("ͭ�ۺ�ʮΪ��˵������λŮʩ��������ذգ����´Ӳ��Ӵ�Ů�͡�\n");
			}
		}	
		if(objectp(present("tong zhi", environment(me))))
		{
	       		return notify_fail("ͭ�Ǻ�ʮΪ��˵������λʩ����ذգ����²��Ӵ����ˡ�\n");
		}
		else if(objectp(present("tong hui", environment(me))))
		{
			return notify_fail("ͭ�ۺ�ʮΪ��˵������λʩ����ذգ����²��Ӵ����ˡ�\n");
		}
	}

	return ::valid_leave(me, dir);
}