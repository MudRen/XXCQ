// liangong2.c ������
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","������");
        set("long",
"�����ǻ��������������������ߺ�ʵ����ש��ǽ�ϣ�wall����Լ��һ
Щͼ�������ζ����ĵ��Ӷ�����������������Ҳ�Ƿ��ζ������ڵ����书
�ĳ���������Ʈ��һ���󷹲˵���ζ��\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"south" : __DIR__"chanting",
		"north" : __DIR__"liangong",
	]));
	set("item_desc",([
		"wall" : "ǽ�ϻ���һЩ�Դ��С�ˡ�\n",
	]));
	setup();
}

void init()
{
	add_action("do_think","think");
}

int do_think(string arg)
{
     object me=this_player();
	int c_skill1,c_skill;
	
	if (arg!="wall") return 0;
	c_skill=(int)me->query_skill("parry", 1);
        c_skill1=(int)me->query_skill("literate", 1);
	if (c_skill1<10)
		return notify_fail("���֪ʶ̫����,������������Ķ�����\n");
        if (me->query("jingli")<20)
        {
         tell_object(me,"��̫���ˣ������޷�����ʯ�����ݡ�\n");
                return 1; 
        }
        if (c_skill>30)
        {
         tell_object(me,"�����ʯ������̫��ǳ�ˡ�\n");
                return 1; 
        }
        
         tell_object(me,"�������ʯ�ھ�˼���ã��Բ���й����������\n");
        me->improve_skill("parry", random(10*me->query("int")));
         if (me->query("id")!="love")
       me->receive_damage("qi", 10);
        return 1;
}
