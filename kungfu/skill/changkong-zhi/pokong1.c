  //Update by godzilla 1999.12.8

#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        object ob;              // ���ֵ�����
        string msg;
        int i,m; 
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIY"���ƿյ㡹"+NOR+"ֻ����ս���е�ʹ�á�\n");
        if (objectp(weapon = me->query_temp("weapon")))
                        return notify_fail("�㲻��ʹ��������\n");
        if( (int)me->query_skill("changkong-zhi", 1) < 200 )
               return notify_fail("��ĳ���ָ����������������ʹ�á��ƿյ㡹��\n");
        if( me->query("family/family_name")!="������")
               return notify_fail("�㲻��������ӣ�����ʹ�á��ƿյ㡹\n"); 
        if( (int)me->query_skill("finger",1) < 200 )
                return notify_fail("��Ļ���ָ���������޷�ʹ�á��ƿյ㡹��\n");    
        if ( me->query("max_neili") < 2000)
                return notify_fail("��������������޷�ʹ�á��ƿյ㡹��\n");
        if ( me->query("neili") < 100)
                return notify_fail("�㵱ǰ�����������������޷�ʹ�á��ƿյ㡹��\n");       
        me->add("neili", -50);
        msg = HIY " $N��������һ������ֻ������������ָ����ת��ͻȻ$N����ת,��յ����ָ,\n"
                  " �ͼ�������������$p�����ȥ��\n"NOR;
        ob = target->query_temp("weapon");
        if(  (int)me->query("combat_exp")  > random((int) target->query("combat_exp") ) )
        {
                me->start_busy(2);
                i=(int)me->query_skill("dodge",1);
                m=(int)me->query_skill("force",1);  
                if (! objectp(ob))
                {
                        int damage = 0;
                        if (target->query_skill("dodge") < i &&
 random(2) == 0)
                        {
                                switch (random(2))
                                {
                                case 0:
                                        msg += HIW " $p�������ܣ����ڻ���û�ܶ����������������"
                                                   "����$p�ĵ����ϣ�$pֻ�����ؿ�����˵���������ܡ�\n";
                                        damage = 3;
                                        break;
                                case 1:
                                        msg += HIW " $p��ȫû�з����������ۡ���һ����$p��ɫɷ�ף��Ѿ�ҡҡ��׹�ˡ�\n";
                                        damage = 5;
                                        break;
                                }
                        }
                       else
                       if (target->query_skill("force") > m && random(2) == 0)
                       {
                                switch(random(2))
                                {
                                case 0:
                                        msg += HIR " $p���һ�����Գ�������ǿ�����ֳ��У���࣡�"
                                                "��һ����ָ�ཻ��$p����΢�Σ������ֽ��\n";
                                        damage = 3;
                                        break;
                                case 1:                                        msg += HIR " $pһ����Х��˫�ֻû���������Ӱ����ס��ǰ��"
                                                "ֻ�����͡���һ������Ӱ������$p�Ѿ������ɫ�Ұס�\n";
                                        damage = 4;
                                        break;
                                }
                        }
                        else
                         {
                                switch(random(2))
                                {
                                case 0:
                                        msg += HIR " $p�������У���Ȼ��֪��ܣ����͡���һ����$N"
                                                "��һָ������$p�İٻ�Ѩ��\n";
                                        damage = 5;
                                        break;
                                case 1:
                                        msg += HIR " $p�����ܣ�������������̫��,ֻ�����͡���һ�����ѱ�$N����̴"
                                                "�д�Ѩ��\n";
                                        target->unconcious();
                                        damage = 0;
                                        break;
                                }
                        }
                        if (damage > 0)
                        target->receive_damage("qi", target->query("max_qi") * damage / 12);
                        message_vision(msg + NOR, me, target);
                        return 1;
                }
                if (ob->query("nopawn"))
                {
                        switch(random(2))
                        {
                        case 0:
                        msg += HIR " $pæ��" + ob->query("name") + "�мܣ�ֻ���û��ھ������ұ����������\n" NOR;
                        target->start_busy(2);
                        break;
                        case 1:
                        msg +=HIR "$p����֮����"+ob->query("name")+"�м�,ֻ���û��ھ�ʹ,����"+ob->query("name")+"���ֶ��ɣ�\n"NOR;
                        ob->move(environment(target));
                        target->start_busy(2); 
                        break;
                        }         
                } 
                else
                {
                        msg += HIW " $p��æ�мܣ�ֻ������ž����һ����$p���е�" + ob->name()
                                + "��������ϣ�ɢ��һ�أ�\n";
                        ob->unequip();
                        ob->move(environment(target));
                        ob->set("name", "�ϵ���" + ob->query("name"));
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                }
                target->start_busy(2);
        }
 else
        {

                int busy = 0;
                if (target->query_skill("dodge") > i && random(2) == 0)
                {
                        switch (random(2))
                        {
                        case 0:
                                msg += WHT" $pһ����Ц����������������Ķ����$N�Ľ�����\n";
                                busy = 2;
                                break;
                        case 1:
                                msg += WHT" $pͻȻ���Ʈȥ���������磬���ɵĶ����$N�ı�ɱ֮�ơ�\n";
                                busy = 1;
                                break;
                        }
                }
 else
                if (target->query_skill("force") > m && random(2) == 0)
                {
                        switch (random(2))
                        {
                        case 0:
                                msg += YEL" $p��ɫ���أ�æ���������ϣ�Ӳ������$N�����о�����\n";
                                busy = 3;
                                break;
                        case 1:
                                msg += YEL" $p������м���Ʒ��Ƴ���ֻ���Ѽ�������Ӳ�����ķ�����������$N���һ����\n";
                                busy = 1;
                                break;
                        }
                }
 else                {
                        switch (random(3))
                        {
                        case 0:
                                msg += HIW" $p��ҡ�һΣ�����ȥ�����·���ƫƫ�����$N��һ����\n";
                                busy = 2;
                                break;
                        case 1:
                                msg += HIW" $pһָ���������ȥ����Ҳ�ǳ���ָ����$Nһ�������ƶٻ���\n";
                                busy = 2;
                                break;
                        case 2:
                                msg += HIW"$p��ס����������ע" + ob->query("name")
                                         + "��������ס��$N�Ľ�����\n";
                                busy = 2;
                                break;
                  }
                }
                        
                
                target->start_busy(3);
                me->start_busy(2);
        
                }
        message_vision(msg + NOR, me, target);
        return 1;
}
