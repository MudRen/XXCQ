// hongniang.c ����
// honest create

#include <ansi.h>

inherit NPC;

int do_hunli();

int do_qingtie();

int do_begin();

int do_jz();


void create()
{
        set_name( HIR"����"NOR, ({ "hong niang", "hong" }));
        set("long", 
                "����һ�����úܺÿ���С���\n"
            );
        set("gender", "Ů��");
        set("age", 16);
        set("no_clean_up",1);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("combat_exp", 3000);
        set("shen_type", 1);
        set("inquiry", ([
                "����"    : (: do_hunli :),
                "����"    : (: do_qingtie :),
                "��ʼ����": (: do_begin :),
                "���"    : (: do_jz :),
        ])); 
        setup();

}
int do_hunli()
{ 
        object me,obj,ob;

        me=this_player();

        ob=this_object();

        if(!me->query("couple/have_couple")) 
          {
            say ("����ҡҡͷ˵:���㻹û����ء���\n");
            return 1;
          }

        obj = find_player(me->query("couple/couple_id"));

        if(!obj || (!wizardp(me) && !me->visible(obj)))
          { say ("����ҡҡͷ˵:����İ������ڲ���....��\n");
            return 1;
          }

        if(!present((string)obj,environment()))
          {
            say("����ҡҡͷ˵:��"+obj->query("name")+"���ڲ��������\n");
            return 1;
          }

        if (me->query("marry_ok")) 
         { 
          say("����ҡҡͷ˵:�����Ѿ����й������ˣ�����Ҫ����\n");
          return 1;
         }

        say (HIW "���︣�˸�˵:����λ�����ϲ���Ե��Ѷ�λ�Ļ������������֡���\n" NOR);

        say (HIB "��������"+(string)me->query("name")+"��"+(string)obj->query("name")+"�����ߵ���һ�����صĵط���\n" NOR);

        me->move("/d/bianliang/hongniang-zhuang");
 
        obj->move("/d/bianliang/hongniang-zhuang");

        ob->move("/d/bianliang/hongniang-zhuang");

        me->set("marry_ok",1);
 
        obj->set("marry_ok",1);

        ob->set("xingren1",me->name());

        ob->set("xingren2",obj->name());

        say (HIR "�����������һЦ˵������������ʲô���أ�����˾�����Ҫ"+HIW+"����"+HIR+"�ɡ���\n" NOR );

        return 1;
}

int do_qingtie()
{
       object me, tie, ob, *all, ke, ma;
       
       int i;

       me=this_player();

       ob=this_object();
       
       all = users();
      
       if (ob->query("qingtie")) 
       {
        say ("����˵���������Ѿ������ˡ���\n");
        return 1;
       }

       if (!(me->query("marry_ok"))) 
        { 
          say ( (string)me->query("name")+"�㲻������Ҫʲô������\n" );
          return 1;
        }

       
       message_vision(HIW "$N�������֣������İ׸������������ž�������ȥ��\n" NOR,this_object()); 

       for(i=0; i<sizeof(all); i++) 
        {
          ke = all[i];

          if ( (string)ke->query("id") !=(string)me->query("id") 
                 && (string)ke->query("id") != (string)me->query("couple/couple_id")) 

              { tie =clone_object(__DIR__"obj/qingtie");
                tie->set("name",HIR+(string)me->query("name")+"��"+(string)me->query("couple/couple_name")+"�Ľ������" NOR);
                tell_object(ke,HIR"һֻ�׸�ɵ������ϣ�������һ��������Ȼ������ˡ�\n\n"NOR); 
                tie->move(ke);}
        }

       ob->set("qingtie",1);

  ma=clone_object("nv1");
   
       ma->move("/d/bianliang/guangchang");

       say(HIY "������Цһ��˵�������˵����˾͸�����һ�������Ǿ͡���ʼ���񡻡���ʼǰ�����ӿ�Ҫ����硻һ��ม���\n" NOR);

       return 1;
}

int do_begin()
{
       object me,ob,obj,check;

       me = this_player();

       if(!(obj = find_player(me->query("couple/couple_id")))) return 0;

       ob = this_object();
       
       if (me->query("gender")!="����") 
 
          { check = me; }
         
         else { check = obj; }

       if (!(check->query("dress_ok"))) 
         { 
           say(HIC "����Գ�Ц�����������ӻ�û�������ô�ļ�������\n" NOR);
           return 1;
         }
 
       message("shout", HIR "�����񡿣�˾�Ǹ߽У���" + me->query("name") + "��" 
         +obj->query("name") + "�������ڿ�ʼ����\n" NOR,users());

       call_out("ke1", 3, ob);
   
       return 1;
} 
            
