// ROOM xiaohu.c

inherit ROOM;

void create()
{
        set("short","С��");
        set("long",@LONG
���Ǿ���һ�����̵�С��������ʱ��ˮ������У�����ˮ��������
�������̰��ö���ˮ��������̧ͷ������ֻ��Զ����ɽ���죬�������֣�
�꾰��Ȥ��������ƺ�վ��һλ������
LONG);
		set("valid_startroom", 1);

		set("exits",([
                "southeast" : __DIR__"houshan",
        ]));
        set("outdoors", "huashan");

        set("objects", ([
              __DIR__"npc/baiqingyi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
 
