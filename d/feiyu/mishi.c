// Room: mishi.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
û�а�������û�л�Ƥ�ʣ�û�н������գ�Ҳû���κλ�������裬
���ݵ����棬ѣĿ���鱦�������ӵļ��ӣ�����������ƣ�����֬�ۣ���
��������ɫ��
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "southdown" : __DIR__"cailiaofang",
        ]));

        setup();
        replace_program(ROOM);
}
