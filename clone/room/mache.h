// File:/clone/room/mache.h
//���ļ�ֻ��Ҫ����Ҫ��Ϊ��վ�ķ���������#include�Ϳ��ԣ�ͬʱӦ��ע�⺯�������ظ����壡
//write by JackyBoy for SNOW 1999/11/5
#include <ansi.h>

#define YIZHAN_INI "/clone/room/mache.ini"
#define TIME1 10
#define TIME2 15
//ע��mache��leave��arrive�����п��ܱ�reset����clean_up�����������ɱ�����ʧ��

//����qu �����û���κ��˴�����ֱ��call_out leave��ͬʱcall_out��ʱ���ϵĿ��ƺ���go_back
//����Ѿ����ˣ�������δ����ֱ��move����
void init()
{
	add_action("do_gu", "gu");
	add_action("do_qu", "qu");
}

int check_trigger(object me)
{
	object room, where;
	string *sites,*site,file;
	int i;
	where = environment(me);
	if( !(room = find_object("/clone/room/mache")) )
	room = load_object("/clone/room/mache");
	file = read_file(YIZHAN_INI);
	if(!file)
		return notify_fail("�Բ�����վ����û�з�վ����ʱ�޷�Ӫҵ��\n");
	else
		sites=explode(file,"\n");
	if( room = find_object("/clone/room/mache") )
	{
		if((int)room->query("che_trigger")==0)
		{
			message_vision("С���߽�һ��������ඣ�������δ�䣬С���Ѿ�ǣ��һ����ƥ�������ת�˳�����\n", me);
			message_vision("С��Ц��˵�������Ǻ�����������վ�ոտ��ţ���Ѵ�����\n"+
				"\t��˵ȥ�ľ�����(type qu XXX)��\n", me);
			message_vision("С��˵���������������µط����з�վ�������Թͳ�ȥ���\n",me);
			for(i=0;i<sizeof(sites);i++)
			{
				site=explode(sites[i],";");
				message_vision(site[0]+"("+site[1]+")\t",me);
				if((i+1)%3 == 0 )
					message_vision("\n",me);
			}
			message_vision("\n",me);
			me->set_temp("guche", 1);
		}        
		else 
			message_vision("С������Ǹ���˵������λ�͹٣����ڳ�����ȥ��,���Ȼ����?��\n", me);
	}
	else
		return notify_fail("�Բ������������ˣ�\n");
}

int do_gu(string arg)
{
	object me;
	me = this_player();
	if(!arg || (arg != "che" && arg !="��" && arg !="��"))
		return notify_fail("��Ҫ��ʲô������ֻ����(che)���Թ͡�\n");
	message_vision("$N�����Ű壬�е���ι�������𣿹ͳ�������\n", me);
	check_trigger(me);
	return 1;
}

int do_qu(string arg, int num)
{
	object room, me,where;
	string dest;int i;
	string *sites,*site,file;
	me=this_player(1);
	where = environment(me);
	if( !(room = find_object("/clone/room/mache")) )
		room = load_object("/clone/room/mache");
	if(!objectp(room))
		return notify_fail("ѽ��û�����ˣ�����ʦ����һ�°ɡ�\n");
	file = read_file(YIZHAN_INI);
	//����fileֵӦ�ò�Ϊ���ˣ�
	sites=explode(file,"\n");
	me = this_player();
	where = environment(me);
	if (!me->query_temp("guche"))
		return notify_fail("����û�������㣬������Լ���ɵ��\n");
	if (!arg)
		return notify_fail("�㵹��˵ȥ��ѽ��\n");
	dest="";
	for(i=sizeof(sites);i>0;i--)
	{
		site=explode(sites[i-1],";");
		if(site[1]==arg||site[0]==arg)//�������뺺�ֻ���Ӣ�ģ����Ǻ���һ�ɿ��������жϣ�
		{
			//�������ļ���Ѱ�������ȥ�ĵط��Ƿ���ڣ������������argΪ�õط���������
			arg=site[0];
			//��¼���������ļ�¼��sites����±�ֵ
			//��ȡĿ��ط����ļ���
			dest=site[2];
		}
	}
	if(dest=="")
		return notify_fail("�Բ���"+arg+"����û�з�վ��\n");
	if(dest==(base_name(this_object())) )
		return notify_fail("���Ѿ��������������㵽����ȥ���ﰡ����\n");
	if( room->query("che_trigger"))
	{
		message_vision("С����$N����Ǹ���˵������λ�͹٣����ڳ�����ȥ��,���Ȼ����?��\n", me);
		return 1;
	}
	else
	{
		message_vision("$N���������������˵����ȥ"+HIW+arg+NOR+"����\n\n", me);
		//����Ѿ��������������ж��Ƿ�ͬ·�������ֱ����·
		if(!room->query_temp("mached"))
		{
			message_vision("���Ц��˵�������õĿ͹٣����Ͼ���·����\n\n", me);
			room->set_temp("mached",arg);
			me->set_temp("mache_start",base_name(this_object()));
			call_out("leave", TIME1, me,room,dest);
			me->move("/clone/room/mache");
			return 1;
		}
		else
		{
			if(arg == (string)room->query_temp("mached") )
			{
				message_vision("���Ц��˵���������ó���Ŀ͹�ҲҪȥ������Ǿ�һ���߰ɣ������Ͼ���·����\n\n", me);
				me->set_temp("mache_start",base_name(this_object()));
				me->move("/clone/room/mache");
				room->set_temp("mached",arg);
				//call_out("leave", TIME1, me,room);
				message("vision",me->name() + "���������������˵����ȥ" + site[0] + "����\n\n", environment(me),({me}));
				message("vision","���Ц��˵���������ó���Ŀ͹�ҲҪȥ������Ǿ�һ���߰ɣ������Ͼ���·����\n\n", environment(me),({me}));
				return 1;
			}
			else
			{
				message_vision("����$NǸ���˵�����Բ�����λ�͹٣�����Ŀ͹ٲ�ȥ" + arg + "����,��������һ�Ȱɡ���\n\n",me);
				return 1;
			}
		}
	}
}

//��ʾ��������Ϣ������ʱ���õ��ﺯ��
int leave(object me,object room,string dest)
{
	message("vision","�������������˳���һ����ӣ���ඣ�ȥ"+room->query_temp("mached")+"ඣ�\n\n",environment(me));
	message("vision","��һ�ᣬ������ʧ�������⡣\n\n",environment(me));
	call_out("arrived",TIME2,me,room,dest);
	//�����н��еı�־
	room->set("che_trigger", 1);
	room->delete_temp("mached");
	return 1;
}

int arrived(object me,object room,string dest)
{
	int i;
	object *inv;
	inv = all_inventory(room);
	message_vision("\n������ͣ������������߽�һ�������ˣ�\n\n", me);
	if(room!=environment(me))
		write("����ѽ�����������������ѽ����ô���������ˣ�\n"+
			"һ����ʱ�մ�λ���Ͽ챨����ʦ�ɣ�\n");
	for(i=sizeof(inv);i>0;i--)
	{
		if(!inv[i-1]->move(dest))
			write("��Ҫȥ�ĵط��е����⣬�챨����ʦ��\n");
		message_vision("$N��������������\n\n",inv[i-1]);
		message("vision",inv[i-1]->name()+"������ȥ�ˡ�\n",room);
	}
	room->delete("che_trigger");
	room->delete("back_flag");
	me->delete_temp("guche");
	return 1;
}
