// Room: С��
// Date: by godzilla 1999.11.18

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "С��");
	set("long", @LONG
һ�����������ö���ʯ�̳ɵ�С����·����������������ʯ·
�ϣ�ž�žવķ������������������Ѿ�û��·�ˡ�������������
�����ƺ��ǳ��ر������(move)���ԡ�
LONG );
        set("outdoors", "tianyu");
	set("exits", ([
	        "east" : __DIR__"xiaojing1", 
		]));
	setup();
	
}
void init()
{
	object me=this_player();
        if(me->query("kar")>12+random(50)&&me->query("family/family_name")=="������")
        {
        	call_out("fang_per",1,me);
        }
        add_action("do_climb","move");
	
}
void fang_per(object me)
{
           if(me->query("lingwu_perform"))
          {
                 return 0;
          }  
    tell_object(me,HIG"���ϵĻ�ѩ�Ѿ��ڻ����������˽�������Ȼ���ֵ��Ŀÿ����ƶ��ĺۼ�
���������(move ���Ŀ���)��\n"NOR);
        me->set_temp("find/����",1);
}
int do_climb(string arg)
{
	object me=this_player();
	if(!arg||arg=="")
	return notify_fail("����ָ�Ӧ������(move xxxx)������(move ��һ����)\n");
       if(me->query("jingli")<110)
     return notify_fail("������̫���ˡ�\n");
	switch(arg)
        {
        	case "��һ����":
        	case "�ڶ�����":
        	case "��������":
        	case "�������":
        	message_vision("$Nʹ�����̵������ƶ����ɣ�����.....ֻ����Ҷ���˼��£�����ȴ��˿���������Ѿ��۵þ�ƣ�����ˡ�\n",me);
                me->add("jingli",-200);
                return 1;
                break;
                case "���Ŀ���":
                if(!me->query_temp("find/����"))
		{
			message_vision("$Nʹ�����̵������ƶ����ɣ�����.....ֻ����Ҷ���˼��£�����ȴ��˿���������Ѿ��۵þ�ƣ�����ˡ�\n",me);
                        me->add("jingli",-200);
                        return 1;
		}
		message_vision("$Nʹ�����̵������ƶ����ɣ���һ�����ɻ������ƶ�������һ����϶��$N��æ���˹�ȥ��\n",me);
		me->move(__DIR__"treeup");
		me->set_temp("find/����",0);
		return 1;
	        break;

             }
}				
