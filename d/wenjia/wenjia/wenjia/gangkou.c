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
        HIC "�����Ű��������κ��У��Ա������ɽ��Ҳ��������ʧ�ˡ�\n\n" NOR,
        HIG "��ˮ��������÷ǳ�������������ǰ���������һ���󽭣�����������\n\n" NOR,
        CYN "���������Ļ�����ͣ�������������ĵ�ת���򣬴�ͷ��Ȼת�������������Ρ�\n\n" NOR,
        WHT "ǰ��Ľ�ˮ�����˷��������������ĺ��з�������ת�������콭��\n\n" NOR,
        HIY "һ�����һ����ɽ�����������Ұ�Խ��Խ���Ǿ������������ɽ��\n\n" NOR,
        GRN "������������ɽˮ��ͬʱ�����ֱ߳�����һ�����򣬹�����\n\n" NOR,
        BLU "������������󣬶ɿڳ�������ǰ��\n\n" NOR,
});

void create ()
{
        set ("short", "�ۿ�");
        set ("long", @LONG
��������Ψһ�ĸۿڣ����������������������������콭�����п���
ȥ�����֡��콭�����ǹ��֣���������佻������ڵأ�Ҳ�ǵ��Ĵ��ıؾ�
֮·����������һ��ľ��(mupai)��
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("item_desc", ([
                "mupai" : "�пʹ��������򣬿�����(shang)����\n",
        ]));

        set("exits", ([
                "east" : __DIR__"shandi",
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

        call_out("arrived", 5, me);

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
                me->move("/d/guilin/gangkou");
                message_vision("��������ʻ�����ߣ��������һ��ľ�嵽���ϣ�$N����������\n", me);
                return 1;
        }
}

