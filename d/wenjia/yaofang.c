// Room: yaofang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.3
// Added Find Yao
// 

inherit ROOM;

void init();
int do_zhao(string);

void create ()
{
        set ("short", "ҩ��");
        set ("long", @LONG
һ��ŨŨ��ҩζ�������������䡣���������ż���ҩ��һ
Щ�����ĽӶ�ҩ�ͽ�ҩ�ǿ����������ҵ��ġ�
LONG);
        set("area","����");
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

        if (!arg || (arg != "yao"))
	{
                return notify_fail("��Ҫ��ʲô��\n");	
        }
		
        write("���ҵ�һ����ҩ��\n");

        yao=new("/d/wenjia/obj/jinchuang");
        yao->move(this_player());

        return 1;
}

