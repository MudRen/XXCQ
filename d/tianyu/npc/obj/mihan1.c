#include <ansi.h>
inherit ITEM;
int do_songxin(string arg);
void create()
{
	set_name(RED"�ܺ�"NOR, ({ "mi han", "letter" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ���ú�Ƥ��õ��ܺ���(song xxx)\n");
		set("value", 100);
		set("material", "steel");
	}
	setup();
}
void init()
{
        add_action("do_songxin","song");
        add_action("do_kan","read")
;
}
int do_songxin(string arg)
{
	object who,me,where;
	int exp,exp1,pot,pot1;
	exp=80+random(50);
	exp1=350+random(100);
	pot=30+random(30);
	pot1=150+random(60);
	me=this_player();
	where = environment(me);
	if(!arg||arg=="")
	return notify_fail("��Ҫ���ܺ���˭��\n");
	if(!objectp(who = present(arg, environment(me))) || !living(who))
        return notify_fail("����û������ˡ�\n");
        if(who->query("name")!=this_object()->query("human"))
        return notify_fail("������Ų����͸����ġ�\n");
        if (file_name(where)!=this_object()->query("where"))
        return notify_fail("�������̫�����ˣ������͵����͵ĵط�ȥ�ɡ�\n");
        if (!me->query_temp("do_job2"))
        {
        	message_vision(HIW"$N���ܺ����������Ľ�����$n��\n"NOR,me,who);
        	message_vision(HIR"$n���˿��ܺ���ͻȻ��$N���һ�������㾹Ȼ�Ҽ�ð�ܺ����������ɣ���\n"NOR,me,who);
        	who->kill_ob(me);
        	destruct(this_object());
                return 1;
        }	
        if(me->query_temp("jiefei_1"))
        {
        	message_vision(CYN"$N��"+RED+"�ܺ�"+CYN+"���������Ľ�����$n�� \n"NOR,me,who);
                message_vision(CYN"$n���˿�"+RED+"�ܺ�"+CYN+"����Ķ�$N���˵�ͷ˵������$N��ת�����ʦ������ʱһ�����ᡱ\n"NOR,me,who);
        	tell_object(me,HIW"�㱻������"+chinese_number(exp1)+"�㾭�顣\n�㱻������"+chinese_number(pot1)+"��ǳ�ܡ�\n"NOR);
        	me->add("combat_exp",exp1);
                me->add("potential",pot1);
                me->delete_temp("do_job2");
                me->delete_temp("jiefei_1");
                me->apply_condition("do_songxin", 0);
                destruct(this_object());
                return 1;
        }
        message_vision(CYN"$N��"+RED+"�ܺ�"+CYN+"���������Ľ�����$n�� \n"NOR,me,who);
        message_vision(CYN"$n���˿�"+RED+"�ܺ�"+CYN+"����Ķ�$N���˵�ͷ˵��������ת�����ʦ������ʱһ�����ᡱ\n"NOR,me,who);
        tell_object(me,HIW"�㱻������"+chinese_number(exp)+"�㾭�顣\n�㱻������"+chinese_number(pot)+"��ǳ�ܡ�\n"NOR);
        me->delete_temp("do_job2");
        me->start_busy(3);        
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->apply_condition("do_songxin", 8);
        destruct(this_object());
        return 1;
}         

int do_kan(string arg)
{
         if(!arg||arg=="")
       return 0;
       if(arg=="mi han")
        {
        tell_object(this_player(),"����һ���ú�Ƥ��õ��ܺ�������д��"+this_object()->query("human")+"���ա�\n");
        return 1;
        }
}
