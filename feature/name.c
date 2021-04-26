// name.c

#include <ansi.h>
#include <dbase.h>
#include <condition.h>

nosave string *my_id;

void set_name(string name, string *id)
{
	set("name", name);
	set("id", id[0]);
	my_id = id;
}

int id(string str)
{
	string *applied_id;

	if( this_player() && !this_player()->visible(this_object()) ) return 0;

	if( pointerp(applied_id = query_temp("apply/id"))
	&&	sizeof(applied_id) )
		if( member_array(str, applied_id)!=-1 )
			return 1;
		else
			return 0;

	// If apply/id exists, this object is "pretending" something, don't
	// recognize original id to prevent breaking the pretending with "id"
	// command.

	if( pointerp(my_id) && member_array(str, my_id)!=-1 )
		return 1;
	else
		return 0;
}

string *parse_command_id_list()
{
	string *applied_id;

	if( pointerp(applied_id = query_temp("apply/id"))
	&&	sizeof(applied_id) )
		return applied_id;
	else
		return my_id;
}

varargs string name(int raw)
{
	string str, *mask;

	if( !raw && sizeof(mask = query_temp("apply/name")) )
		return mask[sizeof(mask)-1];
	else {
		if( stringp(str = query("name")) )
			return str;
		else
			return file_name(this_object());
	}
}

varargs string short(int raw)
{
	mapping party;
	string party_title,title, nick, str , *mask;

	if( !stringp(str = query("short")) )
		str = name(raw) + "(" + capitalize(query("id")) + ")";

	if( !this_object()->is_character() ) return str;

	if (!raw) {
		if ((int)query_temp("pending/exercise") != 0)
			return name() + "正坐在地下修炼内力。";
		else if ((int)query_temp("pending/respirate") != 0)
			return name() + "正坐在地下吐纳炼精。";
		else if ((int)query_temp("pending/zhoutian") != 0)
			return name() + "正坐在地下运周天。";
	}

        if( !raw && sizeof(mask = query_temp("apply/short")) )
                str = (string)mask[sizeof(mask)-1];
	else
	{
		if( stringp(nick = query("nickname")) )
			str = sprintf("「%s」%s", nick, str);

		if( stringp(title = query("title")) )
			str = sprintf("%s%s%s", title,(nick?"":" "), str);

		if ( mapp(party = query("party")) )
		{
			party_title = party["party_name"] + party["rank"];
			str=sprintf("%s %s%s%s", party_title,(title?"":" "),(nick?"":" "), str);
		}
	}

        if( this_object()->query_temp("state"))
            str += HIG + "<" + this_object()->query_temp("state")+ ">" + NOR;
	if( !raw ) {
		if( this_object()->query_condition("killer") > 0 ) str = HIR "(通缉犯) " NOR + str;
		if( this_object()->is_ghost() ) str = HIB "(鬼气) " NOR + str;
		if( query_temp("netdead") ) str += HIG " <断线中>" NOR;
		else
		if (this_object()->query("hunmi")) str += HIR "<昏迷不醒>"NOR;
		//if (sleeps(this_object())) str += HIR "<睡梦中>" NOR;
		else{
		if( in_input() ) str += HIC " <输入文字中>" NOR;
		if( in_edit() ) str += HIY " <编辑档案中>" NOR;
		}
		if( interactive(this_object())
		&&	query_idle( this_object() ) > 120 ) str += HIM " <发呆"
			+chinese_number((query_idle(this_object())-60)/60)+"分钟>" NOR;
		if( !living(this_object()) ) str += HIR + query("disable_type") + NOR;
	}

	return str;
}

varargs string long(int raw)
{
	string str, extra, *mask;

	if( !raw && sizeof(mask = query_temp("apply/long")) )
		str = mask[sizeof(mask)-1];
	else if( !stringp(str = query("long")) )
		str = short(raw) + "。\n";

	if( stringp(extra = this_object()->extra_long()) )
		str += extra;

	return str;
}
