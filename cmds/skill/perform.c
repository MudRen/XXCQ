// perform.c

inherit F_CLEAN_UP;

mapping valid_types = 
([
	"finger":   "ָ��",
	"hand":     "�ַ�",
	"cuff":     "ȭ��",
	"claw":     "צ��",
        "club":     "����",
	"strike":   "�Ʒ�",
]);

int main(object me, string arg)
{
	object weapon;
	mapping smap, pmap; 
	string martial,skill;
	
	seteuid(getuid());
	
	smap = me->query_skill_map();

	pmap = me->query_skill_prepare();

	if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");

	if( !arg ) return notify_fail("��Ҫ���⹦��ʲ�᣿\n");

	if( sscanf(arg, "%s.%s", martial, arg)!=2 ) {
		if( weapon = me->query_temp("weapon") )
			martial = weapon->query("skill_type");
		else if ( sizeof(pmap) == 0) martial = "unarmed";
		else if ( sizeof(pmap) == 1) martial = (keys(pmap))[0];
		else if ( sizeof(pmap) == 2) martial = (keys(pmap))[me->query_temp("action_flag")];
	}

	if( stringp(skill = me->query_skill_mapped(martial)) ) {
		notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
		if( SKILL_D(skill)->perform_action(me, arg) ) {
			if( random(120) < (int)me->query_skill(skill) )
				me->improve_skill(skill, 1, 1);
			return 1;
		} else if( SKILL_D(martial)->perform_action(me, arg) ) {
			if( random(120) < (int)me->query_skill(martial, 1) )
				me->improve_skill(martial, 1, 1);
			return 1;
		}
		return 0;
	}

	return notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��⹦��\n");
}

int help ()
{
        write(@HELP
ָ���ʽ��perfrom [<�书����>.]<��ʽ����> [<ʩ�ö���>]

�������ѧ���⹦(ȭ�š�����������....)��һЩ����Ĺ�����ʽ����ʽ������
�����ָ����ʹ�ã���������� enable ָ��ָ����ʹ�õ��书����ָ���书��
��ʱ�����ֵ��⹦��ָ���ȭ�Ź���ʹ������ʱ���Ǳ��е��书��

��������⹦�������಻ͬ��������ʽ������ͬ�ģ����߲����ȭ�Ÿ���������
���书(���Ṧ)�������� <�书>.<��ʽ>  �ķ�ʽָ�����磺

perform taiji-jian.chan

or

perform chan

���仰˵��ֻҪ�� enable �е��书��������ʽ�ģ������������ָ��ʹ�á�
HELP
        );
        return 1;
}
