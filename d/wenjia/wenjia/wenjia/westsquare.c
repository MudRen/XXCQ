// Room: westsquare.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "���㳡");
        set ("long", @LONG
����������ǰ�Ĺ㳡��ͬ������һ����Ҳû�У�һ��紵���㲻����
�˸��������һ����Ͽ��뿪������뷨�������Ѿ�û�д���ˣ�������
֮����һЩС·�����ѵ�ͨ��ɽ�ϣ�����ͨ�������ֺŵ�ɽ·��
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"square",
                "west" : __DIR__"shanjing1",
        ]));

        setup();
        replace_program(ROOM);
}
