//changan city

inherit ROOM;

void create ()
{
        set ("short", "����Ժ");
        set ("long", @LONG
����Ժ�ͱ���Ժ�������ԵñȽϵ����ң��������϶���һЩ���ɢ
�ҵı���������Ҳ�������������Ժ�Ķ�����һ�����ص��᷿����®
�Ļ����פ���������Ϊ��ª�����᷿����Ȯ�������ڣ�����Ʈ��֮��
ȴ�ǽ�®�ķ��á�
LONG);
	set("valid_startroom", 1);

        set("objects", ([
	]));

        set("exits", 
        ([
		"north" : __DIR__"southlang",
		"east" : __DIR__"huzu",
		"west" : __DIR__"eatroom",
		"south" : __DIR__"quanzu",
	]));

        set("outdoors", "xiao");

        set("objects", ([
		__DIR__"npc/guanjia" : 1,
	]));

        setup();

	replace_program(ROOM);
}