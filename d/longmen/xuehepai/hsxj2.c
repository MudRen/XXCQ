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
                "west" : __DIR__"tanbian",
                "south" : __DIR__"hsxj1",
        ]));
        setup();
        replace_program(ROOM);
}