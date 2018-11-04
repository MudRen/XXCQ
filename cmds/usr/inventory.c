//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;
string total_inv(object*);
int main(object me, string arg)
{
	object *inv, ob;
	int opt;
	string str;
	//�������������
	opt=0;
	if(arg)
		sscanf(arg,"-%d %s",opt,arg);//opt��Ϊ0���ʾҪ��ϸ��Ϣ
	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}

	if( !ob ) ob = me;

	inv = all_inventory(ob);
	if( !sizeof(inv) ) {
		write((ob==me)? "Ŀǰ������û���κζ�����\n"
			: ob->name() + "����û��Я���κζ�����\n");
		return 1;
	}
	str=(ob==me)? "��": ob->name();
	str+="���ϴ���������Щ����(����"+
		(string)((int)ob->query_encumbrance() * 100/ (int)ob->query_max_encumbrance())+
		"%)��\n";
	str+=opt?implode(map_array(inv, "inventory_desc", this_object()), "\n"):total_inv(inv);
	me->start_more(str);
	return 1;
}

string total_inv(object* inv)
{
	mapping ni;//name&id�Ϳɷֱ���������Ƿ���ͬһ���ˣ��ļ����Ƿ���ͬ��������
	mapping ni_unit;//��������ni���Ӧ��ĵ�λ��
	object ob;
	string name,id,prop,str;
	int num;
	ni=([]);
	ni_unit=([]);//�����ʼ��
	foreach(ob in inv)
	{
		name=ob->name(1);
		id=ob->query("id");//��ʹ��ob->parse_command_id_list();
		prop=name+"_"+id;//������name+"/"+id???
		num=ob->query_amount();
		if(num==0)
			num=1;
		if(undefinedp(ni[prop]))
		{
			ni[prop]=num;//ͳ������
			if(!stringp(ni_unit[prop]=ob->query("base_unit")))//��¼��λ
				ni_unit[prop]=ob->query("unit");
			if(!stringp(ni_unit[prop]))
				ni_unit[prop]="Щ(��λ����!)";
			//��Ӧ�ü�¼װ������������������͵�������أ�
		}
		else
		{
			num=num+ni[prop];
			ni[prop]=num;
		}
	}
	//��ʼ�ϲ�ֵ��
	str="";
	foreach(prop in keys(ni))
	{
		if(sscanf(prop,"%s_%s",name,id)!=2)
		{
			log_file("inv" , "�������"+prop+"\n");
			continue;//����д���������
		}
		num=ni[prop];
		str+=chinese_number(num)+ni_unit[prop]+name+"("+id+")\n";
	}
	return str;
}

string inventory_desc(object ob)
{
	return sprintf("%s%s",
		ob->query("equipped")? HIC "��" NOR:"  ",
		ob->short()
	);
}

int help ()
{
        write(@HELP
ָ���ʽ: inventory [-num] [���ID]
 
���г���(��)Ŀǰ������Я����������Ʒ��
û�в���-num��numΪ����������ʾֻ��Ҫ�ۺ���ʾ�������ʾ��Ҫ��ϸ��ʾ��
���ID�������ֻ����ʦ����ʹ�ã�
ע : ��ָ����� " i " ���档
 
HELP
);
        return 1;
}
