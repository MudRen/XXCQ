//changan city

inherit ROOM;

void create ()
{
        set ("short", "���䳡");
        set ("long", @LONG
����һ��������Ľ��䳡���ǽ�®���ӱ���ĵط���佻��Ĵ�����
��ʮ���֮һ�ı������������ֱ��䲢����佻������书���ڽ��䳡����
����һ�����䳡����һЩ�����豸�������䡣
LONG);
	set("valid_startroom", 1);

        set("objects", ([
                 "/kungfu/class/huanhua/beifen": 1,]));

        set("exits", 
        ([
		"northup" : __DIR__"wuroad2",
		"east" : __DIR__"wuchang2",
		"west" : __DIR__"wuchang3",
	]));

        set("outdoors", "xiao");
        setup();
	replace_program(ROOM);
}