// Room: liaowangtai.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����̨");
        set ("long", @LONG
�����ǡ���ֹ�ء��Ե�һ������̨�������Ϊ�˹۲����ܻ����õİ�
����������ɽ���ٶ��ˣ����Կ��������ؿ��������һ����㳡������
Ӧ�þ��Ƿ���ɽׯ�Ĵ�㳡�ɣ���������˼��£��е�����ʮ�����£�ʹ
���Ŀ�������
LONG);
        set("area","����");
        set("outdoors", "feiyu");

        

        set("exits", ([
                "south" : __DIR__"renzhiguan",
        ]));
        setup();
        replace_program(ROOM);
}