int do_jz()
{     
       object me,obj,check,dress;
     
       me = this_player();

       if(!(obj = find_player(me->query("couple/couple_id")))) return 0;
       
       if (me->query("gender")!="����")
          
          { check = me; }
       
         else { check = obj; }
       
       if (check->query("dress_ok")) 
         { 
           say ("����̾�˿���˵�����ҿ�ֻ��һ��ױ�¡���\n");
           return 1;
         }

       if ( me->query("gender")=="����")

       { 
          dress=clone_object(__DIR__"obj/clasp");
          dress->move(obj);
          dress=clone_object(__DIR__"obj/marry_dress");
          dress->move(obj);
          dress=clone_object(__DIR__"obj/bracelet");
          dress->move(obj);
          message_vision(HIW "$N�������֣�һλ����С��������һ��ױ�¡�\n" NOR,this_object()); 
          message_vision(HIB "$N��$n˵�����ӿ�Ҫ�úô��һ�¡�\n" NOR,this_object(),obj); 
          message_vision(HIY "$N��$nһֻ�����Ρ�\n" NOR,this_object(),obj); 
          message_vision(HIW "$N��$nһ����ɫ��ɴ��\n" NOR,this_object(),obj); 
          message_vision(HIG "$N��$nһֻ�������\n" NOR,this_object(),obj); 
          obj->set("dress_ok",1);
          message_vision(HIY "$N��$n˵�����촩�����ɡ���\n" NOR,this_object(),obj); 
       }
       else
        {
          dress=clone_object(__DIR__"obj/clasp");
          dress->move(me);
          dress=clone_object(__DIR__"obj/marry_dress");
          dress->move(me);
          dress=clone_object(__DIR__"obj/bracelet");
          dress->move(me);
          message_vision(HIW "$N�������֣�һλ����С��������һ��ױ�¡�\n" NOR,this_object()); 
          message_vision(HIB "$N��$n˵�����ӿ�Ҫ�úô��һ�¡�\n" NOR,this_object(),me); 
          message_vision(HIY "$N��$nһֻ�����Ρ�\n" NOR,this_object(),me); 
          message_vision(HIW "$N��$nһ����ɫ��ɴ��\n" NOR,this_object(),me); 
          message_vision(HIG "$N��$nһֻ�������\n" NOR,this_object(),me); 
          me->set("dress_ok",1);
          message_vision(HIY "$N��$n˵���������ӿ촩�����ɡ���\n" NOR,this_object(),me); 
        }
      return 1;

}


int ke1(object ob)
{
         string xingren1,xingren2;

         xingren1= (string)ob->query("xingren1");

         xingren2= (string)ob->query("xingren2");

         ob = this_object();

         message("shout", HIR "�����񡿣�˾�Ǹ߽У���һ����ء�\n" NOR,users());

         say ("\n"+ HIW + xingren1 + "��" + xingren2 + "�������һ��ͷ��\n" NOR); 
    
         call_out("ke2",3,ob);

         return 1;
}

int ke2(object ob)
{
        string xingren1,xingren2;

        xingren1= (string)ob->query("xingren1");

        xingren2= (string)ob->query("xingren2");

        ob = this_object();

        message("shout", HIR "�����񡿣�˾�Ǹ߽У������ݸ��á�\n" NOR,users());
  
        say ("\n"+HIB + xingren1 + "��" + xingren2 + "�Ը�λ��ʦ����һ��ͷ��\n" NOR);

        call_out("ke3",3,ob);
 
        return 1;
}
int ke3(object ob)
{
        string xingren1,xingren2;

       xingren1= (string)ob->query("xingren1");

       xingren2= (string)ob->query("xingren2");

       ob = this_object();

       message("shout", HIR "�����񡿣�˾�Ǹ߽У������޶԰ݡ�\n" NOR,users());

       say ("\n"+HIY + xingren1 + "��" + xingren2 + "�����������໥�԰ݡ�\n" NOR);
    
       call_out("sanhua",3,ob);
    
       return 1;
}
    int sanhua(object ob)
{   
       object flower;
    
       message("shout", HIR "�����񡿣�˾�Ǹ߽У�����ͯɢ����\n" NOR,users());
   
       message("shout", HIR "��������������һ���ͷ׵Ļ��ꡣ\n\n" NOR,users());

       flower=clone_object(__DIR__"obj/flower"+random(6));

       flower->move(__DIR__"hongniang-zhuang");
       
       ob = this_object();

       call_out("eateat",3,ob);

       return 1;

}

int eateat(object ob)
{
      object food,ke,*all;
      
      int i;

      all=users();

      message("shout", HIR "�����񡿣�˾�Ǹ߽У������޶���,������͡�\n" NOR,users());
 
      for(i=0; i<sizeof(all); i++) 
        {
          ke = all[i];
          food = clone_object(__DIR__"obj/wlywine");
          food->move(ke);
          tell_object(ke,"��õ�һƿ"+(string)food->query("name")+"��\n"); 
          food = clone_object(__DIR__"obj/cigarette");
          food->move(ke);
          tell_object(ke,"��õ�һ��"+(string)food->query("name")+"��\n"); 
          food = clone_object(__DIR__"obj/sugar"); 
          food->move(ke);
          tell_object(ke,"��õ�һ��"+(string)food->query("name")+"��\n"); 
        }
     message("shout", HIR "�����񡿣�˾�Ǹ߽У���������ϡ���\n" NOR,users());
}   

