// Room: shanjing1��c

inherit ROOM;
void create ()
{
        set ("short", "ɽ��С��");
        set ("long", @LONG
������һ������������ɽ��С��һֱ�����Ϸ������š�С�����߶���
��ֵ���ʯ����Χû��һ����Ӱ�����ƺ�������ˮ��������������������
���ٲ���Զ�ˡ�
LONG);
        set("area","����");
        set("outdoors","����");

           set("valid_startroom",1);
        set("exits", ([
                "north" : __DIR__"hsxj2",
                "south" : __DIR__"hsxiaolu4",
        ]));
        setup();
        replace_program(ROOM);
}
