// fotang.c ����
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
	set("long",
	"�����ж�λŮ�죬��Ϊ�ɷ��ǽ������ˣ�����ÿ��������ƽ����ۣ�
���γɱ������ｨ�˸�С���ã������������ơ�һ������������������
̨�ϣ������������ͽ����Ĥ�ݡ���Ҳ�����������ݣ�kneel������
�Լ���ɱ����\n"NOR
     	);
     	set("valid_startroom",1);
	set("no_fight",1);
	set("exits",([
     		"west" : __DIR__"huayuan",
     	]));
     	setup();
}

void init()
{
        add_action("do_kneel","kneel");
}

int do_kneel(string arg)
{
        object me;
        me=this_player();
        if (arg)
         return notify_fail(CYN"��ֻҪ���Ĥ�ݣ�kneel�������ˡ�\n"NOR);
       if ( (me->query("kill"))==0 ) 
            return notify_fail(YEL"�����ɱ���������ի���\n"NOR);
	me->clean_up_enemy();
	me->set("kill",0);
   me->remove_all_killer();
	message("channel:chat",
		HIY"���������ˡ�"+me->query("name")+"�����Ĺ����£���Ҷ�������������ǰ�ӡ�\n"NOR,users());
        return 1;
}

