// Room: huikeshi.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�����");
        set ("long", @LONG
������С�ֺŵĻ���ң�û���ܲ����ֺŵ�ǰ�����������ɣ�������
��Ҳ�ǳ����ࡣ̧ͷ���Կ���һ��д��С�ֺŵ����ң��м����һ��̫ʦ
�Ρ��������¼ҵ����������������Ǵ�Ժ�������߾��ǲݵء�
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wenxinlaoxie" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"caodi",
                "north" : __DIR__"dayuan",
        ]));

        setup();
        replace_program(ROOM);
}
