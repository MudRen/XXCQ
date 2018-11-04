// who.c
// From ES2
// Modified by Java on Sep.14 1998

#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int sort_user(object,object);
int help();

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
	string name, str, *option;
	object *list, *ob, ob1;
	int i, ppl_cnt;
	int opt_long, opt_wiz, opt_party;
	if( arg )
	{
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i])
			{
				case "-h": return help();
				case "-l": opt_long = 1;break;
				case "-w": opt_wiz = 1;break;
				case "-p": opt_party = 1;break;
				default:
					if(option[i][0]=='@' )
					{
						RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],me, opt_long);
						write("��·ѶϢ���ͳ������Ժ�\n");
						return 1;
					}
					ob1 = present(option[i], environment(me));
					if (!ob1) ob1 = find_player(option[i]);
					if (!ob1) ob1 = find_living(option[i]);
					if ((!ob1) && (option[i] =="me")) ob1=me;
					if (!ob1) return notify_fail("û�������һ��������\nָ���ʽ : who [-h] [-l] [-w] [-p] [<ID>]\n");
					me = ob1; opt_party = 1;
			}
	}
	str = HIW+CHINESE_MUD_NAME+NOR"Ŀǰ";
	if(opt_party)
		if(me->query("family/family_name"))
			str += HIR+"("+me->query("family/family_name")+") "+NOR;
		else str += HIR + "(������) " + NOR;
	if ( opt_wiz )
		str += "��ʦ�У�";
	else
		if ( opt_long ) str += "����У�";
		else str += "�������У�";
	str += "\n��������������������������������������������������������������������������\n";
	ob = filter_array(objects(), (: userp :));
	if (opt_party)
		ob = filter_array(ob, (: $1->query("family/family_name") ==	$2->query("family/family_name") :), me);
	list = sort_array(ob, (: sort_user :));
	ppl_cnt = 0;
	if( opt_long || opt_wiz)
	{
		i = sizeof(list);
		while ( i-- )
		{
			// Skip those users in login limbo.
			if( !environment(list[i]) ) continue;
			if( !wizardp(me) && !me->visible(list[i]) ) continue;
			if (opt_wiz&&!wizardp(list[i]) ) continue;
			if( interactive(list[i]) )
				ppl_cnt++;
			str = sprintf("%s%12s%s%s\n",str,RANK_D->query_rank(list[i]),
				interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
				list[i]->short(1));
		}
	}
	else
	{
		i = sizeof(list);
		while ( i-- )
		{
			// Skip those users in login limbo.
			if ( !environment(list[i]) ) continue;
			if ( !wizardp(me) && !me->visible(list[i]) ) continue;
			name=interactive(list[i])?(query_idle(list[i])>120?HIG"*" NOR:" "):HIR "#" NOR;
			name = sprintf( "%s%-10s(%-11s��",name,list[i]->name(1),
					capitalize(list[i]->query("id"))+")");
			str = sprintf("%s%25s%s", str, name,ppl_cnt%3==2?"\n":"");
			//if (interactive(list[i]))
			ppl_cnt++;
		}
		if ( ppl_cnt%3 ) str += "\n";
	}
	str += "��������������������������������������������������������������������������\n";
	str = sprintf("%s���� %s λʹ���������У�ϵͳ������%s\n "HIG"*"NOR" ��ʾ�����У�"HIR"#"NOR" ��ʾ�����С�", str, CHINESE_D->chinese_number(sizeof(list)),
	query_load_average());
//      if( remote ) return str;
//      write(str + "\n");
	me->start_more(str);
	return 1;
}
int sort_user(object ob1, object ob2)
{
	string name1, name2;
	if( wiz_level(ob1) != wiz_level(ob2) )
		return wiz_level(ob2) - wiz_level(ob1);
	name1 = ob1->query("family/family_name");
	name2 = ob2->query("family/family_name");
	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;
	return (int)ob2->query("family/generation") - (int)ob1->query("family/generation");
}

int help()
{
	write("ָ���ʽ : who [-h] [-l] [-w] [-p] [<ID>]
���ָ������г����������ϵ���Ҽ���ȼ���
-h �г�������Ļ��
-l ѡ���г��ϳ���ѶϢ��
-p ֻ�г�ͬ�ŵ���ҡ�
-w ֻ�г��������е���ʦ��
<ID> �г�<ID>��������������ɵ���ҡ�
"HIG"*"NOR" ��ʾ"HIG"����"NOR"�У�"HIR"#"NOR" ��ʾ"HIR"����"NOR"�С�
���ָ� finger");
    return 1;
}