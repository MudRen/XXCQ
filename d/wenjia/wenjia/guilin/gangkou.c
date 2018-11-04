// Room: dukou.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

#include <ansi.h>

inherit ROOM;
void init();
int do_shang(string arg);
int arrived(object me,int stage);

string *around_msg = ({
        HIY "һ�����һ����ɽ�����������Ұ�Խ��Խ���Ǿ������������ɽ��\n\n" NOR,
        WHT "����Խ��Խ�������δ�˳���콭���º��У������Ļ�����������\n\n" NOR,
        CYN "��ˮ��������÷ǳ�������������ǰ���������һ���󽭣����Ǳ�����\n\n" NOR,
        HIG "���������Ļ�����ͣ�������������ĵ�ת���򣬴�ͷ��Ȼת���˱��������Ρ�\n\n" NOR,
        HIC "��ˮ�����ı伱�ˣ������Ϻ��е�Խ��Խ���������������ֱ߳�����һ��ɽ����\n\n" NOR,
        BLU "�������ɽ��ɽ�Ŵ�������һ��СС�Ķɿڡ�\n\n" NOR,
});

void create ()
{
        set ("short", "�ۿ�");
        set ("long", @LONG
�콭����Ψһ�ĸۿڣ������������������콭���������������п���
ȥ����������������������������ɽ�������������ֺ��¼ҵ��ܲ�������
����һ��ľ��(mupai)��
LONG);
        set("area","����");
        set("outdoors", "guilin");
        set("valid_startroom", 1);

	set("item_desc", ([
		"mupai" : "�пʹ�������ɽ����������(shang)����\n",
	]));

        set("exits", ([
                "northeast" : __DIR__"jiangdi1",
        ]));
        setup();
}

void init()
{
	add_action("do_shang", "shang");
}

int do_shang(string arg)
{
        object room,me;
        me=this_player();

        if(!arg || arg!="chuan")
               return notify_fail("��Ҫ��ʲô?\n");
         
        message_vision("$N�����ϵĴ���е�����ι���ʹ�ѽ!��\n", me);

        if( !(room = find_object("/d/guilin/fengfan")) )
		room = load_object("/d/guilin/fengfan");

        message_vision("���������Ľ�����������һ��ľ��ܵ����ϡ�$N�����ϴ���\n", me);
        me->move("/d/guilin/fengfan");

        call_out("arrived", 5, me,0);

        return 1;
}

int arrived(object me,int stage)
{
        object room;

        tell_object(me, around_msg[stage]);
        if( ++stage < sizeof(around_msg) ) {
                call_out( "arrived", 5, me, stage );
                return 1;
        } else
                me->reincarnate();

        if( room = find_object("/d/guilin/fengfan") )
        {
                me->move("/d/wenjia/gangkou");
                message_vision("��������ʻ�����ߣ��������һ��ľ�嵽���ϣ�$N����������\n", me);
                return 1;
        }

}
