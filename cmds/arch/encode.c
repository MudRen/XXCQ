// update.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int update_player(object);

int main(object me, string file)
{
	int i;
	object obj, *inv;
	string err,bfile;

	seteuid( geteuid(me) );

	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("��Ҫ���±���ʲ�ᵵ����\n");

	if( (obj = present(file, environment(me))) && interactive(obj) )
		return update_player(obj);

	if( file == "me" )
		return update_player(me);
	else {
		file = resolve_path(me->query("cwd"), file);
		if( !sscanf(file, "%s.c",bfile) )
		{
			bfile=file+".b";
			file += ".c"; 
		}
		else
			bfile=bfile+".b";	
	}

	if( file_size(file)==-1 )
		return notify_fail("û�����������\n");
	if( file_size(bfile)!=-1)
	{
		write("ɾ��binaries�ļ���\n");
		rm(bfile);
	}
	me->set("cwf", file);

	if (obj = find_object(file)) {
		if( obj==environment(me) ) {
			//�������С�����
			write("��������...\n");
			if( file_name(obj)==VOID_OB )
				return notify_fail("�㲻���� VOID_OB �����±��� VOID_OB��\n");
			inv = all_inventory(obj);
			i = sizeof(inv);
			while(i--)
				if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
				else inv[i] = 0;
		}
		destruct(obj);
	}

	if (obj) return notify_fail("�޷�����ɳ�ʽ�롣\n");

    write("���±��� " + file + "��");
	err = catch( call_other(file, "???") );
	if (err)
		printf( "��������\n%s\n", err );
	else {
		write("�ɹ���\n");
		if( (i=sizeof(inv)) && (obj = find_object(file))) {
			while(i--)
				if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1);
		}
	}
		
	return 1;
}

int update_player(object me)
{
	object env, link_ob, obj;

	env = environment(me);

	// First, create the new body.
	link_ob = me->query_temp("link_ob");
	if(!objectp(link_ob))
		return notify_fail("query_temp(link_ob)����!\n");
	if(!link_ob->query("body"))
		return notify_fail("query link_ob's body prop error!\n");
	write("body file: "+link_ob->query("body")+"\n");
	obj = LOGIN_D->make_body(link_ob);
	if (!obj) return 0;

	// Save the data and exec the player to his/her link object.
	me->save();
	exec(link_ob, me);
	destruct(me);

	// Restore new body and exec to it via enter_world in LOGIN_D
	obj->restore();
	LOGIN_D->enter_world(link_ob, obj, 1);

	write("���������ϡ�\n\n");
	obj->move(env);
	obj->write_prompt();

	return 1;
}

int help()
{
  write(@HELP
ָ���ʽ : update <����|here|me|�����>
 
���ָ����Ը��µ���, �����µ������������������. ��Ŀ��Ϊ
'here' ��������ڻ���. ��Ŀ��Ϊ 'me' ������Լ�������. ��Ŀ
��Ϊ�����ɸ���������.
 
HELP
    );
    return 1;
}
 
