// recruit.c

#include <ansi.h>

inherit F_CLEAN_UP;

void punish( object);

int main(object me, string arg)
{
	object ob, old_rec;
	mapping family;

	if( !arg ) 
		return notify_fail("ָ���ʽ��recruit|shou [cancel]|<����>\n");

	if( arg=="cancel" ) {
		old_rec = me->query_temp("pending/recruit");
		if( !objectp(old_rec) )
			return notify_fail("�����ڲ�û����¼�κ���Ϊ���ӵ���˼��\n");
		write("��ı����ⲻ����" + old_rec->name() + "Ϊ�����ˡ�\n");
		tell_object(old_rec, me->name() + "�ı����ⲻ������Ϊ�����ˡ�\n");
		me->delete_temp("pending/recruit");
		return 1;
	}

	if( !(ob = present(arg, environment(me))) )
		return notify_fail("������˭�����ӣ�\n");

	if( ob==me ) return notify_fail("���Լ�Ϊ���ӣ�������....����û���á�\n");

	if( ob->is_apprentice_of(me) ) {
		message_vision("$N����$n��ͷ��˵��������ͽ������\n", me, ob);
		return 1;
	}

	if( !me->query("family") )
		return notify_fail("�㲢�������κ����ɣ�������ȼ���һ�����ɣ����Լ���һ��������ͽ��\n");

	// If the target is willing to apprentice us already, we do it.
	if( (object)ob->query_temp("pending/apprentice") == me ) {

		if( !living(ob) ) {
			message_vision(
				"$N������$nΪ���ӡ�\n\n"
				"����������$n��Ȼû�а취�а�ʦ֮��\n\n",
				me, ob);
			return 1;
		}
	// follow modified by elon 09-10-95 to fix a bug in 1st time recruit
		if((ob->query("family")) && ( (string)me->query("family/family_name") != (string)ob->query("family/family_name") ) ) {
			message_vision(
				"$N��������ʦ�ţ���Ͷ��$n���£���\n\n"
				"$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������\n\n",
				ob, me);
			ob->set("score", 0);
			ob->add("betrayer", 1);
			punish(ob);
		} else
			message_vision(
				"$N������$nΪ���ӡ�\n\n"
				"$n����������$N���������ؿ����ĸ���ͷ���е�����ʦ������\n",
				me, ob);

		me->recruit_apprentice(ob);
		ob->delete_temp("pending/apprentice");

		write("��ϲ��������һ�����ӣ�\n");
		family = ob->query("family");
		tell_object( ob, sprintf("��ϲ����Ϊ%s�ĵ�%s�����ӡ�\n", family["family_name"],
			chinese_number(family["generation"]) ));

		return 1;
	

	} else {

		old_rec = me->query_temp("pending/recruit");
		if( ob==old_rec )
			return notify_fail("������" + ob->name() + "Ϊ���ӣ����ǶԷ���û�д�Ӧ��\n");
		else if( objectp(old_rec) ) {
			write("��ı����ⲻ����" + old_rec->name() + "Ϊ�����ˡ�\n");
			tell_object(old_rec, me->name() + "�ı����ⲻ������Ϊ�����ˡ�\n");
		}

		me->set_temp("pending/recruit", ob );
		message_vision("\n$N��Ҫ��$nΪ���ӡ�\n", me, ob);
		tell_object(ob, YEL "�����Ը���" + me->name() + "Ϊʦ������ apprentice ָ�\n" NOR);
		return 1;
	}
}

void punish( object me)
{	int i;
	mapping skill_status;	
	string *sname;

	if ( !(skill_status = me->query_skills()) ) return;
      sname  = keys(skill_status);

      for(i=0; i<sizeof(skill_status); i++) {
         me->set_skill(sname[i], skill_status[sname[i]]/2);
        }
	
	return;
}


int help()
{
        write(@HELP
ָ���ʽ : recruit|shou [cancel]|<����>
 
���ָ����������ĳ��Ϊ����, ����Է�Ҳ��ӦҪ����Ϊʦ�Ļ�.
 
See Also:	apprentice
HELP
        );
        return 1;
}
