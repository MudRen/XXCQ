// heal command..

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string str)
{
	object ob;
	if (!str) return notify_fail("��ʽ��heal <ĳ��ID>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("��... ���������?\n");
	tell_object(me, HIC"���������䣺���������壬���������壡�����ţ������Ĺ�����ѽ����\n"NOR );
	tell_object(ob, HIY"��ֻ��һ�����������ķΣ���ʱ���е��˿ڶ���ԭ�ˣ�������ɷ��������ˬ�����������˸��������ˡ�\n"NOR );
	ob->set_temp("nopoison", 1);
	ob->set("jingli",ob->query("max_jingli"));
	ob->set("eff_jingli",ob->query("max_jingli"));
	ob->set("eff_qi",ob->query("max_qi"));
	ob->set("qi",ob->query("max_qi"));
	ob->set("neili",ob->query("max_neili"));
	ob->set("douzhi",ob->query("max_douzhi"));
	write_file("/log/cmds/HEAL_PLAYER",sprintf("%s Ϊ %s ���� on %s\n",
	this_player()->name(1),ob->name(1), ctime(time()) ));
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : heal <ĳ��>


��ָ�������(��)��ĳ�˵�����״̬�ָ���
HELP
    );
    return 1;
}
