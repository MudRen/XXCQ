// hssg.c

#include <ansi.h>
inherit ROOM;
static int lianing;

// Ҫ��ϰ���书
static string lian_skill;

// ��ϰ����������
static int zhao_index;
//�ж��Ƿ��������ĺ���
int is_lianing();
//��ʼ����
void do_lian();

void create()
{
         set("short",MAG"��ʩˮ��"NOR);
         set("long",@long
�����������Ļ�ʩˮ���ˣ���˵�����кܶ��������������Ծõľ���
�书��
long);
         set("exits",([
             "south" : __DIR__"sf",
]));
	 setup();
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
	int skill, skill_basic;
        int lianing = 0;
	seteuid(getuid());
        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("ս���л�����ϰ���㲻�������\n");

	if( !arg ) return (__DIR__"enable")->main(me, arg);

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
		me->start_lian(arg);
		printf("hehe\n");
		return 1;
	}
	return 0;

}

int is_lianing()
{       
	printf("hi\n");
	return lianing;
}

void start_lian(string skill)
{                                
	printf("hehe\n");
	zhao_index = 0;
	lianing = 1;
	lian_skill = skill;
	this_player()->start_busy( (: is_lianing :) );
}

void stop_lian()
{
	lianing = 0;
	if ( this_player()->is_busy() )
	{
		this_player()->interrupt_me();
	}
}

void do_lian()
{
	string msg,skillname, desc;
	object me, weapon, skill;
	mapping action;
	int jibie;
	int skill_basic,skill_int;
	me = this_object();
	skillname = me->query_skill_mapped(lian_skill);
	skill_basic = me->query_skill(lian_skill, 1);
	skill_int = me->query_skill(lian_skill, 1);

	if( SKILL_D(skillname)->practice_skill(me) )
	{
			me->improve_skill(skillname, skill_basic/5 +1, skill_basic > skill_int? 0: 1);

			jibie = me->query_skill(lian_skill);
			action = SKILL_D(skillname)->query_action(jibie);
			if(action["action"])
			{
				msg = HIY"��������"NOR+WHT+action["action"] + "\n"NOR;
				weapon = query_temp( "weapon" );
				if ( objectp( weapon ) )
				msg = replace_string( msg, "$w", weapon->name() );
				message_vision( msg, me );
				tell_object(me, HIC"�����ۡ�"NOR+HIW+"�����һ�е���ϰ���Ƚ����⡣\n"+NOR);
			}
			else{
				write( HIY "��������ϰ" + to_chinese(skillname) + "\n" NOR);
			}
	}
	else{
		msg = sprintf( HIY"��������"NOR+"$N���յ���, �����ˡ�%s����\n", to_chinese( skillname) );
		message_vision( msg, me );
		lianing = 0;
		return;
	}
}


