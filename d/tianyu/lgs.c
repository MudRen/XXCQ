// Room: ������
// Date: by godzilla 1999.11.18

int do_xiulian();
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������");
	set("long", @LONG
�����ɵĽ�������Ҫ�Ǹ����֣�һ��ʦ�����޷��Դ�����Ҫ����
��������չۿ��Լ�̽���������еİ��أ�������𳤱��������޽�
��������Ϊ�����űչ����ã������Ǹ���Ϣ���ṩ��ʳ����Ϣ�ĵط�
��
LONG );
	set("exits", ([
	        "out" : __DIR__"lgsw",
	        "east" :__DIR__"xiuxis"
		]));
	set("no_fight",1);	
	setup();

}
void init()
{
	add_action("do_xiulian","lianxi");
	add_action("do_quit","quit");
}
int do_quit()
{
       object me=this_player();
       tell_object(me,"�չ�ʱ�����˳���\n");
       return 1;
}
int do_xiulian()
{
	 object me,weapon;
	 me=this_player(); 
	 if (!me->query_skill_mapped("sword","tianyu-qijian"))
	 return notify_fail("�㻹û��enable tianyu-qianjian���޷���ϰ\n");
	 if (me->query("jingli")<50)
	 return notify_fail("������̫������Ϣһ�������ɣ�\n");
	 if (me->query("neili")<100)
	 return notify_fail("���������������ˣ�\n");
	 if ((int)me->query_skill("tianyu-qijian",1)*(int)me->query_skill("tianyu-qijian",1)*(int)me->query_skill("tianyu-qijian",1)/10 > (int)me->query("combat_exp")) 
	 return notify_fail("Ҳ����ȱ��ʵս���飬�����ϰ��û��������\n");
	 if (!objectp(weapon = me->query_temp("weapon"))
         || (string)weapon->query("skill_type") != "sword")
                return notify_fail("û�н���ô��ϰ�����潣��\n");
     if (me->query_skill("tianyu-qijian",1)<=100)
      return notify_fail("��������潣��򲻹����޷���ϰ��\n");
     tell_object(me,HIR"�㰴��ʦ�����������ھ�����ϰ��һ�����𽣷������佣������������һ�㡣\n"NOR);
         me->add("jingli",-30);
         me->add("neili",-5);
         me->improve_skill("tianyu-qijian", me->query("int")*8);
         return 1;
}         

int valid_leave(object me, string dir)
{
	object room;
	room=find_object(__DIR__"lgsw");
	if(me->query_temp("xiulian_sword") && dir=="out")
	{
		room->add("mask/�չ�",-1);
		me->set_temp("xiulian_sword",0);
		return 1;
	}
	return ::valid_leave(me, dir);
}
	
		
	
