// Room: xiwuyuan.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����Ժ");
        set ("long", @LONG
�����Ƿ���Ů���Ӽ�����ϰ�ĵط������Լ������������������š�
���Ϸ���·��ͨ����ƫ���ģ�ͨ��������ž͵������ˡ�
LONG);
        set("area"," ����");
        set("valid_startroom", 1);

        set("objects", ([
                      "/kungfu/class/feiyu/yemengse" : 1,
                       "/d/feiyu/npc/feiyudizi" : 2,
        ]));
		set("exits", ([
                "southeast" : __DIR__"xipianting",
                "east" : __DIR__"neitang",   
        ]));

        setup();
        replace_program(ROOM);
}
