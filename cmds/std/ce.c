// ce.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help();
void create() {seteuid(getuid());}

int main(object me, string arg)
{
      object obj;

      if(!me->query("couple/have_couple")) return help();

	obj = find_player(me->query("couple/couple_id"));

	if(!obj || (!wizardp(me) && !me->visible(obj)))
                return notify_fail("��İ������ڲ���....\n");

	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("��İ������ڹ������������Ļ�....\n");

	if( !arg ){
//        if((string)me->query("gender") == "Ů��") 
        message_vision(MAG "\n$N��ô˼��"+me->query("couple/couple_gender")
                          +me->query("couple/couple_name")+"��...\n"NOR, me);
//        else
//        message_vision(MAG "\n$N��ô˼������"+me->query("couple/couple_name")+"��...\n"NOR, me);

 tell_object(obj,sprintf(MAG"���"+obj->query("couple/couple_gender")+"��˼����... ...\n" NOR));
                }
      else {
       if( arg == "kiss" ) {

        if( objectp(present(me->query("couple/couple_id"), environment(me))) )
        message_vision(MAG "\n$Nӵ����$n�����һ��...\n"NOR, me,obj);
        else {
       write(MAG "�����ӵ�����" + me->query("couple/couple_gender") + "�����һ��...\n" NOR);
	  tell_object(obj, sprintf( MAG "���%s����ӵ���㣬���������һ��... ...\n" NOR,
	 	  obj->query("couple/couple_gender"))); } }

       else {
	  write(MAG "�����ĸ������" + me->query("couple/couple_gender") + "��" + arg + "\n" NOR);
	  tell_object(obj, sprintf( MAG "���%s���ĸ����㣺%s\n" NOR,
	 	  obj->query("couple/couple_gender"), arg)); }
           }

	return 1;
}

int help()
{
	write(@HELP
ָ���ʽ��ce [kiss][<ѶϢ>]

����������ָ�����İ���˵���Ļ���

HELP
	);
	return 1;
}
