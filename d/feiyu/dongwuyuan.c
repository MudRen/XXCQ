// Room: dongwuyuan.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����Ժ");
        set ("long", @LONG
�����Ƿ����е��Ӽ�����ϰ�ĵط���ֻ����������Χ��һ��̸���š�
����Ķ��ڸ�����ϰ�ţ����Ϸ���·��ͨ����ƫ���ģ�ͨ��������ž͵�
�����ˡ�
LONG);
        set("area"," ����");
        set("valid_startroom", 1);

        set("objects", ([
                      "/kungfu/class/feiyu/yemengshen" : 1,
                       "/d/feiyu/npc/feiyudizi" : 2,
        ]));


        set("exits", ([
                "southwest" : __DIR__"dongpianting",
                "west" : __DIR__"neitang",   
        ]));

        setup();
        replace_program(ROOM);
}
