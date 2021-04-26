// hssg.c

#include <ansi.h>
inherit ROOM;
nosave int lianing;

// 要练习的武功
nosave string lian_skill;

// 练习的招数索引
nosave int zhao_index;
//判断是否在练功的函数
int is_lianing();
//开始练功
void do_lian();

void create()
{
         set("short",MAG"还施水阁"NOR);
         set("long",@long
这就是燕子坞的还施水阁了，据说这里有很多武林人事向往以久的绝世
武功。
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
                return notify_fail("你还是专心拱猪吧！\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中还想练习，你不想活啦。\n");

	if( !arg ) return (__DIR__"enable")->main(me, arg);

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");

	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);

	if( skill < 1 )
		return notify_fail("你好像还没有学过这项技能吧？最好先去请教别人。\n");
	if( skill_basic < 1 )
		return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");
	if( skill_basic/2 <= skill/3 )
		return notify_fail("你的基本功没有练到家，必须先打好基础才能继续提高。\n");

	notify_fail("你现在不能练习这项技能。\n");
	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;
	notify_fail("你试着练习" + to_chinese(skillname) + "，但是并没有任何进步。\n");

	if( SKILL_D(skillname)->practice_skill(me) )
	{
		message_vision( HIY"【练功】"NOR"$N摆开了练功的架式，准备开始练习"+to_chinese(skillname)+"。\n", me );
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
				msg = HIY"【练功】"NOR+WHT+action["action"] + "\n"NOR;
				weapon = query_temp( "weapon" );
				if ( objectp( weapon ) )
				msg = replace_string( msg, "$w", weapon->name() );
				message_vision( msg, me );
				tell_object(me, HIC"【评论】"NOR+HIW+"你对这一招的练习还比较满意。\n"+NOR);
			}
			else{
				write( HIY "你正在练习" + to_chinese(skillname) + "\n" NOR);
			}
	}
	else{
		msg = sprintf( HIY"【练功】"NOR+"$N气收丹田, 练完了【%s】。\n", to_chinese( skillname) );
		message_vision( msg, me );
		lianing = 0;
		return;
	}
}
