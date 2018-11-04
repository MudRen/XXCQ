// Room: shiyanshi.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.7.22
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ʵ����");
        set ("long", @LONG
������С�ֺ�����ҩƷҩ����ʵ���ң���������ż��ų����ӣ�����
�ϰ��źܶ�ƿ�Ӻ�ҩƷ��������������������Ū��ƿ��ҩƷ��ǽ����һ
���������������ķ��ı��������������¼ʵ����̡���ʱ���˵������
������ȥȡ���ϣ�Ҳ���˵����������������ʵ��Ʒ��
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"liandanfang",
                "west" : __DIR__"dayuan",
                "north" : __DIR__"ziliaoshi",
        ]));

        set("objects", ([
                "/kungfu/class/wenjia/wenwen" : 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        if ( (dir == "north" || dir == "east") && (int)me->query("wentask/done")<=200 )
                 return notify_fail("�Ա�����һ���¼ҵ�����ס�㣬����һ��˵�����������¼��صأ��㻹û���ʸ������!��\n");
        return ::valid_leave(me, dir);
}
