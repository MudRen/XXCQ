// Room: luoshenling.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
������Ƿ�����������֮һ�������롱�ˡ����Ը��ʵ�ɽ���ֻ��һ
��ɽ�����������롱�Ƿ������Ķ����ܰ��ڣ�һֱ��Ϊ��������ʵ�����
��������һֱ������ʢ������Ϊ�ڡ���ֹ�ء�֮ǰ�����ԶԷ�������λ��
������ȫ����������
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        set("objects", ([
		__DIR__"npc/feiyudizi" : 2,
        ]));

        set("exits", ([
		"northdown" : __DIR__"shanlu3",
		"southdown" : __DIR__"shanlu4",
	]));
        setup();
}

void init()
{
        object me = this_player();
        if (me->query_temp("feiyutask/given")) me->set_temp("di4mark", 1);
        return;
}