// Room: /d/playertown/xuemeiting.c ѩ÷ͤ
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
        set("short", "ѩ÷ͤ");
        set("long", @LONG
����һ���ǳ����µ�Сͤ�ӣ�����ɫ��ͤ�������������񳤵���
�������ڱ��̵ĺ�ˮ�ߣ�ͤ�ӵ���Χ���ż���÷������������ѩ��ʱ
�򣬺�÷��������ʱ�������ⶥ��ͤ��������������������ʱ������
���ٴ���ᣬ�����صİ���Ϸ��Ϊ��ԧ��ͤ����
LONG );
        set("outdoors", "playertown");
        set("exits", ([
                "west"  : __DIR__"road5",
        ]));
        setup();
        replace_program(ROOM);
}
