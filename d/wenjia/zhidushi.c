// Room: zhidushi.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.4.10
// �޸ĳ�������
// 

inherit ROOM;
void create ()
{
        set ("short", "�ƶ���");
        set ("long", @LONG
����С�ֺŵ��ƶ��ҡ���ʵ������ʵ��õ�ҩƷ�ͻ��õ���
�����������졣��������칤��һӦ��ȫ�������Ǵ�Ժ��������
���ǲ����ҡ�
LONG);
        set("area","����");
	set("valid_startroom", 1);
        set("exits", ([
                "east" : __DIR__"dayuan",
                "down" : __DIR__"cailiaofang",
        ]));
        setup();
        replace_program(ROOM);
}
