// Room: shiyanshi.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.4.16
// �޸ĳ�������
// 

inherit ROOM;
void create ()
{
        set ("short", "ʵ����");
        set ("long", @LONG
������С�ֺ�����ҩƷҩ����ʵ���ң���������ż��ų���
�ӣ������ϰ��źܶ�ƿ�Ӻ�ҩƷ��������������������Ū��ƿ
��ҩƷ��ǽ����һ���������������ķ��ı��������������¼ʵ
����̡���ʱ���˵������������ȥȡ���ϣ�Ҳ���˵��������
��������ʵ��Ʒ��
LONG);
        set("area","����");
        set("exits", ([
                "east" : __DIR__"liandanfang",
                "west" : __DIR__"dayuan",
                "north" : __DIR__"ziliaoshi",
        ]));
        setup();
        replace_program(ROOM);
}
