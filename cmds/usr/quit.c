// quit.c

#include <command.h>
#include <mudlib.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
	seteuid(getuid());
	set("channel_id", "���߾���(Quit)");
}

int main(object me)
{
	int i;
	object *inv, link_ob;

	if( LOGIN_D->get_madlock()) 
		return notify_fail("ʱ���Ѿ���գ�û�����ܹ��˳����ʱ���ˡ�\n");

	if( (me->is_busy()) && (!me->query_temp("suicide_countdown")))
		return notify_fail("��������æ���������£������˳���Ϸ��\n");

	if( !wizardp(me) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(me, inv[i]);
	}

	link_ob = me->query_temp("link_ob");

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {

		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}

		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();

		if( environment(me)->query("valid_startroom") )
		{
			me->set("startroom", base_name(environment(me)));
			write("�����´����߽���ʱ��������￪ʼ��\n");
		}

		destruct(link_ob);
	}

	write("��ӭ�´�������\n");
	message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);
	i=me->query("combat_exp")-me->query_temp("temp_exp");
	if (i < 0 ) i=0;
	CHANNEL_D->do_channel(this_object(), "sys",
		me->name() + "(" + me->query("id") + ")�뿪��Ϸ�ˡ�\n\t�������߾�������"+i+
			"��\n\t����ʱ��"+
			CHINESE_D->chinese_period(FINGER_D->online_time(me))+
			"��\n");
	if(wizardp(me))
		CHANNEL_D->do_channel(this_object(),"wiz",me->name(1)+
			"�뿪��"+CHINESE_MUD_NAME+"��\n");
	me->set("time_aged",me->query("time_aged")+time()-me->query_temp("temp_time"));
	//����������ʱ�䵽time_aged�����У��漰FINGER_D��LOGIN_D,CHINESE_D #By JackyBoy@cctx
	//��֪BUG���е����time_aged������δ���ԭ��
	me->save();
	destruct(me);

	return 1;
}

int help()
{
	write(@HELP
ָ���ʽ : quit
����(��)����ʱ�뿪ʱ, �����ô�һָ�
HELP
    );
    return 1;
}
