// Room: eastsquare.c
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
֮����һЩС·�����ѵ�ͨ��ɽ�ϣ�����ͨ�������ֺŵ�ɽ·����·����
��һ��ľ��(mupai)��
LONG);
        set("area","����");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("item_desc", ([
                 "mupai" : "�����������ֺ�\n��  �棺���ֺ�\nɽ·��᫣����Ṧ��������ȥ��\n                    ����\n",
        ]));

        set("exits", ([
                "eastdown" : __DIR__"huoroad1",
                "west" : __DIR__"square",
                "northeast" : __DIR__"siroad1",
        ]));

        setup();
        replace_program(ROOM);
}
