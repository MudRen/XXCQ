// tune.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *tuned_ch;
	string target,name;
	object ob;

	tuned_ch = me->query("channels");

	if( !arg ) {
		if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
			write("�����ڲ�û�������κ�Ƶ����\n");
		else
			write("������������Ƶ����" + implode(tuned_ch, ", ") + "��\n");
		return 1;
	}

	if (arg[0..5]=="notell")
	{
		if (arg=="notell")
		{
		me->set_temp("notell_all",1);
		write("�㿪ʼ�����ܱ��˵����Ļ��ˡ�\n");
		return 1;
		}
		sscanf(arg,"notell %s",target);
		if(!ob=find_player(target)) 
		return notify_fail("����˲����ߣ����ǲ����ڡ�\n");
		name=ob->query("name");
		me->set_temp("notell/"+target,name);
  		write("�㿪ʼ������"+name+"�����Ļ��ˡ�\n");
		return 1;
	}
	if (arg[0..3]=="tell")
	{
		if (arg=="tell")
		{
		me->delete_temp("notell_all");
		write("�㿪ʼ���ܱ��˵����Ļ��ˡ�\n");
		return 1;
		}
		sscanf(arg,"tell %s",target);
		if (!name=me->query_temp("notell/"+target))
		return notify_fail("�㲢û�йرպ�����˵Ľ�̸Ƶ����\n");
		me->delete_temp("notell/"+target);
		write("��������½���"+name+"�����Ļ�\n");
		return 1;
	}
	if(me->query("age")<15)
		return notify_fail("�����ڻ�С���޷��ر�Ƶ����\n");
		
	if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 ) {
		write("�ر� " + arg + " Ƶ����\n");
		tuned_ch -= ({ arg });
		me->set("channels", tuned_ch);
		return 1;
	} else {
		write("Ҫ��ĳ��Ƶ��ֻҪ�ø�Ƶ��˵�����ɡ�\n");
		return 1;
	}
}

int help()
{
	write(@HELP
ָ���ʽ��tune [<Ƶ������>]

���ָ������ѡ���Ƿ�Ҫ����ĳһƵ����ѶϢ�����û��ָ��Ƶ�����ƣ��ͻ��г�
��Ŀǰ�����е�Ƶ�������ָ����Ƶ����ԭ�������еľͻ�ص�����֮�򿪡�

������һ��û�������е�Ƶ�����������Զ������򿪡�
Ҫ��һ��Ƶ��������ֻҪ�ã�

<Ƶ������> <ѶϢ> ....

���ӣ�
  chat hello everyone!
  
������� help channels ��ѯĿǰ����ЩƵ������������

���⻹���������رպ�ĳ�˵Ľ�̸Ƶ��
����:
tune notell �����������˵�tell��
tune notell <ĳ��ID>  ������ĳ�˵�tell��
tune tell   ��ʼ���������˵�tell
tune tell <ĳ��id>  ��ʼ����ĳ�˵�tell
ע�⣺�����ָ���ر���ĳ���˵�tell,tune tell������򿪶�������tell
����ָ�����ܴ򿪡�

see also : shout
HELP
	);
	return 1;
}

