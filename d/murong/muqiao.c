// muqiao.c
#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",YEL"ľ��"NOR);   
         set("long",@long
����ͨ������Сͤ��ľ�ţ�������ȥ����̲���������ɫ���ˡ�ľ�ŵ�
�����ϵ����һ����Сľͷʨ�ӣ����˰������֡�ľ���������ܹ�����һ��
����Сͤ����ľ����˨��һ��Сľ��(boat)����Ȼ�������˲��ڡ�
long);   
         set("outdoors","����Ľ��");  
         set("item_desc", ([
         "boat" : "С����û���ˣ������(jump)��С���ϡ�\n",
]));     
         set("exits",([
             "west" : __DIR__"houyuan1",            
             "south" : __DIR__"bst",
]));
	 set("objects", ([
	 __DIR__"npc/gongye" : 1,
]));
         setup();
}
void init()
{                                    
	 object boat;
	 boat = find_object(__DIR__"boat1");
	 if(!(boat = find_object(__DIR__"boat1")))
              boat = load_object(__DIR__"boat1");
         if( boat->query("busy")) {
         set("long",@long
����ͨ������Сͤ��ľ�ţ�������ȥ����̲���������ɫ���ˡ�ľ�ŵ�
�����ϵ����һ����Сľͷʨ�ӣ����˰������֡�ľ���������ܹ�����һ��
����Сͤ��
long);                                   
	 }
       	 add_action("do_jump","jump");
}
int do_jump(string arg)
{       
	object boat;
	boat = find_object(__DIR__"boat1");
	if(!living(this_player())) return 0;
	if( this_player()->is_busy()) 
		return notify_fail("����æ���أ�\n");
	if( this_player()->is_fighting())                       
		return notify_fail("����æ���أ�\n");	
	if(!(boat = find_object(__DIR__"boat1")))
             boat = load_object(__DIR__"boat1");		
	if( boat->query("busy"))
		return notify_fail("��Ҫ����������\n");
	if(!arg||arg!="boat")
		return notify_fail("��Ϲ����С�ĵ���ˮ���ˡ�\n");
	message_vision("$N����Ľ⿪���ӣ�һ��������ͷ��ȥ��\n", this_player());

	this_player()->move(__DIR__"boat1");
	tell_object(this_player(), BLU"����˺ô󾢲���ס���ӣ����ŵøϽ�����������\n"NOR);
	return 1;
}       

