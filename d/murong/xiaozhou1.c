// /d/murong/xiaozhou.c


#include <ansi.h>
#define SHIP_TO __DIR__"xd"
inherit ROOM;

void create()
{
        set("short", GRN "С��" NOR);  
        set("long", @LONG
�����һҶС�ۣ����Ҳ�����������ĸ��ˡ�һ���Ҷ��ֳֳ���ݣ���
�ڴ�β�����س��Ŵ���
LONG);      
 
       set("no_fight", 1); 
       setup(); 
}
 
void init()
{ 
      object me = this_player();               
      call_out("do_bird", 10, me);  
      add_action("do_action", "");                             
}

int do_action(string arg)
{
       string action = query_verb();

       switch (action) {   
       	       case "l":
       	       case "look":	
               case "dazuo":
               case "exercise": 
               case "lian":
               case "tuna":
               case "kill":
               case "fight":
               case "steal":
               case "hit":
	       case "save":       
               case "quit":    
               case "drop":
               case "practice":
               write(HIY"\n����һҶС�ۣ����Ҳ�����������ĸ��ˡ�һ���������ӵ����괬���ֳ�\n"
"����ݣ����ڴ�β�����س��Ŵ���\n\n"NOR);
                       return 1;
       }
       return 0;
}

void do_bird()
{ 
	object me = this_player(); 
	mixed *local;

	local = localtime(time() * 60);
        if(environment(me))
        {  
        	write(HIW"\n����Ѵ�ʻ����һƬһ���޼ʵĺɻ�����\n\n"NOR);
	        if( local[2] < 5 && local[2] >= 2 )  
	        {
			write(YEL"\n�����Ĺ��֮�У�һ�ж�ʧ����ɫ���¹�����ˮһ�㣬������к��һƬƬ��\n"
		           "��Ҷ�ͺɻ��ϡ��������������ںɻ����С���Ҷ�ͺɻ��·���ţ��������\n"
		           "һ��������������ɴ���Ρ����������������ϡ���ٻӰ��ȴ�����ǻ��ں�\n"
		           "Ҷ�ϡ�\n\n"NOR); 
        	call_out("do_bird1", 10, this_object());		             
	        }
        	if( local[2] < 2 || local[2] >= 21 ) 
        	{
			write(BLU"\n��վ��С��֮�ϣ����ɲ�������ݣ�Զ�ɹ�ɽ����ɫ������׺������������\n"
       			"��������ϸ�����ɳ�̳ɵ�����Ъ������ɫ�������ϡ���ʱ���ƻ��ţ�ǳӳ\n"
			"����׵��λ�����ʱ�����޼ʣ���ƫ���ű�Ө����⡣������ҹ���������\n"
           		"��������е���΢��ɪ����\n\n"NOR);
        	call_out("do_bird1", 10, this_object());		             
	        }
        	if( local[2] < 8 && local[2] >= 5 )  
        	{
			write(HIM"\n��������տ�ʼ�ǳ��صġ���һЪ��һб���ʺ���ٺ�ɫ��ϼ��Խ��Խ���\n"
           		"�س����ڿ��С���������ɫ�ѽ������ף�ͷ��ͨ��Ⱦ�е���ɫ�ķ�����ƿ�\n"
           		"�ü�ǳ������գ�������ӯ�����ڸ�����ϼ���ӳ�Ŷ�����Ƭ��͸������\n"
           		"�����������ֳ�����\n\n"NOR);                                   
        	call_out("do_bird1", 10, this_object());		             
          	}
        	if( local[2] < 12 && local[2] >= 8 ) 
        	{
			write(RED"\nһ����ȥ, ������Ҷ, ��Ҷ, «έ, ����, ����һģһ��, ��֮��Ҷ, ��Ҷ\n"
           		"��ˮ��Ư��, ��ʱһ�����, �㼴�仯�ٶ�, ����˿̼ǵ��������, ��ʱ\n"
           		"������ȫȻ��ͬ�����Ӱ��ˮ�棬��������ɫ�Ĺ⡣���ߵĴ����Ͱ�����\n"
           		"�����Ƶ������š���ݡ�«έ�ͺ�ġ��׵ġ��ϵĻ�������������յ�һ��\n"
           		"���ȵ�̫����ɹ�ţ�������������������Ϣ��\n\n"NOR);   
        	call_out("do_bird1", 10, this_object());		             
          	}
        	if( local[2] < 21 && local[2] >= 17 ) 
        	{
			write(HIY"\n���췺�����ɫ����ϼ��ӳ�ڱ����峺�ĺ�ˮ�ϣ�����һƬõ��ɫ�Ĺ⣬Զ\n"
           		"Զ��ϼ�⣬�̵̿��ڱ���У���˪�㡢���������觡������꣬..... ��\n"
           		"��Ϧ��������������յ�ϼ�⽥������ȥ�ˣ�������ɫ�����糺죬��\n"
           		"��Ϊǳ�죬��ͻȻ�Եø߶�Զ�˵���գ����ֳ�һƬ���µ���ɫ��\n\n"NOR);
        	call_out("do_bird1", 10, this_object());		             
        	}                
        	if( local[2] < 17 && local[2] >= 12 ) 
        	{
			write(GRN"\n�������۵ĺ������棬�������������Ҷ�ӡ�����Ҷ���м䣬���ǵص�׺\n"
           		"��Щ�׻�������һ���������飬�������������ǣ�����ճ�ԡ�����ˡ�΢\n"
           		"������������������㣬�·�Զ��Ʈ��ĸ����Ƶġ�\n\n"NOR);
        	call_out("do_bird1", 10, this_object());		             
         	}                                    
    	}
    	return;
}
void do_bird1()
{ 
	object me = this_player();   
    	mixed *local;

	local = localtime(time() * 60);
        if(environment(me)) 
        {  
		write(CYN"\nС���ںɻ���������ҹգ�һ�Դ�«έ�ͺɻ�������ǰ�ι���\n\n"NOR);
        	if( local[2] < 5 && local[2] >= 2 ) 
        	{
			write(HIW"\n���������٣��������ǲ�����ȥ�����ɫ�������ѴӺ�����ȽȽ��������\n"
           		"��֪�Ƕ�������ô��Ʈ��͸���İ�ɴ��\n\n"NOR);
        	call_out("do_bird2", 10, this_object());		             
	        }
         	if( local[2] < 8 && local[2] >= 5 ) 
         	{
			write(CYN"\n�������Ѿ�����ˡ�����һ����ɫ���Ż�������Ƶ���¶��һ��һ��ľ���\n"
           		"��������ǰ���«έ��ʪ�����͵��ں����ųɼ�����������ˮ������Ȼ��\n"
           		"��أ��̲��һ��ճ�����Ű�����\n\n"NOR);         
        	call_out("do_bird2", 10, this_object());		             
           	}
          	if( local[2] < 12 && local[2] >=8 ) 
          	{
			write(GRN"\n��ӯӯ�ĺ����ϣ���ֻ΢΢�����Ű�ɫ����С�ۣ���ʪ���΢���е�����\n"
		        "��ֻС�����ں����Ϸ�����ȥ��\n\n"NOR);
        	call_out("do_bird2", 10, this_object());		             
           	}
           	if( local[2] < 17 && local[2] >= 12 ) 
           	{          
			write(GRN"\n�Ӳ�Զ����ˮ���ɵĺ�����Ʈ��һ��������ת�ĸ�����������Ů���ں͸���\n"
           		"Ц�����۲�����\n\n"NOR);
        	call_out("do_bird2", 10, this_object());		             
              	}             
           	if( local[2] < 21 && local[2] >= 17 ) 
           	{
			write(CYN"\n̫����ɽ�ˣ����ķ�����ǿ�������ͷ�������������Ⱦ��Ѫɫ��������\n"
           		"���Ƶع���˸�ţ���ˮȾ����ɫ��̫������һ�������������Żƺ�ɫ��\n"
           		"�ƣ���ʱ¶���������������·����ŭ�����ۡ�һ�������������¶������\n"
           		"ɫ����ֻ������������������˸�š�\n\n"NOR);
		call_out("do_bird2", 10, this_object());           	
           	}              
           	if( local[2] < 2 || local[2] >= 21 ) 
           	{
		write(CYN"\n��ʱ������ţ��ں���ï�ܵ����ּ䣬��һ������Ҳ���������̵��������\n"
           	"һ��ĺ�ˮ������һ���Բ����������������һĨ���̣�ˮ��Ư���������\n"
           	"���ƽ�ʵԶ���ƶ�ʱ��������һ��ɽˮ��һ�㡣\n\n"NOR);
        	call_out("do_bird2", 10, this_object());           	
           	}
      	}     
      	return;
}

