// syz.c
#include <ansi.h>
inherit ROOM;
nosave int lianing;
nosave int tick;
// Ҫ��ϰ���书
nosave string lian_skill;

// ��ϰ����������
nosave int zhao_index;
//�ж��Ƿ��������ĺ���
int is_lianing();
//��ʼ����
void do_lian();
void create()
{
	 lianing = 0;
         set("short",HIY"����ի"NOR);
         set("long",@long
����ի��ΪĽ�ݼ�ÿ������֮ҹ������ġ����渻���ûʣ��Ϲ�Ӧ�о�
�У��Ա���Ѿ���ź��ţ�ÿ������֮ʱ��һ����С�����������£������µ�
ͬʱ��Ҳ��������˴����ʹ����
long);
         set("exits",([
		"west" : __DIR__"cl2",
	]));
	set("objects", ([
	__DIR__"obj/fruit" : 2,
]));
        setup();
}

void init()
{
	add_action("yanxi", "yanxi");
}

int is_lianing()
{
	return lianing;
}

void start_lian(string skill)
{
	object me = this_player();
	zhao_index = 0;
	lianing = 1;
	lian_skill = skill;
	me->start_busy( (: is_lianing :) );
}

void stop_lian()
{
	object me = this_player();
	lianing = 0;
	if ( me->is_busy() )
	{
		this_object()->interrupt_me();
	}
}

void do_lian()
{
	int jibie;
	int skill_basic,skill_int;
	string msg,skillname;
	object me, weapon, skill;
	mapping action;

	me = this_player();
	seteuid(getuid(me));

	me->set_heart_beat(1);
	tick = 5 + random(10);

	skillname = me->query_skill_mapped(lian_skill);
	skill_basic = me->query_skill(lian_skill, 1);
	skill_int = me->query_skill(lian_skill, 1);

	if( SKILL_D(skillname)->practice_skill(me) )
	{
			me->improve_skill(skillname, skill_basic/5 +1, skill_basic > skill_int? 0: 1);

			jibie = me->query_skill( lian_skill );
			action = SKILL_D(skillname)->query_action(jibie);
			if(action["lian"])
			{
				msg = HIY"��������"NOR+WHT+action[ "lian" ] + "\n"NOR;
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

int yanxi(string arg)
{
	object me = this_player();
	object where = environment(me);
	string skillname;
	int skill, skill_basic;

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
		return 1;
	}
        return 1;
}
