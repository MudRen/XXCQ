// hb1.c 

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",GRN"����"NOR);
         set("long", 
"�׻�˵��"+BLINK HIC+"��������, �����պ�"+NOR+"���������Ǵ��������"+BLINK HIM+"̫��"+NOR+"�������̲���\n"
"Ư��һҶҶ��"+BLINK HIW+"С��"+NOR+", һ�����ö���С�������ź��ϵ���粻ʱƯ����Ķ��С�\n"
);
       set("outdoors","����Ľ��");
       set("exits", ([
           "west" : __DIR__"hb",
           "east" : __DIR__"hb2",
]));
       setup();
}
void init()
{
	object me = this_player();
	int luck = (int)me->query_temp("mrb_meet");
	me->add("jingli", -10);
	if( (int)me->query("mrb_fail", 1) < 5 ) {
        if( me->query("combat_exp") > 300000
         && me->query("family/generation") == 3
         && me->query("family/family_name") == "����Ľ��" 
         && me->query("jifen")
         && me->query("ketou")
         && !me->query("marry")
         && luck < 1
         && !me->query("meet_mrb")
         && random(5) < 2)
         {
         	write("��ͻȻ���ú��������������ת��ͷ��ȴ����ʲôҲû�С�\n");
         	me->set_temp("mrb_meet", 1);
         }   
         
        if (luck >= 1) 
        {
          write("��ͻȻ���ú��������������ת��ͷ��ȴ����ʲôҲû�С�\n"); 
          me->add_temp("mrb_meet", 1); 
        }
    }
}