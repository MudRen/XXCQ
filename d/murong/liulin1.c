#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", GRN "������" NOR);
        set("long", @LONG
����ˮ��֮�ص����Ӳ��ݺᣬ��Ƭ�����ֱ�����һ��С���ԣ��������
Ʈ�ڣ������������衣ʱ��ʱ����һ��ֻ�������޴�����ǰ�ܹ��������Ǹ�
�õط���ǰ��С����·���޷����С�
LONG);
 
        set("no_sleep_room", 1);

        set("objects", ([
           __DIR__"npc/mmr" : 1,
        ]));       
        set("exits", ([
              "east" : __DIR__"hb2",
        ]));

        setup(); 
}
void init()
{
	object me = this_player();
	if(!(present("mengmian laoseng", environment(me) ) )
	&&  me->query_temp("mrb_see"))
	new(__DIR__"npc/mmr")->move(environment(me));
	if( present("liu tiao", environment(me)))
	destruct(present("liu tiao", environment(me)));
}                                                       

int valid_leave(object me, string dir)
{
        if (objectp(present("mengmian laoseng", environment(me))) && 
            dir == "east")
                return notify_fail("��������һ���죬��Ӱ����ͷ��Ծ������������ǰ��\n");
        return ::valid_leave(me, dir);
}