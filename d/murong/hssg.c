// hssg.c

#include <ansi.h>
inherit ROOM;
int start_douzhuan();
int halt_douzhuan(object me);
void create()
{
         set("short",MAG"��ʩˮ��"NOR);
         set("long",
"����Ǿ��������Ĺ���Ľ�ݵĻ�ʩˮ�������˵�кܶ�����������\n"
"���Ծõ��书��ֻ��ǽ����һ�������(shujia)����������˸����伮��\n"
);
         set("exits",([
             "south" : __DIR__"sf",
]));
         set("item_desc", ([
             "shujia" : "����ϸ������ɵ��书�ؼ�(miji)�����̲�ס������һ���ͷ���������\n",
]));
}

void init()
{
	add_action("douzhuan", "douzhuan");
}

int douzhuan(string arg)
{       
	object me = this_player();
	object where = environment(me);
	string skillname;
	int skill, skill_basic, time;
	seteuid(getuid());
	if( me->is_busy())
		return notify_fail("����æ���ء�\n");
	if( me->is_fighting())
		return notify_fail("����æ���ء�\n");        
	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);

	if( skill < 1 )
		return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱��ˡ�\n");
	if( skill_basic < 1 )
		return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("��Ļ�����û�������ң������ȴ�û������ܼ�����ߡ�\n");

	notify_fail("�����ڲ�����ϰ����ܡ�\n");
	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;
	notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");
	if( SKILL_D(skillname)->practice_skill(me) )
	{
		message_vision( HIY"��������"NOR"$N�ڿ��������ļ�ʽ��׼����ʼ��ϰ"+to_chinese(skillname)+"��\n", me );
	    	time = (int)me->query_skill("douzhuan-xingyi", 1)/20;		
	    	me->set_temp("pending/douzhuan", 1);   
    		me->set_temp("douzhuan_times", time);
	    	me->set_temp("douzhuan/period", 1);    	
    		me->start_busy( (: start_douzhuan :), (: halt_douzhuan :) );	    	
		me->start_douzhuan(arg);
		printf("hehe\n");
		return 1;
	}
	return 0;		
} 

int start_douzhuan()
{                                                     
	string msg,skill, desc;
	object me, weapon, skill;
	mapping action;                                     
	me = this_object();   
	int jibie = me->query_skill(skill);
	int neili_cost = (int)me->query_skill("shenyuan-gong", 1)/4;                                    
        int time = (int)me->query_temp("douzhuan_times");
        int period = (int)me->query_temp("douzhuan/period");   
        me->receive_damage("neili", neili_cost);
       	if(period < time)
       	{            
		write("1.\n");
	}                                
	if( period == time)
        {
           	me->delete_temp("pending/douzhuan");
       	        message_vision(CYN"\n$N΢΢����˫�ۣ�������Ϣ��վ��������\n"NOR, me);
       	        return 0;
        }
        period++;                           
        me->set_temp("douzhuan/period", period);
        return 1;        
}           

int halt_douzhuan(object me)
{
        me->delete_temp("pending/douzhuan");    
        if(living(me))
        message_vision(CYN"\n$N΢΢����˫�ۣ�������Ϣ��վ��������\n"NOR, me);
        return 1;
}                          	