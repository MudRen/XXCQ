//  ������
// by netkill@cctx
//Modify congw@CCTX

#include <ansi.h>
inherit ROOM;
string look_bei();

void create()
{
        set("short", HBMAG HIY "��ɽ����"NOR );
        set("long", 
"\n              "+HBWHT HIW"�����ǻ�ɽ�ľ�����ɽ�߲��ɲ⣬�����ƺ�ãã��\n\n"NOR+
"   һ���Ƕ��͵����£�һ�����վ���ɽ·��Ψ�д˴���һԼ�����ɿ��ƽ�أ�������\n"+
"�����������Ӣ�ۺ����ڴ������಩��Ϊ�����µ�һ�ĳƺš�����������һ��"+BMAG HIY "��"NOR+"(bei),\n"+
"������һС��ͤ��������Ϣ֮�á�\n"

        );
	set("no_fight", 1);
        set("no_sleep_room",1);
        set("exits", ([ 
                "down" : "/d/huashan/bshanlu",
                ]));
        set("no_clean_up", 0);
        set("item_desc", ([
                "bei" : (: look_bei :),
        ]));
	set("objects", ([
        "/adm/zi" : 1,
        ]));
        
        setup();
}

int init()
{               
        object me=this_player();
        if ( !me->query_temp("biwu")) 
                me->set_temp("biwu",1); 
                
}

int valid_leave(object me, string dir)
{              
        if ( dir=="down") me->delete_temp("biwu");
        return ::valid_leave(me, dir);

}



string look_bei()
{       
        string use,str;
        int i,j;
        use= HIW"\n����"NOR+HIY"��Сѩ����Ӣ���ס�"+HIW"����\n\n"NOR+WHT"_______________________\n"NOR;
        for ( i=2; i<=20; i=i+2)
        {
        	
              str=read_file("/data/ladder.txt",i,1);
	      
               if(str && !(str==""))
                {
                use+=sprintf(HBGRN HIR"�� �� %s �� ��\n"NOR HIG,chinese_number(i/2));
                use+=str;
               } 
              str=read_file("/data/ladder.txt",i+1,1);
		 if( str && !(str==""))
		 {use+=str;use+=WHT"_______________________\n"NOR;}
	
        }
        return (use);
        
}
