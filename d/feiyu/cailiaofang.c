// Room: cailiaofang.c
//Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 

inherit ROOM;

void init();
int do_zhao(string);
int do_open(string arg);
void delete_served(object);

void create ()
{
        set ("short", "���Ϸ�");
        set ("long", @LONG
�����Ƿ����������񷿼䡣����ʮ�ֻ谵��ֻ����һ������������
�ܶ��ƿƿ�޹޺ʹ���ӣ�һЩƿ����������Ѿ�ĥ�ɷ�ĩ��ҩ�ġ�����
һЩ���߰���Ķ������Ҷ���ǽ��������Ӧ�ÿ����ҵ�һЩ���õĶ���(zhao)��
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "south" : __DIR__"xiwuchang",
        ]));

        set("objects", ([
                       __DIR__"npc/guanshi" : 1,
        ]));

		setup();
}

void init()
{
        add_action("do_zhao", "zhao");
	add_action("do_open", "open");
}

int do_zhao(string arg)
{

        object yaocai;
        object me;

        me = this_player();

        if ( !arg || arg != "yaocai")
        {
                return notify_fail("��������ҵ��Ķ���Щҩ�ģ�\n");	
        }
		
        if( me->query_temp("mark") )
        {
                message_vision("$N�ұ����������䣬����û��ʲô���֡�\n", me);
                return notify_fail("");
        }

        write("���ҵ�һ��ҩ�ġ�\n");
        me->set_temp("mark", 1);
        call_out("delete_served", 30, me);

         yaocai=new(__DIR__"obj/yaocai");
        yaocai->move(this_player());

        return 1;
}

int do_open(string arg)
{
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "guizi" || arg == "����" || arg == "gui")
        {
        me = this_player();
        message_vision("$N���˹��ӣ�һ��ù�ĳ�ζ�˱Ƕ�����$N��Ϣϸ����������һ��ͨ�����ҵ�·��\n", me);
        if( !query("exits/northup") ) {
        set("exits/northup", __DIR__"mishi");
        call_out("close_path", 3);
        }
        return 1;
        }
        else
        {
                write("�޷���"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/northup") ) return;
        message("vision",
"�µ�һ���������ֹ����ˡ�\n",
                this_object() );
                delete("exits/northup");
}

void delete_served(object me)
{
      if ( objectp(me) ) me->delete_temp("mark");
}
