 //����
//Write by phoenix 1999.12.5

int overqudu(object me);

#include <ansi.h>
string *qudu_msg = ({
        CYN"\n��ͷ���Ѿ�ʢ���˺�ˮ��ȫ��ɢ�������������Ѿ������ıƳ��˵��\n\n"NOR,
        CYN"��ϢԽתԽ�죬����žž���죬��ֻ�����Ѿ��ں��ˡ�\n\n"NOR,
        CYN"�������Ѿ�Լ����ɫ��ʮָ����һ��һ�ε�ʢ���˺�ɫ�Ķ�Һ��\n\n"NOR,
 
});
int exert(object me)
{
    int stage;  
    if( me->is_fighting() )
        return notify_fail("ս�����˹�������������\n");
    if ((int)me->query_skill("tianyu-qigong", 1) < 100)
        return notify_fail("��������湦��Ϊ��������ǿ���������ܷ����亦��\n");
    if( (int)me->query("neili") < 500 )
        return notify_fail("���\��������������������\n");
    if (me->is_busy() || me->query_temp("qu_du"))
                return notify_fail("��������æ���ء�\n");
        if(me->query("family/family_name")!="������")
        return notify_fail("�����ڲ���������\n");
    if ((int)me->query_condition("xisui_du") > 0
          || me->query_condition("yangdu_poison") > 0
          || me->query_condition("yao1_poison") > 0 
          || me->query_condition("yao2_poison") > 0
          || me->query_condition("xie_poison") > 0
          || me->query_condition("xiangshi_poison") > 0
          || me->query_condition("sworm_poison") > 0
          || me->query_condition("snake_poison") > 0
          || me->query_condition("shengdu_poison") > 0
          || me->query_condition("hx_poison") > 0
          || me->query_condition("feixing_poison") > 0
          || me->query_condition("duzun_poison") > 0  
           )  
          {
                message_vision(HIW"$NǱ�ľ�����һ�������ӵ������ж��ϣ�׼��ǿ�бƳ����ڶ��ء�\n"NOR,me);
                me->set_temp("qu_du",20);
                me->start_busy((: overqudu :));
                remove_call_out("guocheng_qudu");
                call_out("guocheng_qudu",9,me,stage);
                return 1;
           }
    else
    return notify_fail("�����û���ж��ļ���\n");
}
int overqudu(object me)
{
        int num=me->query_temp("qu_du");
        int stage; 
        if (num < 1)
        return 0; 
        me->set_temp("qu_du", num-=1);   
        if (num > 1)
        return 1;
        me->set_temp("qu_du", 0);
        me->add("neili",-500);
        message_vision(HIW"$N������ϣ��������˿�����վ��������\n"NOR, me);
        me->apply_condition("xisui_du",0);
        me->apply_condition("yangdu_poison",0);
        me->apply_condition("yao1_poison",0);
        me->apply_condition("yao2_poison",0);
        me->apply_condition("xie_poison",0); 
        me->apply_condition("xiangshi_poison",0);
        me->apply_condition("sworm_poison",0);
        me->apply_condition("snake_poison",0);
        me->apply_condition("shengdu_poison",0);
        me->apply_condition("hx_poison",0);
        me->apply_condition("feixing_poison",0);
        me->apply_condition("duzun_poison",0);    
}               
int guocheng_qudu(object me,int stage)
{
        tell_object(me, qudu_msg[stage]);
        if(++stage < sizeof(qudu_msg) )
        {
                call_out("guocheng_qudu",9,me,stage);
                return 1;
        }
}        
        
 
