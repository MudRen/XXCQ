// liangong.c ������
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","������");
        set("long",
"�����ǻ��������������������ߺ�ʵ����ש��ǽ�ϣ�wall����Լ��һ
Щͼ�������ζ����ĵ��Ӷ������������������Ƿ��ζ������ڵ����书��
�����������ǵ�����Ϣ�ҡ�\n"
	);
	set("valid_startroom",1);
	set("item_desc",([
		"wall" : "������һЩ��ȭ���ȵ�С�ˡ�\n",
	]));
	set("exits",([
		"west" : __DIR__"zoulang4",
		"south" : __DIR__"liangong2",
		"east" : __DIR__"xiuxishi",
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
        c_skill=(int)me->query_skill("cuff", 1);
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
        
         tell_object(me,"�������ʯ�ھ�˼���ã��Ի���ȭ����������\n");
        me->improve_skill("cuff", random(10*me->query("int")));
         if (me->query("id")!="love")
       me->receive_damage("qi", 10);
        return 1;
}
