// Room: ���ı�
// Date: by godzilla 1999.11.18

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "���ı�");
	set("long", @LONG
��ֻ��������һ�ͱ�ǰ�������ڵף�ֻ���������ƣ���֪������
�ж��ż���ӹȵ�Ʈ��һ������������һ��پ��Ŀ�������ʹ����
���������ĸо���
LONG );
        set("outdoors", "tianyu");
        set("exits", ([
        "north"  : __DIR__"xiaojing1",
        ])); 
	setup();
	
}
void init()
{
	add_action("do_jump","jump");
}
int do_jump(string arg)
{
	
	object me=this_player();
        int i=(int)me->query_skill("dodge");
	if(!arg||arg=="")
	return notify_fail("��Ҫ���Ķ�����\n");
	if(arg=="down")
	message_vision(HIR"$N��������ɽ�ڡ�\n"NOR, me);
	if(i<60+random(50))
	{
		me->move(__DIR__"yuduan");
		call_out("do_wait", 2, me);
		return 1;
	}
	else
	{
		me->move(__DIR__"yuduan");
		call_out("do_wait1",2,me);
		return 1;
	}
}
void do_wait(object me)
{
	write(HIR"��ֻ���ö��ߺ����������죬����Խ׹Խ��....\n"NOR, me);
	write(HIW"��ֻ���������������ٻ�........\n"NOR, me);
	me->move(__DIR__"tianxinb");
	tell_room(environment(me),me->name()+"��ɽ������������\n");
	me->set_temp("last_damage_from","ˤ��ɽ�µ�");
	me->unconcious();
	me->die();
}
void do_wait1(object me)
{
	tell_object(me,HIR"��ֻ���ö��ߺ����������죬����Խ׹Խ��....\n"NOR);
//    tell_object(me,HIW"��֪���˶��,��ֻ������һ����ʧȥ��ֻ��........\n"NOR, me);  ^M
	me->move(__DIR__"tianxinb");
	tell_room(environment(me),me->name()+"��ɽ������������\n");
//    me->unconcious();
}	
			
		      	 
