// Room: yaofang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;

void init();
int do_zhao(string);
void delete_served(object);

void create ()
{
        set ("short", "ҩ��");
        set ("long", @LONG
һ��ŨŨ��ҩζ�������������䡣���������ż���ҩ��һЩ������
�Ӷ�ҩ�ͽ�ҩ�ǿ����������ҵ��ġ�
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "west" : __DIR__"bingqifang",
        ]));

        set("objects", ([
                __DIR__"npc/wenjiadizi" : 1,
        ]));

        setup();
}
void init()
{
        add_action("do_zhao", "zhao");
}

int do_zhao(string arg)
{

        object yao;
        object me;

        me = this_player();	

        if (!arg || (arg != "yao"))
        {
                return notify_fail("��Ҫ��ʲô��\n");	
        }
		
        if( me->query_temp("marks/served") )
        {
                message_vision("�¼ҵ����ú����ı����$N˵�����ող�����һ��ҩ����ô����Ҫ���滳������ҩ��ʲô����$N������˼���������֡�\n", me);
                return notify_fail("");
        }

        write("���ҵ�һ����ҩ��\n");
        me->set_temp("marks/served", 1);
        call_out("delete_served", 60, me);

        yao=new("/d/wenjia/obj/jinchuang");
        yao->move(this_player());

        return 1;
}

void delete_served(object me)
{
      if ( objectp(me) ) me->delete_temp("marks/served");
}

