// Room: qianting.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "ǰ��");
        set ("long", @LONG
�����Ƿ������ܲ���ǰ�����ߵ������ʱ������һ����ɱ�����ա���
�����ߵ�ǽ���ϸ�����һ������Ծ���š�����ǰ���������д�š�������
�á������м���һ�Ż�Ƥ�Σ����������վ��һ�ŷ������ĵ��ӡ�������
�������������д��µĵط�������ȥ������ͨ��ƫ�����š����������
�������䳡��
LONG);
        set("area","����");
        set("valid_startroom", 1);

        set("exits", ([
                "south" : __DIR__"lysquare",
                "northeast" : __DIR__"dongpianting",
                "northwest" : __DIR__"xipianting",
                "east" : __DIR__"dongwuchang",
                "west" : __DIR__"xiwuchang",
        ]));

        setup();
        replace_program(ROOM);
}
