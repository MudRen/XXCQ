//changan city

inherit ROOM;

void create ()
{
        set ("short", "���ǹ㳡");
        set ("long", @LONG
���Ǿ������Ĺ㳡��Ҳ�����Ӿ���������Ҫ����Ľֿڣ���������
�������߹�������Ϊ����Ѳ�����ٲ�������Ѳ�ߣ����Ժ�������������ͣ
�������������ǻ����֣��ᴩ�����ǻƿ��������ϾͿ쵽�������ˡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
                "west" : __DIR__"huangkudajie5",
		"east" : __DIR__"huangkudajie6",
		"north" : __DIR__"huangshanjie5",
		"south" : __DIR__"nandajie2",
        ]));

	set("objects", ([
             __DIR__"npc/long" : 1,
               __DIR__"npc/dog" : 3,
	]));

	set("area", "����");

        set("outdoors", "bianliang");
        setup();
	replace_program(ROOM);
}
