// Room: wuchang.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.17
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�䳡");
        set ("long", @LONG
�������ֺŵ��䳡�����������ֺŵĵ�������ϰʩ�����ɵ�
�ط������ﵽ����������������Ϣ�����ֺž����û�������ϰ��
ԭ�����︽�����Ƿس�������ȥǰ����һ����ʬ����������
��������
LONG);
        set("area","����");
        set("outdoors", "wenjia");
	set("valid_startroom", 1);

        set("exits", ([
                "north" : __DIR__"liangongfang",
        ]));
        setup();
        replace_program(ROOM);
}
