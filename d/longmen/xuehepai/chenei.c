//Ѫ�ӳ���

#include <room.h>
inherit ROOM;
void create ()
{
  set ("short", "Ѫ�ӳ���");
  set ("long", @LONG
��Ȼ������˻����������콵��Ѫ����֣�ŭ�Ľ������ӿ����Ѫ��
�������Ըо���Ѫ��֮�У���һ�ɱ��˵Ŀֲ���һ�ɱ��˵�����֮������
ͨ�˸����ܲ��ˡ���Ѫ������ʺ�ɫ�ε�ӳ��ѩ���ϣ�����һ�����˵�
���Ƴ���Ѫ��������������һƬ��������ϡ�Ĺ������㷢�ֳ������ƺ�
����(zi)�
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "zi" : "����ǧ������Ѫ������ѧ�ľ������㲻��һ���ϲ����æ��������ʼ��˼(think)����.\n",        
]));
  
  setup();
}

void init()
{
        add_action("do_study", "think");
        add_action("do_jump", "tiao");
}

int do_study(string arg)
{   
   object me=this_player();
   int jingli_cost, qi_cost;
   if( !arg || (arg != "zi"))
     return notify_fail("��Ҫѧʲô��\n");
   if( me->is_busy() )
     return notify_fail("��æ�ĺܣ����й���ȥѧϰ��\n");
   if( me->is_fighting() )
     return notify_fail("��ѧ�������������ˣ�\n");
   if( (int)me->query_skill("literate", 1) < 100)
     return notify_fail("�㿴�˰���Ҳ����������̵���ʲô��\n");
   if( (int)me->query_skill("yiqiguan-riyue", 1) < 150)
     return notify_fail("����ڹ��ķ���̫�ͣ����������������ѧ��\n");
if( ((int)me->query_skill("yiqiguan-riyue", 1) >= 250) && (me->query_skill("tao",1)>=250))
     return notify_fail("�㶨�����˻ᣬ���Ѿ�ȫ�������ˡ�\n");
   
   jingli_cost = 80 - (int)me->query_int();
   if( (int)me->query("jingli") < jingli_cost )
     return notify_fail("������ͷ�����ͣ�����Ϣ��Ϣ�ˡ�\n");

   qi_cost = 80 - (int)me->query_con();
   if( (int)me->query("qi") < qi_cost )
     return notify_fail("�����ڻ�������������Ϣ��Ϣ�ˡ�\n");

   
   me->receive_damage("jingli", jingli_cost);
   me->receive_damage("qi", qi_cost);
   
        if( (int)me->query_skill("yiqiguan-riyue", 1) < 250)
   me->improve_skill("yiqiguan-riyue", 50);
      if ((random(10)<3) && (me->query_skill("tao",1)<250)) {
   me->improve_skill("tao",50);
    write("��ĵ�ѧ�ķ������ˣ�\n");
    }

   write("��ڤ˼���룬��ȫ�����ڳ��ϵ�������ѧ֮�У����һ�������½����ˡ�\n");

   tell_room( environment(me), me->name() + "˫�ֻ�����ȥ����֪�ڱȻ�ʲô��\n", ({me}));

   return 1;
}


int do_jump(string arg)
{
          object me;
           object *obb;
           int i;

          me=this_player();
          if (!arg || arg!="out")
              return notify_fail("��Ҫ��������ȥ��\n");
          message_vision("ֻ��$N���˳�ȥ��\n",me);
        obb=users();
        for(i=0; i<sizeof(obb); i++) {
        if (obb[i]->query_temp("xueheche"))
        {
                me->move(environment(obb[i]));
            message_vision("ֻ��$N��Ѫ�ӳ�������������\n",me);
            return 1;
        }
        }
                 me->move("/d/longmen/xuehepai/xueheting");

          message_vision("ֻ��$N��Ѫ�ӳ�������������\n",me);
          return 1;
}

