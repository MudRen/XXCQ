// Room: square.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.7.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�ܲ��㳡");
        set ("long", @LONG
������"�������ֺ�"�¼��ܲ������ֺš�ǰ��Ĺ㳡����ǰ��ȥ��һ
����ΰ�Ľ��������ĺ�ΰҲ�������¼ҵ��Ӵ���¼��������еĵ�λ�㳡
���ܲ��������ģ�ÿ��������Χ����һ���������š����߿��Խ���ǰ����
������������Ҳ��һ��С�㳡��
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wendating" : 1,
                __DIR__"npc/wenxiaoting" : 1,
                "/kungfu/class/wenjia/wenxiaobian" : 1,
        ]));

        set("exits", ([
                "southdown" : __DIR__"paifang",
                "north" : __DIR__"qianting",
                "west" : __DIR__"westsquare",
                "east" : __DIR__"eastsquare",
                "feiyu":"/d/feiyu/lysquare",
        ]));

        setup();

        "/clone/board/wenjia_b"->foo();
}

int valid_leave(object me, string dir)
{
        if ((!(string)me->query("family") || (string)me->query("family/family_name") != "���ֺ��¼�") 
               && ( dir == "north" || dir == "east" || dir == "west" )
               && !present("wenjiacard", this_player()) &&
               (objectp(present("wen dating", environment(me)))
               || objectp(present("wen xiaoting", environment(me))) ))
               {  if (objectp(present("wen dating", environment(me)))) 
               
                       return notify_fail("�´����ȵ����㲻���¼ҵ��ӣ��������ڡ�\n");
               else
                       return notify_fail("��С���ȵ����㲻���¼ҵ��ӣ��������ڡ�\n");
               
        }

        if ((string)me->query("family/family_name") == "���ֺ��¼�" && dir == "southdown" && (int)me->query("combat_exp") <= 100000 )
                       return notify_fail("��ͻȻ����ʦ��˵�����书�����߲��ܳ��¼ң��ڽ����϶��¼ҵ�����\n");

        return ::valid_leave(me, dir);
}
