//changan city

inherit ROOM;

void create ()
{
        set ("short", "ʯ��·");
        set ("long", @LONG
����һ��ʯ��·������ÿ�ն������������������߹���ʯ���ѱ�ĥ��
�ǳ��Ĺ�����·��������Ӧ��ͨ������ȣ�������������̨�׾��ǿ���
���䳡�ˡ�վ��������Կ������䳡�ϵ�佻����������Ȼ�����龰���
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"jqlang_1",
		"east" : __DIR__"moneyroom",
		"southdown" : __DIR__"wuchang1",
	]));

        set("outdoors", "xiao");
        setup();
	replace_program(ROOM);
}