inherit ROOM;

#include <ansi.h>
void create()
{
      set("short","�ؿ�");
      set("long",@LONG
���ﱻ��ʱ���һ���ؿ���һ����������ָ��Ѫ���ɵ��Ӷ������ο�
���м�飬���տ��Թ���������ʿһ�ɲ���ͨ��������������ʿ�����ں���
�����������ۡ�������Ѫ���ɷ�ɽ�ˣ����ڽ��ϡ�
LONG);
	set("valid_startroom",1);
           set("renshu",0);
	set("objects",([
                 "/kungfu/class/xuehepai/huwei1" : 1,
	]));
	set("exits",([
                "west"  : __DIR__"guanka",
		"east"  : __DIR__"shanjiao",
	]));
	set("outdoors", "����");

	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam,party;
        myfam=(mapping)me->query("family");
        party=(mapping)me->query("party");

              if (me->query_temp("shouwei"))
                     return notify_fail("�������������������ܵ����߶���\n");
if (((myfam && myfam["family_name"] != "Ѫ����") || (!myfam && party)) && (dir=="east") )
        {
                if (present("huwei", environment(me)))
                        return notify_fail("����������ס��ǫ��˵����Ѫ�����Ѿ������ˣ����ݽ�����ʿ�������ڣ�\n���ǰ�ʦ�Ļ�"
                                + RANK_D->query_respect(me) +"�������ȥ�ɣ��������ûȤ��\n");
        }

        return ::valid_leave(me, dir);
}

void init()
{
         add_action("do_shouwei","shouwei");
}

int do_shouwei(object me)
{
         me=this_player();

              if (query("renshu")>=4)
              return notify_fail("�������ֻҪ�������ء�\n");
            if (!(me->query_temp("xhjob_start")))
                   return notify_fail("��û�б�ָ�ɵ�������������Ҫ������£�\n");
            if (me->query_temp("shouwei"))
                   return notify_fail("����������Ѫ���ɵĹؿ�ͨ����\n");
          message_vision(HIC"$N���Ӿ��񣬿�ʼ������ߵ�ÿһ�����ˡ�\n"NOR, me);

         me->apply_condition("xhquest", 6);
              add("renshu",1);
            me->set_temp("shouwei",1);
          return 1;
}
