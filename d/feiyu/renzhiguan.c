// Room: renzhiguan.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "��ֹ��");
        set ("long", @LONG
�������"����ɽׯ"������֮һ����ֹ�ء���ɽ������Ȼƽ̨����
��Ĳ���ʹ�����γ�һ����ΰ�Ĺؿڡ��������򱱿��Կ�������������
ɽׯ���Ĳ��֡���ֹ��������ɭ�ϣ����ϵ������գ������ѹ�������һ
����ʮ����������û��ʧ�ع��������ɽ��Ӧ�þ��ǡ������롱�˰ɣ�
LONG);
        set("area","����");
        set("outdoors", "feiyu");
        set("valid_startroom", 1);

        set("objects", ([
                "/d/feiyu/npc/feiyudizi" : 2,
                "/kungfu/class/feiyu/songwandeng" : 1,
         ]));

        set("exits", ([
                "southdown" : __DIR__"shanlu3",
                "north" : __DIR__"liaowangtai",
                "westdown" :__DIR__"shanlu2",
        ]));

        setup();

        
}

int valid_leave(object me, string dir)
{
        if ((!(string)me->query("family") || (string)me->query("family/family_name") != "������") 
               && ( dir == "north" || dir == "westdown")
              && (objectp(present("dizi", environment(me)))
               || objectp(present("dizi", environment(me))) ))
               {  if (objectp(present("dizi", environment(me)))) 
               
                       return notify_fail("�������˵�����㲻�Ƿ��������ӣ���ذɡ�\n");
        }

        return ::valid_leave(me, dir);
}
