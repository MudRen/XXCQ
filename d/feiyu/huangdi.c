// Room: huangdi.c
//Created by Atlus 1999.10.9
// Modified by Atlus 1999.10.9
// 

inherit ROOM;

void init();
int do_zhao(string);
int do_push(string arg);
void delete_served(object);

void create ()
{
        set ("short", "�ĵ�");
        set ("long", @LONG
������һƬ�ĵأ������Ѿ��ܾ�����ʹ���ˣ�Ұ�ݳ���һ��Խ��Խ��
�����������ͻȻ�㷢����ʱ��·�Ҳ����ˣ�
LONG);
        set("area","����");
        set("valid_startroom", 1);

        setup();
}

void init()
{
        add_action("do_zhao", "zhao");
	add_action("do_push", "push");
}

int do_zhao(string arg)
{

        object me;

        me = this_player();

        if ( !arg || arg != "·")
        {
                return notify_fail("��Ҫ��ʲô��\n");	
        }
		
        message_vision("$N�������ң���Ȼ�ҵ���һ��С·��\n",me);
        if( !query("exits/east") ) {
        set("exits/east", __DIR__"jzroad3");
        call_out("close_path", 3);
        }
        return 1;
        
}

int do_push(string arg)
{
        object me;
        if(!arg || arg=="")
        {
                write("ʲô��\n");
                return 1;
        }
        if( arg == "zacao" || arg == "�Ӳ�" || arg == "cao")
        {
        me = this_player();
        message_vision("$N����������Ϣϸ����������һ�ߵ��Ӳ��б������ĺۼ���\n���ǣ�$N�ƿ��Ƕ��Ӳݣ�һ����·������ǰ\n", me);
        if( !query("exits/southdown") ) {
        set("exits/southdown", __DIR__"tulu");
        call_out("close_path", 3);
        }
        return 1;
        }
        
}
void close_path()
{
        if( !query("exits/east") ) return;
        message("vision",
"һ��紵�����Ӳ��е�·�ֲ����ˡ�\n",
                this_object() );
                delete("exits/east");
        if( !query("exits/southdown") ) return;
        message("vision",
"һ��紵�����Ӳ��е�·�ֲ����ˡ�\n",
                this_object() );
                delete("exits/southdown");
}

