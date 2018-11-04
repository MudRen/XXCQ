// message.c
#include <ansi.h>

varargs void message_vision(string msg, object me, object you)
{
	string my_gender, your_gender, my_name, your_name;
	string str1, str2, str3;

	my_name= me->name();
	my_gender = me->query("gender");
	str1 = replace_string(msg,  "$P", gender_self(my_gender));
	str1 = replace_string(str1, "$N", gender_self(my_gender));
	str3 = replace_string(msg,  "$P", my_name);
	str3 = replace_string(str3, "$N", my_name);
	if( you ) {
		your_name= you->name();
		your_gender= you->query("gender");
		str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str2 = replace_string(str2, "$p", gender_self(your_gender));
		str2 = replace_string(str2, "$N", my_name);
		str2 = replace_string(str2, "$n", gender_self(your_gender));
		message("vision", str2, you);
		str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
		str1 = replace_string(str1, "$n", your_name);
		str3 = replace_string(str3, "$p", your_name);
		str3 = replace_string(str3, "$n", your_name);
	}
	message("vision", str1, me);
	message("vision", str3,  environment(me), ({ me, you}) );
}

void tell_object(object ob, string str)
{
	message("tell_object", str, ob);
}

varargs void tell_room(mixed ob, string str, object *exclude)
{
	if( ob ) message("tell_room", str, ob, exclude);
}

void shout(string str)
{
	message("shout", str, users(), this_player());
}

void write(string str)
{
	if( this_player() )
		message("write", str, this_player());
	else if( previous_object() )
		message("write", str, previous_object());
	else
		efun::write(str);
}

varargs void say(string str, mixed t)
{
	if( living(previous_object()) )
		message("say", str, environment(previous_object()), previous_object());
	else if( this_player() )
		message("say", str, environment(this_player()), this_player());
}

//replace_color() added by jackyboy @ cctx&snow 1999/11/4
varargs string replace_color(string arg,int flag)
{
	arg = replace_string(arg, "$BLK$", flag?BLK:"");
	arg = replace_string(arg, "$RED$", flag?RED:"");
	arg = replace_string(arg, "$GRN$", flag?GRN:"");
	arg = replace_string(arg, "$YEL$", flag?YEL:"");
	arg = replace_string(arg, "$BLU$", flag?BLU:"");
	arg = replace_string(arg, "$MAG$", flag?MAG:"");
	arg = replace_string(arg, "$CYN$", flag?CYN:"");
	arg = replace_string(arg, "$WHT$", flag?WHT:"");
	arg = replace_string(arg, "$HIR$", flag?HIR:"");
	arg = replace_string(arg, "$HIG$", flag?HIG:"");
	arg = replace_string(arg, "$HIY$", flag?HIY:"");
	arg = replace_string(arg, "$HIB$", flag?HIB:"");
	arg = replace_string(arg, "$HIM$", flag?HIM:"");
	arg = replace_string(arg, "$HIC$", flag?HIC:"");
	arg = replace_string(arg, "$HIW$", flag?HIW:"");
	arg = replace_string(arg, "$NOR$", flag?NOR:"");
	arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
	
        // Background color
	arg = replace_string(arg, "$BBLK$", BBLK);
	arg = replace_string(arg, "$BRED$", BRED);
	arg = replace_string(arg, "$BGRN$", BGRN);
	arg = replace_string(arg, "$BYEL$", BYEL);
	arg = replace_string(arg, "$BBLU$", BBLU);
	arg = replace_string(arg, "$BMAG$", BMAG);
	arg = replace_string(arg, "$BCYN$", BCYN);
	arg = replace_string(arg, "$HBRED$", HBRED);
	arg = replace_string(arg, "$HBGRN$", HBGRN);
	arg = replace_string(arg, "$HBYEL$", HBYEL);
	arg = replace_string(arg, "$HBBLU$", HBBLU);
	arg = replace_string(arg, "$HBMAG$", HBMAG);
	arg = replace_string(arg, "$HBCYN$", HBCYN);
	if(flag) arg+=NOR;
	return arg;
}
string clean_color(string arg)
{
	arg = replace_string(arg, BLK, "");
	arg = replace_string(arg, RED, "");
	arg = replace_string(arg, GRN, "");
	arg = replace_string(arg, YEL, "");
	arg = replace_string(arg, BLU, "");
	arg = replace_string(arg, MAG, "");
	arg = replace_string(arg, CYN, "");
	arg = replace_string(arg, WHT, "");
	arg = replace_string(arg, HIR, "");
	arg = replace_string(arg, HIG, "");
	arg = replace_string(arg, HIY, "");
	arg = replace_string(arg, HIB, "");
	arg = replace_string(arg, HIM, "");
	arg = replace_string(arg, HIC, "");
	arg = replace_string(arg, HIW, "");
	arg = replace_string(arg, NOR, "");
	arg = replace_string(arg, BLINK, "");
	//BackGround Color
	arg = replace_string(arg, "$BBLK$", "");
	arg = replace_string(arg, "$BRED$", "");
	arg = replace_string(arg, "$BGRN$", "");
	arg = replace_string(arg, "$BYEL$", "");
	arg = replace_string(arg, "$BBLU$", "");
	arg = replace_string(arg, "$BMAG$", "");
	arg = replace_string(arg, "$BCYN$", "");
	arg = replace_string(arg, "$HBRED$", "");
	arg = replace_string(arg, "$HBGRN$", "");
	arg = replace_string(arg, "$HBYEL$", "");
	arg = replace_string(arg, "$HBBLU$", "");
	arg = replace_string(arg, "$HBMAG$", "");
	arg = replace_string(arg, "$HBCYN$", "");
	return arg;
}
nomask varargs void printf(mixed *arg1...) 
{ 
	mixed *arg; 
	string output; 
	
	//arg1 = map_array( arg1,(: CONVERT_D->output($1,this_player(1)) :) ); 
	arg = arg1[1..]; 
	output = sprintf(arg1[0],arg...); 
	write(output); 
} 

void message_system(string message)
{
	message("system", HIW "\n��ϵͳ��ʾ��" + message + "\n" NOR,all_interactive(), 0);
}

