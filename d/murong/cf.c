// chufang.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIY"����"NOR);
         set("long",@long
����һ��С����, ��Ȼ����, ���ǹ���ư��, ���ν���, ������ȫ����̨
�϶��������ʹϹ��߲�, �����Ϻ, �������಻��, ��ʮ�ָɾ����롣��
����һ����һ�ŷ���(fanzhuo)��
long);
         set("item_desc", ([ 
"fanzhuo" : "�����Ϸ��Ÿ�����ζ�Ľ���С�ˣ�
                    ������  (dongsun tang)   
                    �����Բ(feicui yuyuan)
                    ���Ϻ��(lingbai xiaren)
                    ÷����Ѽ(meihua zaoya)
                    ӣ�һ���(tingtao huotui)
                    ������Ҷ��(longjing caiyeji)               
�㿴����ô�����ζ����������(na)�����ͳԡ�
\n"
]));         
         set("exits",([
             "south" : __DIR__"xt",
]));
         setup();
	 
}
void init()
{
	add_action("do_na", "na");
}

int do_na(string arg)
{
	object me,ob;
  	string arg1,arg2;
  	me=this_player();
  	if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
   		return notify_fail("�����ʽ: na <ʳ������> from fanzhuo��\n");
  	if(arg2!="fanzhuo")
     		return notify_fail("�����ʽ: na <ʳ������> from fanzhuo��\n");
     	if((int)me->query("food", 1) >= 200)
     		return notify_fail("������ô�࣬����ԣ����ǲ�è��\n");
    	switch (arg1){
          case "dongsun tang": 
          	ob=new(__DIR__"obj/dongsun-tang");
                ob->move(me);          
                break;
          case "feicui yuyuan":
                ob=new(__DIR__"obj/feicui-yuyuan");
                ob->move(me);
                break;   
          case "lingbai xiaren":                   
                ob=new(__DIR__"obj/lingbai-xiaren");
                ob->move(me);          
                break;
          case "meihua-zaoya":
                ob=new(__DIR__"obj/meihua-zaoya");
                ob->move(me);
                break;   
          case "yingtao-huotui":                
                ob=new(__DIR__"obj/yingtao-huotui");
                ob->move(me);          
                break;
          case "longjing-caiyeji":
                ob=new(__DIR__"obj/longjing-caiyeji");
                ob->move(me);
                break;         

          default :
                 return notify_fail("û������ʳ�\n");
                    }

       message_vision("$N�ӷ���������һ��$n��\n",me, ob);  
       return 1;
}