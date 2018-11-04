// char.c
//change lian by@wzfeng 98 7 12
//#pragma save_binary

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>

inherit F_ACTION;
inherit F_ALIAS;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_TEAM;

// Use a tick with longer period than heart beat to save cpu's work
static int tick;


//addit 
//addit
// ����������, ָʾ��ɫ�ǲ�������
static int lianing;

// Ҫ��ϰ���书
static string lian_skill;

// ��ϰ����������
static int zhao_index;
//�ж��Ƿ��������ĺ���
int is_lianing();
//��ʼ����
void do_lian();

//��������
int query_gongfang();




// Use a tick with longer period than heart beat to save cpu's work

void create()
{
	seteuid(0); // so LOGIN_D can export uid to us
	//add @wzfeng
	lianing = 0;

}

// Use this function to identify if an object is a character.
int is_character() { return 1; }

// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
	seteuid(getuid(this_object()));

	set_heart_beat(1);
	tick = 5 + random(10);
    enable_player();

	CHAR_D->setup_char( this_object() );
}

//��������
void heart_beat()
{
	int wimpy_ratio, cnd_flag;
	mapping my;
	object ob;

	my = query_entire_dbase();

	// If we are dying because of mortal wounds?
	if( my["eff_qi"] < 0 || my["eff_jing"] < 0) {
		remove_all_enemy();
		die();
		return;
	}

	
	if( my["qi"] < 0 || my["jing"] < 0||my["jingli"] < 0) {
		remove_all_enemy();
		if( !living(this_object()) ) die();
		else unconcious();
		return;
	}

	// Do attack if we are fighting.
	if( is_busy() ) {
		continue_action();
		//add @wzfeng
		if ( lianing && environment() && random( 100 ) > 30 )
			do_lian();

		// We don't want heart beat be halt eventually, so return here.
		return;
	} else {
		// Is it time to flee?
		if( is_fighting()
		&&	intp(wimpy_ratio = (int)query("env/wimpy"))
		&&	wimpy_ratio > 0
		&&	(	my["qi"] * 100 / my["max_qi"] <= wimpy_ratio
			||	my["jing"] * 100 / my["max_jing"] <= wimpy_ratio) )
			GO_CMD->do_flee(this_object());
		// Do attack or clean up enemy if we have fleed.
		attack();
	}

	if( !userp(this_object()) ) {
		this_object()->chat();
		// chat() may do anything -- include destruct(this_object())
		if( !this_object() ) return;	
	}

	if( tick--  ) return;
	else tick = 5 + random(10);

	cnd_flag = update_condition();

	// If we are compeletely in peace, turn off heart beat.
	// heal_up() must be called prior to other two to make sure it is called
	// because the && operator is lazy :P
	if( ((cnd_flag & CND_NO_HEAL_UP) || !heal_up())
	&&	!is_fighting() 
	&&	!interactive(this_object())	) {
		if( environment() ) {
			ob = first_inventory(environment());
			while(ob && !interactive(ob))
				ob = next_inventory(ob);
		}
		if( !ob ) set_heart_beat(0);
	}

	if( !interactive(this_object()) ) return;

	// Make us a bit older. Only player's update_age is defined.
	// Note: update_age() is no need to be called every heart_beat, it
	//       remember how much time has passed since last call.
	this_object()->update_age();

	if(query_idle(this_object()) > IDLE_TIMEOUT)// && !wizardp(this_object()))
		this_object()->user_dump(DUMP_IDLE);
}

int visible(object ob)
{
	int lvl, invis;

	lvl = wiz_level(this_object());

	if( lvl > wiz_level(ob) ) return 1;
	invis = (int)ob->query("env/invisibility");
	if( intp(invis) && (invis > lvl) ) return 0;

	if( ob->is_ghost() ) {
		if( is_ghost() ) return 1;
		if( query_temp("apply/astral_vision") ) return 1;
		return 0;
	}
	return 1;
}

//��������
int query_gongfang()
{
    int attack;

    if ( undefinedp( query("env/attack") ) || !intp( query("env/attack") ) )
        attack = 50;
    else
    {
        attack = query("env/attack");
        if ( attack < 0 ) attack = 0;
        else if ( attack > 100 ) attack = 100;
    }
    return attack;
}


////////
////////////////////////////////////////////////////////////////////
// Lian interface

int is_lianing()
{
	return lianing;
}

void start_lian(string skill)
{
	zhao_index = 0;
	lianing = 1;
	lian_skill = skill;
	start_busy( (: is_lianing :) );
}

void stop_lian()
{
	lianing = 0;
	if ( is_busy() )
	{
		this_object()->interrupt_me();
	}
}
/*
string *desc_skill = ({
"�������һ�е���ϰ�������������\n",
"�������һ�е���ϰ����ƽ����\n",  
"�����һ�е���ϰ���Ƚ����⡣\n",
});
*/
void do_lian()
{
	string msg,skillname, desc;
	object this, weapon, skill;
	mapping action;
	int jibie;
	int skill_basic,skill_int;
	this = this_object();   
//	desc = desc_skill[random(sizeof(desc_skill))];
	skillname = this->query_skill_mapped(lian_skill);
	skill_basic = this->query_skill(lian_skill, 1);
	skill_int = this->query_skill(lian_skill, 1);

	if( SKILL_D(skillname)->practice_skill(this) ) 
	{
			this->improve_skill(skillname, skill_basic/5 +1, skill_basic > skill_int? 0: 1);

			jibie = this->query_skill( lian_skill );
			action = SKILL_D(skillname)->query_action( jibie );
			if(action["lian"])
			{
				msg = HIY"��������"NOR+WHT+action[ "lian" ] + "\n"NOR;
				weapon = query_temp( "weapon" );
				if ( objectp( weapon ) )
				msg = replace_string( msg, "$w", weapon->name() );
				message_vision( msg, this );
				tell_object(this, HIC"�����ۡ�"NOR+HIW+"�����һ�е���ϰ���Ƚ����⡣\n"+NOR);
			}
			else{
				write( HIY "��������ϰ" + to_chinese(skillname) + "\n" NOR);
			}
	}
	else{
		msg = sprintf( HIY"��������"NOR+"$N���յ���, �����ˡ�%s����\n", to_chinese( skillname) );	
		message_vision( msg, this );
		lianing = 0;
		return;
	}
}


int random_move()
{
	mapping exits;
	string *dirs;

	if( !mapp(exits = environment()->query("exits")) ) return 0;
	dirs = keys(exits);
	command("go " + dirs[random(sizeof(dirs))]);
}









	

	
	
