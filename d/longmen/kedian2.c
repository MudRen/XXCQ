inherit ROOM;

void create()
{
        set("short", "�͵��¥");
        set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ���
�Ĵ�����һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������
¥�µ�С��������Ǯ������˯����
LONG );
        set("exits", ([
                "down"  : __DIR__"kezhan",
                "enter" : __DIR__"kedian3",
        ]));
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


