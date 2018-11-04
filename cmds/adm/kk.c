
#include <command.h>

inherit F_CLEAN_UP;

void create() 
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	int i;
	object ob;
	object *inv;
	int force=0,lob=0;
                        
    if (!arg) return 0; 
    if(sscanf(arg,"-l %s",arg)==1)
    	lob=1;
    if(sscanf(arg,"-f %s",arg)==1)
    	force=1;//������ǿ���˳�
    if(lob)
    {
		ob=LOGIN_D->find_body(arg);
		if(!objectp(ob))
			return notify_fail("ʧ�ܣ��޷��ҵ�"+arg+"\n");
		destruct(ob);
		write("���"+arg+"��\n");
		ob = present(arg, environment(me));
		if(objectp(ob))
			destruct(ob);
    	return 1;
    }
	ob=find_player(arg);
	if (!ob) return notify_fail("û������ˣ�"+arg+"\n");
	if( !wizardp(ob) ) {
		inv = all_inventory(ob);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(ob, inv[i]);
	}
	CHANNEL_D->do_channel(this_object(), "sys",
		me->name()+"��"+ob->name() + "(" + ob->query("id") + ")�߳�����Ϸ��");
          CHANNEL_D->do_channel(this_object(), "rumor",
                ob->name() + "��ϵͳ�߳�����Ϸ��");
	if(!force)
		ob->save();
	destruct(ob);
	return 1;
}
