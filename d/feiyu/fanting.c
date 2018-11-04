// Room: fanting.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21

inherit ROOM;

void init();
int do_shake(string);
void delete_served(object);

void create()
{
	set("short", "����");
	set("long", @LONG
���Ƿ���ɽׯ�ķ��������ڵİ��費�ֻ࣬�Ǽ��Ŵ��ķ����͵ļ�
ʮ��ľ�ʡ��м������ڳԷ���������������һ��С����������ǳ����ˡ�
������ĵ����ǴҴҵĽ���������ǽ��д�ţ����Է������֣�shake hand)����
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
	set("objects", ([
                "/d/feiyu/npc/chuzi" : 1,
        ]));

       set("exits", ([
	          "north" :__DIR__"xiwuchang",
       ]));
       
	setup();
}
void init()
{
        add_action("do_shake", "shake");
}

int do_shake(string arg)
{

        object me;
        object chifan;

        if (!arg || (arg != "shou" && arg != "hand"))
        {
                return notify_fail("��Ҫ��ʲô��\n");	
        }
		
        me = this_player();	
        if( !objectp(chifan = present("chuzi", environment(me))) )
                return notify_fail("������֣�������Ǳ��������֣���������û�����㡣������Ҫ���������ˡ�\n");
	 	
        if( me->query_temp("fanmark") )
        {
                message_vision("���Ӷ�$N˵�����ոո����Ϲ��ˣ���ô������ˣ��µĻ�û���أ�\n", me);
                return notify_fail("");
        }

        message_vision("$N������Ǳ��������֣����ӿ첽�߹����к��㡣\n", me);
 
        chifan->serve_tea(me) ;

        me->set_temp("fanmark", 1);
        call_out("delete_served", 10, me);

        return 1;
}

void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("fanmark");
}


int valid_leave(object me, string dir)
{
        object *obj;
        int i;

        me=this_player();

        if (  ((dir == "north") || (dir == "south") )
                && ( present("zhu", this_player())
                || present("tang", this_player()) || present("kaoya", this_player()) ))
        {
        message_vision("$N��������涨�����ǲ��ܴ��������ģ����Զ��Ծ��İ������ȥ�Ķ������¡�\n", me);
        obj=all_inventory(me);
        for (i=0;i<sizeof(obj);i++){
                if (obj[i]->query("id")=="tang" || obj[i]->query("id")=="kaoya" ||
                    obj[i]->query("id")=="zhu" ) destruct(obj[i]);
                }
        }
        return ::valid_leave(me, dir);
}

