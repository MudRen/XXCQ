// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ��û��ʲô�ر�ĵط���һ���鰸������ľ�Σ���������
��佻����Ӷ�������Ϣ�ĵط�����¥��һ������ֻҪ��С���ڣ����˾Ͳ�
��ȥ�ˡ���˵���ڹ������㣬ȴ���Ƿ��϶��㲻�ɵġ�
LONG);

	set("valid_startroom", 1);

	set("exits", ([
		"north" : __DIR__"jqlang_2",
		"up" : __DIR__"guanyu_2",
	]));

        set("objects", ([
                 __DIR__"npc/guiyuan": 1,
	]));

	setup();
	replace_program(ROOM);
}