
inherit ROOM;
void create()
{
        set("short", "��̶��");
        set("long", @LONG
���������Ȼ���ʡ�һ����ɫ���ٲ��������£�������ʯ�ϣ�����
һ����ˮ�������ڵ��Ƶ�ԭ�������̶��ˮ����Ȼ�ܼ������������ؾ�
�ǵ��������ż����С��������䲻����������������ˡ�
LONG );
        set("valid_startroom",1);
        set("outdoors","����");
        set("class","Ѫ����");
        set("exits", ([
                "east"  : __DIR__"hsxj2",
        ]));
        setup();
}

void init()
{
        add_action("do_jump","tiao");
}

int do_jump(string arg)
{
          object ob;
          object me;
            object *obb;
            int i;

          me=this_player();
          if (!arg || arg!="tan")
              return notify_fail("��Ҫ��������ȥ��\n");
          message_vision("ֻ��$N����ȫ��������̶���˽�ȥ��\n",me);
          if (ob=present("xuehe che",environment(me))  && me->query_temp("xueheche"))
{
obb=all_inventory(environment(me));
                        for(i=0; i<sizeof(obb); i++) {
                                        if (obb[i]->query("id")=="xuehe che") 
                                        destruct(obb[i]);
                        }

             me->set_temp("chong",1);
}
              me->move(__DIR__"jiliu");
          return 1;
}

