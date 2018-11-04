#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIR "��" HIC "��" HIG "��" HIB "��" NOR,
                ({"cake","dan gao","gao"}));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", @LONG
     һ���ش�ĵ��⣬�����������������ͣ�������Ϊ������Լ����շ�����ҵġ�
     ���ͬϲͬϲ���Ǻǣ�
LONG);
                set("unit", "��");
                set("value", 100000);
        }
}
string chinese_time(int type,string get_time)
{
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
		"Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});

        if ( stringp(get_time) )
                e_time = get_time;
        else e_time = ctime(time());

        // e_time must is ctime(time string) like "Sun May  3 00:52:12 1998"
        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);

        c_week  = chinese_number(member_array(week, week_name) + 1);
        c_month = chinese_number(member_array(month, month_name) + 1);

        c_year  = sprintf("%s%s%s%s",
                         chinese_number(year[0]-48),
                         chinese_number(year[1]-48),
                         chinese_number(year[2]-48),
                         chinese_number(year[3]-48));

        c_year = c_year + "��";
        c_month  = c_month + "��";
        c_week = " ����"+c_week;

        c_time = chinese_number(day) + "��";
        c_time += chinese_number(hour) + "��";
        c_time += chinese_number(minute) + "��";
        // maybe not need srcond to show
        // c_time += chinese_number(second) + "��";

        if (type) {
                switch( type ) {
                        case 1: return c_year+c_month+c_time+c_week;
                        case 2: return c_year+c_month+c_time;
                        case 3: return c_month+c_time+c_week;
                        case 4: return c_month+c_time;
                        case 5: return year+"��"+(member_array(month, month_name) + 1)+
				"��"+day+"��"+hour+"��"+minute+"��";
                        case 6: return (member_array(month, month_name) + 1)+
				"��"+day+"��"+hour+"��"+minute+"��";
                        default: return c_year+c_month+c_time+c_week;
                        }
                }
        return c_year+c_month+c_time+c_week;
}
void init()
{
	add_action("do_eat","eat");
	add_action("do_eat","chi");
}

int do_eat(string arg)
{
	string rtime,skill;
	mapping skl;
	int max;
	object me=this_player();
	if(!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	rtime=chinese_time(1,(string)localtime(time()));
	message_vision("$N����һ��"+name(1)+"��Ҫ�ԡ�\n",this_player());
	if(strsrch(rtime,"��������")!=-1)
	{
		//���Գ����
		max = me->query("max_jingli");
		me->set("eff_jingli",max);
		me->set("jingli",max);
		max = me->query("max_jing");
		me->set("eff_jing",max);
		me->set("jing",max);
		max = me->query("max_neili");
		me->set("eff_neili",max);
		me->set("neili",max);
		max = me->query("max_qi");
		me->set("eff_qi",max);
		me->set("qi",max);
		max = me->query("max_shen");
		me->set("eff_shen",max);
		me->set("shen",max);
		max = me->max_food_capacity();
		me->set("food",max);
		max = me->max_water_capacity();
		me->set("water",max);
		me->clear_condition();
		if(!this_player()->query("bir19990605"))
		{
			me->set("bir19990605",1);
			me->add("combat_exp",me->query("combat_exp")/20);
			me->add("potential",5000);
			me->add("max_neili",me->query("max_neili")/20);
			me->add("max_jingli",me->query("max_jingli")/20);
			me->add("str",me->query("str")/10);
			me->add("int",me->query("int")/10);
			me->add("per",me->query("per")/10);
			me->add("con",me->query("con")/10);
			me->add("dex",me->query("dex")/10);
			skl=me->query_skills();
			if(mapp(skl))
				foreach(skill in keys(skl))
					me->set_skill(skill,(int)(me->query_skill(skill,1)*21/20));
		}
		message_vision("$N���ھͰ�"+name(1)+"�������ˣ�ֱ���û���Ĺ������綼�����˺ܶࡣ\n",me);
		destruct(this_object());
	}
	else
	{
		write("��ѽ����������ˣ����ܳ��ˣ�\n");
		message_vision("$Nѽ�ؼ��һ��������һ����ڵĵ���������\n",this_player());
		set("name",HIR"���ڵĵ���"NOR);
		set("value",10);
		move(environment(this_player()));
	}
	return 1;
}