// Room: lysquare.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����ɽׯ�㳡");
        set ("long", @LONG
������"����������ɽׯ"�Ĵ�㳡��ɽ��һ������Ĵ�ƽ̨ʹ����
�γ�һ���޴�Ĺ㳡���㳡�������Ƿ�԰Լʮ�ɵĻ��أ���ɫ���ʻ���
�����������ޡ���ɫ����������̵ĸ�Ƽ�໥��ӳ��������Ŀ�����ص�
������һ����ʯ����ʯ���Ͽ��ž�������������������չ����ΰ׳�ۡ�
LONG);
        set("area","����");
        set("outdoors", "feiyu");
        set("valid_startroom", 1);

        set("objects", ([
                "/d/feiyu/npc/feiyudizi" : 2,
        ]));

        set("exits", ([
                
                "north" : __DIR__"qianting",
                "westdown" :__DIR__"shanlu1",
        ]));

        setup();

        
}

int valid_leave(object me, string dir)
{
        if ((!(string)me->query("family") || (string)me->query("family/family_name") != "������") 
               && ( dir == "north" )
              && (objectp(present("dizi", environment(me)))
               || objectp(present("dizi", environment(me))) ))
               {  if (objectp(present("dizi", environment(me)))) 
               
                       return notify_fail("������Ӻȵ����㲻�Ƿ��������ӣ��������ڡ�\n");
               else
                       return notify_fail("������Ӻȵ����㲻�Ƿ��������ӣ��������ڡ�\n");
               
        }

        return ::valid_leave(me, dir);
}
