//changan city

#include <ansi.h>
#include <room.h>
#include <command.h>
inherit ROOM;
int consider_lv(object ob,int a);

void create ()
{
        set ("short", "�ּ�С·");
        set ("long", @LONG
����һƬ�����֣����Ӻ��ܣ�ֻ����һ��С·���ֶ�����һЩ����͸
���������ڵ��ϣ���������������������ֲ�����ָ�ġ��ݹ�����·��˵
����ʱ��ǿ�˳�û����ȡ��������������Ϳ��Ե��ɻ����ˡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"tulu",
		"south" : __DIR__"treeroad2",
       ]));

        set("outdoors", "huayang");
        setup();
}

void init()
{
	object me, ob;
	mapping myfam;

	me = this_player();
	myfam = me->query("family");

	if ( myfam = me->query("family") && (myfam["family_name"] == "佻�����") && random(100) < 15 )
	{
		message_vision(HIY"ͻȻ���ϴ���һ����Ц����һ����ƣ�һ���󺺴�����Ծ��������\n"NOR, me);
		message_vision(HIY"�󺺴��һ���������佻������������䵽���������㵹ù���������ɣ�����\n"NOR, me);
		ob = new(__DIR__"npc/jiefei");
		ob->set("combat_exp",me->query("combat_exp") * 9 / 10);
		ob->set("max_qi",me->query("max_qi"));
		ob->set("eff_qi",me->query("max_qi"));
		ob->set("qi",me->query("max_qi"));
		ob->set("max_jingli",me->query("max_jingli"));
		ob->set("eff_jingli",me->query("max_jingli"));
		ob->set("jingli",me->query("max_jingli"));
		ob->set("max_neili",me->query("max_neili"));
		ob->set("neili",me->query("max_neili"));
		ob->set_skill("force", consider_lv(ob, 8));
		ob->set_skill("strike", consider_lv(ob, 8));
		ob->set_skill("cuff",consider_lv(ob, 8));
		ob->set_skill("dodge", consider_lv(ob, 8)); 
		ob->set_skill("whip", consider_lv(ob, 8)); 
		ob->set_skill("spear", consider_lv(ob, 8)); 
		ob->set_skill("axe", consider_lv(ob, 8)); 
		ob->set_skill("club", consider_lv(ob, 8)); 
		ob->set_skill("stick", consider_lv(ob, 8)); 
		ob->set_skill("sword", consider_lv(ob, 8)); 
		ob->set_skill("staff", consider_lv(ob, 8)); 
		ob->set_skill("blade", consider_lv(ob, 8)); 
		ob->set_skill("parry", consider_lv(ob, 8)); 
		ob->set_skill("literate", consider_lv(ob, 8));
		ob->set("shen",-(me->query("combat_exp")/20));
		ob->move(environment(me));
		ob->kill_ob(me);
		me->kill_ob(ob);
		me->set_temp("jiefei",1);
	}
	return;
}

int consider_lv(object ob,int a)
{
	int level; 
	float exper;

	exper = to_float(ob->query("combat_exp"));
	level = ceil( pow( exper*10.0, 0.333333) );

	level = level * a / 10;

	return level;
}

int valid_leave(object me, string dir)
{

	if (  ((dir == "south")||(dir == "north"))
	   && me->query_temp("jiefei") == 1
	   && objectp(present("bang zhong", environment(me))) )
	{
		message_vision("��һ����$N�������������ߣ�û��ô���ף�����", me);
		return notify_fail("\n");
	}
	me->delete_temp("jiefei");
	return ::valid_leave(me, dir);
}