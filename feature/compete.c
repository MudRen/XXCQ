//compete.c
//create by Netplay@cctxII
//���ڱ���ϵͳ��һЩ��������

#include <ansi.h>
#include <dbase.h>

mapping fight;

void fight_winner(object loser)
{
        object winner=this_object();
		int i=winner->query_tops();
        string arg;
        COMPETE_D->fighter_place(winner,loser);

        arg=winner->name(1)+"����սʤ"+loser->name(1)+"!";
        if(i>winner->query_tops())
		arg+="��ϲ"+winner->name(1)+"�ٵ�Ӣ�����а��"+winner->query_tops()+
		"��!";
        message("channel:chat",HIC"���������š�"+arg+"\n" NOR, users());

}

/*varargs int query_fight_result(string type)
{
	if( mapp(fight) )
	return fight[type];
}

void add_fight_result(string type)
{
	if( !mapp(fight) ) fight = ([ type: 1 ]);
	else fight[type] = fight[type]+1;
}

void add_jifen(int i)
{
	if( !mapp(fight) ) fight =(["jifen": i]);
	else fight["jifen"]+=i;
}*/

int query_tops()
{
	return COMPETE_D->query_place(this_object());
}