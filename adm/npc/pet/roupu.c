// ���� ROOM
// By ɽèAdx @ snow 99-12-12

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�䲻������̣��ϰ������������ڰ������������ϣ��и�
�������æµ�ţ������Ϸ����������⡣��������Ĺҹ��Ϲ�������
�õ����⣬����ûʲô���⡣
LONG );

	set("exits", ([
         "south"  :  "/d/room/playtown/guandao6",
	]));

	set("objects", ([
		__DIR__"tufu":1,
        __DIR__"petowner":1,
	]) );
	setup();
	replace_program(ROOM);
}
