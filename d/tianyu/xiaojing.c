// Room: С��
// Date: by godzilla 1999.11.18

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ�����������ö���ʯ�̳ɵ�С����·��������������һ����ɽ
ʯ��ľ��׺�����С�������ʯ���ϣ�ž�žવķ�������������һ
�ԵĲݴ��ƺ���ʲô������һ��������æµ����ʲô��С����������
���졣
LONG );
        set("outdoors", "tianyu");
	set("exits", ([
	        "east" : __DIR__"qixuant", 
		"northwest"  : __DIR__"xiaojing1",
	]));
	set("objects",([
	        __DIR__"npc/puren1" : 1,
	        ]));
	setup();
	
}
void init()
{
	add_action("do_search","search");
	add_action("do_search","zhao");
}
int do_search(string arg)
{
	object ob,me;
	me=this_player();
	if(!arg||arg=="")
	return notify_fail("��ʲô��\n");;
	if(arg=="������")
	{
		if(me->query_temp("do_find_ce"))
		{
			message_vision("$N��ʼϸϸ�������ݴ���Χ������.....��������һ���������۵ĵط��ҵ���һ�����ӡ�\n",me);
                        ob=new(__DIR__"obj/huamingce");
                        ob->move(me);
                        me->delete_temp("do_find_ce");
                        return 1;
                }
                message_vision("$N�ĸ������˶������ң�����Ҳ��֪���Լ�����Ҫ��ʲô��\n",me);	
                return 1;
                 
        }               
                
}                 
	
        
