// Room: houyuan.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.4.10
// �޸ĳ�������
// 

inherit ROOM;
void create ()
{
        set ("short", "��Ժ");
        set ("long", @LONG
������С�ֺŵĺ�Ժ��������ͨ��ҩ��ıؾ�֮·��һ��С
·���ϵ����Ĺᴩ��һ��Ժ�ӡ��������С�ֺ���ҩ��ҩ���
�����Ǵ�Ժ��
LONG);
        set("area","����");
	set("valid_startroom", 1);
        set("outdoors", "wenjia");

        set("exits", ([
                "south" : __DIR__"dayuan",
                "north" : __DIR__"yaotian1",
        ]));
        setup();
        replace_program(ROOM);
}
