//		clone/linghou.c  writen by winder for sotw

inherit ITEM;
#include <ansi.h>

void create(object me,string arg)
{
	set_name(HIR "���" NOR, ({"huo"}));
        set("unit", "ö");
	set("long", "����һö��������������ͨѶ������Ļ�����\nָ���ʽ : hu <ĳ��>/<all>\n");
        setup();
}

void init()
{
        add_action("do_fire", "hu");
}

int do_fire(string arg)
{
	object me, who, *whose, where, wwhere;
	int i, mount;
	string name, family, wfamily;

	me = this_player();
	where = environment(me);
	name = (string) me->query("name");
	family = (string) me->query("family");

	if ((int) me->query("neili") < 20)
		return notify_fail(HIY"�����������Խ������ȼ��\n"NOR);

	if( !arg)
		return notify_fail("��Ҫ��ʲô��\n");
	else
	{
		if( arg == "all") 

//	��Ҫ��ѯ����б�û������ me->query("family") == "" 		//

			if ( me->query("family") == "" )
				return notify_fail(HIY"�㲻���κΰ��ɵĵ��ӣ�û��ͬ��ʦ�ֵܿ��Ժ��У�\n"NOR);
			else
			{
				message_vision(HIR "\n$N�Ի���ȡ��һö���ɫ�������������ָ�⣬��������е�ȥ��\n" NOR, me);
				message_vision(HIR "\n�����Ŵ̶��ļ�����������������ѿ�������һֻ�ʺ�Ķ������þ��Բ���ɢ��\n" NOR, me);
				message_vision(HIR "\n��֪ʦ�ֵ��ܲ��ܼ�ʱ�ϵ����\n" NOR, me);
				whose = users();
				for (i; i < sizeof(whose); i++)
				{	// Skip those users in login limbo.
					if( !environment(whose[i]) && !me->visible(whose[i]) )
						continue;
					else
					{
						wfamily = (string) whose[i] -> query("family");
						if ((family == wfamily) && (me != whose[i]))
//							tell_object(whose[i], HIR"\n����һ̧ͷ������" + (string)where->query("short")+ "���Ͽ�����һ���ʺ�ɫ�ľ�����\n\n������ͬ��ʦ�ֵ�" + (string)me->query("name") + "����Σ���ˣ�\n" NOR);
							tell_object(whose[i], HIR"\n����һ̧ͷ������" + (string)where->query("short")+ "���Ͽ�����һ���ʺ�ɫ�ľ�����\n\n������ͬ��ʦ�ֵ�����Σ���ˣ�\n" NOR);
						else
							continue;
					}
				}
				me->set("neili", me->query("neili")-20);
				destruct(this_object());
				return 1;
			}
		else
		{
			who = LOGIN_D->find_body(arg);
			if ( me == who)
				return notify_fail(HIY"�Լ������Լ������в��ɣ�\n"NOR);
			if ( !who || !environment(who))
				return notify_fail(HIY"û�������һ���δ�����ϣ�\n"NOR);
			else
			{
				wwhere = environment(who);
				if ( (string)where == (string)wwhere)
				{
					tell_object(me,HIY"������ߣ�������ô�Ѿ��ɣ�\n"NOR);
					return 1;
				}
				else
				{
					message_vision(HIR "\n$N�Ի���ȡ��һö���ɫ�������������ָ�⣬��������е�ȥ��\n" NOR, me);
					message_vision(HIR "\n�����Ŵ̶��ļ�����������������ѿ�������һֻ�ʺ�Ķ������þ��Բ���ɢ��\n" NOR, me);
					message_vision(HIR "\n��֪" + (string)who->query("name") + "�ܲ��ܼ�ʱ�ϵ����\n" NOR, me);
					tell_object(who,HIR "\n����һ̧ͷ������" + (string)where->query("short")+ "�Ͽ�����һ���ʺ�ľ�����\n\n����" + (string)(me->query("name")) + "����Σ����Ҫ���æ��\n" NOR);
//					tell_object(who,HIR "\n����һ̧ͷ������" + (string)where->query("short")+ "�Ͽ�����һ���ʺ�ľ�����\n\n��������Σ����Ҫ���æ��\n" NOR);
					me->set("neili",me->query("neili")-20);
					destruct(this_object());
					return 1;
				}
			}
		}
	}
}

int help (object me)
{
	write(@HELP
ָ���ʽ : hu <ĳ��>/<all>
���ָ���������κ����(�����Լ����ɵ�������)��ȡ�
HELP);
	return 1;
}
