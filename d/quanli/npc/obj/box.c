// box.c �ƺ�
// by mulan

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_gudu","gudu");
}

void create()
{
        set_name("�ƺ�", ({ "gu he", "he","box" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","��");
        set("sworm",5);
        set("value",0);
        set("material","wood");
        set("long", "����һ������ȥ����ͨ�ĺ��ӣ�\n"
                    "����������ȴ��Ϊ����������Ϊͷʹ�Ķ���____�۹ƣݡ�\n"
                    "��������(gudu) ! \n");
        }
        setup();
}

int do_gudu(string arg)
{
    object me, obj;
    int myexp , objexp ;
    int mylev , objlev ;
    int myforce , obforce ;
    int steps ;

        me = this_player();
        if( environment(me)->query("no_fight") )
                return notify_fail("�����ֹս����\n");
        if( !arg )
                return notify_fail("���빥��˭��\n");

        if( this_object()->query("sworm") <=0)
                return notify_fail("����Ĺ��Ѿ�û���ˡ�\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if(obj == me)
                return notify_fail("��û������ɡ�\n");

        myexp =  me -> query ("combat_exp" ) ;
        objexp = obj -> query ("combat_exp" ) ;
        mylev =  me -> query_skill("gudu" ) ;
        objlev = obj -> query_skill("gudu" ) ;
        myforce =  me -> query_skill("force" ) ;
        obforce = obj -> query_skill("force" ) ;

        if ( mylev <= 0 )
                return notify_fail("�㲻��ƶ�֮��������ң�عƳ湥�����ˣ�\n");

        myexp = 30 * objexp / myexp ;
        if ( myexp < 30 ) myexp = 30 ;

        if ((int) me ->query("jingli") < myexp )
                return notify_fail("��ľ�������ң�عƳ棡\n");

        if ((myforce + 30) <= obforce)
                return notify_fail("���ֵ��ڹ�̫����ˣ��ƶ������������ã�\n");

        this_object()->add("sworm", -1);
        
        steps =  mylev / 10  ;
        if ( steps < 5 ) steps = 5 ;
        if ( steps > 15 ) steps = 15 ;
        message_vision(HIY "\n$N��˫�����˳�ȥ�������ͷ�����һ���ܹ��ص��£�\n\n"
                   HIW"��Ȼ��һ�㱡���İ��࣬Ѹ�ٵ�����ǰ����է����һ�㱡��\n"
                   "����ϸ��ȥ������ǧ����С��һ����ǰ���ζ�����\n\n"
                   HIB"$n�̲���ʧ������������    "+HIR"���ƶ�����\n"NOR,
                   me, obj);
        me -> start_busy (3) ;

        if( userp(obj) )
        {       obj -> fight_ob(me) ;
                me->fight_ob(obj);
        }
        else
        {       obj->kill_ob(me);
                me->fight_ob(obj);
        }
        if (  random ( mylev ) < random(obj->query_dex()) )
                message_vision(YEL "\n��$n ���Ÿ�����Ṧ������ȥ!��\n" NOR, me, obj);
        else
        {
         tell_object (obj , HIR "\n����Χɲ�Ǽ価�ǹƳ棬ǧ��ֻ���䶯����ôҲ�ϲ��ߣ�\n"
               "��ֻ���ý���΢΢һʹ���ѱ��Ƴ�ҧ���ˣ�\n" NOR  ) ;
         obj->apply_condition("sworm_poison", 30);
         tell_object(obj, HIG "�����������ʹ,���ã������˹ƶ���\n" NOR );
         obj -> receive_damage ("jingli", steps * 8 ) ;
         obj -> receive_damage ("qi", steps * 10 ) ;
         obj -> start_busy (3) ;
         me -> start_busy (1) ;
        }
        me -> receive_damage ("jingli" , mylev ) ;
        me -> add("neili" , - mylev ) ;
        return 1;
}
