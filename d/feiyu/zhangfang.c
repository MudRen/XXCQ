// Room: zhangfang.c
// Created by Atlus 1999.7.23
// Modified by Atlus 1999.7.23
// 

inherit ROOM;

void create ()
{
        set ("short", "�ʷ�");
        set ("long", @LONG
�����Ƿ��������ʷ����������ճ�������֧�������ﶼ�м�¼������
���ʵ��Ǹ�����������˵�Ǹ��Ͻ�ʿ��ѧʶ��Ϊ�ḻ�������ʲôѧϰ��
����������������ʷ������һ���ӵ��ʱ������ݣ����в������Ϸ�����
�����ӣ������������Ӱɡ����������Ͼ��Ǳ�������
LONG);
        set("area","����");
        set("valid_startroom", 1);
        
        set("objects", ([
                __DIR__"npc/zhangfangxs" : 1,
        ]));

        
        set("exits", ([
                "south" : __DIR__"bingqifang",
        ]));

        setup();
        replace_program(ROOM);
}