void do_bird2()
{ 
        object me = this_player();
        if(environment(me)) 
        {
		write(YEL"\nС����«έ�ͺɻ��������ش���\n\n"NOR);
        	call_out("wait", 10, this_object());
       	}     
       	return;
}

void wait()
{
        object me, room;      
        me = this_player();
        room = find_object(__DIR__"xd");
        if(!(room=find_object(__DIR__"xd")))
             room=load_object(__DIR__"xd");
        tell_object(me, CYN"\n������С�����棬������̫����������ɫ����֪�������ѵ�����Ŀ�ĵء�\n\n"NOR);
        tell_object(me, "    ����Ψһ�ĳ����� "HIG"out"NOR"��\n");

        this_object()->set("exits/out", __DIR__"xd");                             
        call_out("check", 20, this_object());
        return;
}

void check()
{
        object room, *ob;
        int i;

        if( room = find_object(__DIR__"xiaozhou1") ) {
                room->delete("exits/out");

                tell_room(room, "��������˵���������´��ɣ���ҲҪ��ȥ�ˡ���\n", ({}));
                ob = all_inventory(room);
                for(i = 0; i < sizeof(ob); i++) {
                        if (userp(ob[i])) {
                                if (!living(ob[i])) tell_room(room, "������$Ņ���˴���\n", ob[i]);
                                else tell_room(room, "$N���������Ļ����ԹԵ����˴���\n", ({ob[i]}));
                                ob[i]->move(SHIP_TO);
                                if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "��̧���˴���\n", ({ob[i]}));
                                else tell_room(SHIP_TO, ob[i]->name() + "�����˴���\n", ({ob[i]}));
                        }
                }
                message("vision", "������̤�Ű����������ѱ���ʻ���ġ�\n", room);
                return;
        }
}                                                             
                                                               
                              
                              