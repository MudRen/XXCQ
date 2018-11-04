/* autosave daemon
 * author : ken@XAJH
 * create time: 98-10-27
 */

#include <ansi.h>
#define DEBUG "debug"
inherit F_DBASE;

void auto_save(int);
void remove();
 
void create()
{
	seteuid(getuid());
	set("channel_id", "�Զ����̾���");

	CHANNEL_D->do_channel( this_object(), "sys", "�Զ����̷���ɹ���\n");

	remove_call_out("auto_save");
	call_out("auto_save", 10, 0);
}

void auto_save(int head)
{
	int i;
	object *ob, link_ob;
	string id, *title =
 ({ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", 
    "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" });

	seteuid(getuid());
#ifdef DEBUG
	CHANNEL_D->do_channel( this_object(), DEBUG, sprintf("���ڴ��� %s ��ͷ�� ID ����.",title[head]) );
#endif
	ob = users();
	i = sizeof(ob);
	while(i--) {
		id = (string) ob[i]->query("id");
		if (!id) continue;
		if( id[0..0] != title[head] )   continue;
		if(!environment(ob[i]) )        continue;
		if( !objectp(link_ob = ob[i]->link() ) )  continue;
		link_ob->save();
		ob[i]->save();
		tell_object(ob[i], HIR"�����̾��顿"HIY"��ĵ����Ѿ��Զ������ˡ�\n"NOR);
	}
	if( head == sizeof(title) -1 )
		head = 0;
	else
		head ++;

	remove_call_out("auto_save");
	call_out("auto_save", 20+random(10), head);
}

void remove() {
	CHANNEL_D->do_channel( this_object(), "sys", "�Զ����̷���ȡ����\n");
	return;
}