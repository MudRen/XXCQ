// Room: shulin.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "���ֱ�");
        set ("long", @LONG
�����Ե������ï�ܵ���Ҷ�ڵ������⣬��ʹ������Ļ����Ե���
����ɭ��һ��紵������Χ����Ҷ��ɳɳ�������졣ʹ�㲻���ӿ��˽Ų�
�������ϣ����ǵ���̨�ˡ�
LONG);
        set("area","����");
        set("valid_startroom", 1);
        set("outdoors", "feiyu");

        set("exits", ([
                "south" : __DIR__"diaoyutai",
                "north" : __DIR__"xiaojing1",
                
        ]));
        setup();
        replace_program(ROOM);
}

