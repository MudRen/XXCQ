#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�����ٲ�");
        set("long", @LONG
���������ٲ��ˣ����������ˮ���Ӹ��ߵ�ɽ���������£�һ������
����������ʯ�����𴮴�ˮ�飬������������£����������ˡ����겻��
���ٲ�ʹ�������γ���һ����̶��̶���ˮ����Ȼ�ܼ������������ؾ���
���������ż����У����ﲻ����Ȼ��
LONG);
        set("valid_startroom",1);
        set("exits", ([
		"east" : __DIR__"pububian",
        ]));
        set("outdoors","����");
        setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
          object ob;
        object me;

          me=this_player();
          if (!arg || arg!="pubu")
              return notify_fail("��Ҫ��������ȥ��\n");
          message_vision("ֻ��$N����ȫ�������ٲ���Х��ȥ��\n",me);
          if ((me->query_skill("dodge",1)<101) || !(ob=present("xueyi",me)))
             {
          message_vision("ֻ��$N��Ҫ�����ٲ�ʱ�����ζٻ������ŵ�����̶������ȥ��\n",me);
          me->move(__DIR__"jiliu");
          return 0;
        }
          me->move(__DIR__"midao1");
          message_vision("ֻ��$N��һ��أ����˽�����\n",me);
          return 1;
}

