#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "˯��");
        set("long", @LONG
���˯������������������ׯ���������ˡ���һ��������������
���м����飬ȴ�ǡ��׾���֮�ࡣǽ����һ�����ӡ��������俴��ȥ��
Ϊ������
LONG);
        set("no_fight", "1");
        set("objects", ([
                    __DIR__"obj/book5" : 1,
                    __DIR__"obj/book1" : 1,
        ]));
        set("book_count",1);
        set("exits", ([
              "west" : __DIR__"tangwu",
        ]));
        setup(); 
}

void init()
{
        add_action("do_shui", "sleep");
}

int do_shui(string arg)
{
        object me = this_player();
        object where = environment(me);        
        message_vision("\n$Nһ�������ڴ��ϣ���һ����������������������硣\n",me);        
        me->set_temp("block_msg/all",1);
        me->disable_player("<˯����>");
        call_out("wakeup", 10 + random(30 - me->query("con")), me, where);
        return 1;
}

void wakeup(object me)
{
        int cost = me->query_condition("sleep");
        if (!me) return;
        if (!cost)
                me->apply_condition("sleep", 9);
        cost++;        
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));      
        me->add("qi",    (me->query("eff_qi") - me->query("qi"))/cost);
        me->add("jing",  (me->query("eff_jing") - me->query("jing"))/cost);
        me->add("neili", (me->query("max_neili") - me->query("neili"))/2/cost);
        me->add("jingli", (me->query("eff_jingli") - me->query("jingli"))/2/cost);
        me->enable_player();
        message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
        me->delete_temp("block_msg/all");       
        write("��һ�����������þ������棬�ûһ���ˡ�\n");
        if (random(me->query("kar")) > 15 && me->query("oyf_son")
            && query("book_count") >= 1){ 
             write("�������ڴ���һ�ţ���Ȼ���ִ����¸���ʲô������\n");
             write("�ƿ�����һ����ԭ����һ����������װ�顣\n");
             (__DIR__"obj/book")->move(me)
;
             add("book_count", -1);
             }
}
