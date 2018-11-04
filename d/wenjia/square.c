// Room: square.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.17
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�ܲ��㳡");
        set ("long", @LONG
������"�������ֺ�"�¼��ܲ������ֺš�ǰ��Ĺ㳡����ǰ
��ȥ��һ����ΰ�Ľ��������ĺ�ΰҲ�������¼ҵ��Ӵ���¼���
�����еĵ�λ�㳡���ܲ��������ģ�ÿ��������Χ����һ������
���š����߿��Խ���ǰ����������������Ҳ��һ��С�㳡��
LONG);
        set("area","����");
        set("outdoors", "wenjia");
	set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wendating" : 1,
                __DIR__"npc/wenxiaoting" : 1,
        ]));

        set("exits", ([
                "down" : __DIR__"paifang",
                "north" : __DIR__"qianting",
                "west" : __DIR__"westsquare",
                "east" : __DIR__"eastsquare",
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "���ֺ��¼�") && dir == "north" && dir == "east" && dir == "west" 
               && !wizardp(me) && !present("wenjiacard", this_player()) &&
               (objectp(present("wen dating", environment(me)))
               || objectp(present("wen xiaoting", environment(me))) ))
               {  if (objectp(present("wen dating", environment(me)))) 
               
                       return notify_fail("�´����ȵ����㲻���¼ҵ��ӣ��������ڡ�\n");
               else
                       return notify_fail("��С���ȵ����㲻���¼ҵ��ӣ��������ڡ�\n");
               
        }

        if ( present("wenjiacard", this_player()) &&
             objectp(present("wen dating", environment(me))) ) 
                message_vision("�´�����$N������˵����ԭ�����¼ҵĿ��ˣ�����������\n", me);
        if ( present("wenjiacard", this_player()) &&
             objectp(present("wen xiaoting", environment(me))) ) 
                message_vision("��С����$N������˵����ԭ�����¼ҵĿ��ˣ�����������\n", me);

        return ::valid_leave(me, dir);
}
