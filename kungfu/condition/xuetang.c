// xuetang.c

#include <ansi.h>

string *reject_msg = ({
	"���ɵ����ǳ��������������ǳ�����\n",
	"�������֮ʼ����������֮ĸ��\n",
	"�ʳ��ޣ����Թ�������У����Թ����衣\n",
	"�����ߣ�ͬ����������ͬν֮������֮����������֮�š�\n",
	"���½�֪��֮Ϊ����˹���ѡ���֪��֮Ϊ�ƣ�˹�����ѡ�\n",
	"��ز��ʣ�������Ϊۻ����ʥ�˲��ʣ��԰���Ϊۻ����\n",
	"���֮�䣬�������ߺ����������������������\n",
	"�쳤�ؾá���������ܳ��Ҿ��ߣ����䲻���������ܳ�����\n",
	"������ˮ��ˮ���������������������֮���񣬹ʼ��ڵ���\n",
	"��ν������������Ϊ�£���֮������ʧ֮��������ν����������\n",
	"�ʹ�����Ϊ���£����ɼ����£�������Ϊ���£����������¡�\n",
});

string *reject_msg_2 = ({
	"�ռ���ɫ��ɫ���ǿա�\n",
	"���ƣ��Ҳ��������˭�������\n",
	"�϶϶ϣ��Ĵ�Կգ���ȴһ����Ե��\n",
	"���������ܡ����������ܡ�\n",
	"���᱾�������������̨��������һ��δ��ǳ�����\n",
});

int update_condition(object me, int duration)
{
	if ((int)me->query("jingli")<40)
	{
		if (me->query("family") && me->query("family/family_name")=="������")
			message_vision("$Nʵ����̫ƣ���ˣ�ֻ�ø���ͥ�����ж������ѧϰ��\n\n", me);
		else
			message_vision("$Nʵ����̫ƣ���ˣ�ֻ�ø����������ж������ѧϰ��\n\n", me);
		me->apply_condition("xuetang", 0);
		me->delete_temp("xuet");
		return 0;
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
	{
		if (me->query("family") && me->query("family/family_name")=="������")
			message_vision("$N����û��������ѧ��ȥ�ˣ�ֻ�ø���ͥ�����ж������ѧϰ��\n\n", me);
		else
			message_vision("$N����û��������ѧ��ȥ�ˣ�ֻ�ø����������ж������ѧϰ��\n\n", me);
		me->apply_condition("xuetang", 0);
		me->delete_temp("xuet");
		return 0;
	}

	me->add("jingli", ((int)me->query("int")-50));
	me->add("learned_points", 1);
	me->apply_condition("xuetang", duration - 1);
	me->improve_skill("literate", ((int)me->query("int") + random((int)me->query("int"))));
	if (me->query("family") && me->query("family/family_name")=="������")
		message_vision("$N��ʮĬ�"+ reject_msg_2[random(sizeof(reject_msg_2))], me);
	else
		message_vision("$Nҡͷ���Ե������"+ reject_msg[random(sizeof(reject_msg))], me);

	if ( duration < 1 )
	{
		if (me->query("family") && me->query("family/family_name")=="������")
			message_vision("\n��ͥ����ĳ�$N���ͷ���������ӷ𣬽���͵�����ɡ�\n\n", me);
		else
			message_vision("\n��������ĳ�$N���ͷ�����ú��ӣ�����������͵�����ɡ�\n\n", me);
		me->delete_temp("xuet");
		return 0;
	}
	return 1;
}