
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
�������������ˮ��������Ȼ���ж��졣������Ѫ����ǰ�ε�
ʮһλ���ŵ�����֮�أ�����Ѫ���ɵĴ�ͳ��Ϊ�˲���Ѫ���ɵ���ѧʧ
������ȥ���Ұɣ�˵��������ʲô������������
LONG );
        set("valid_startroom",1);
        set("class","Ѫ����");
       set("exits",([
                "east" : __DIR__"pubulei1",
        ]));
//        set("no_clean_up"�� 0);
        setup();
}

void init()
{
        add_action("do_jump","tiao");
}

int do_jump(string arg)
{
        object me;

        me=this_player();
        
        if (!arg || arg!="out")
                return notify_fail("��Ҫ����������\n");
        message_vision("$N����һԾ�����˳�ȥ��\n",me);
        me->move(__DIR__"pubu");
        message_vision("$NͻȻ���ٲ��д��˳�����\n",me);   
        return 1;
}

