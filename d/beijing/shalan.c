//changan city

inherit ROOM;

void create ()
{
        set ("short", "��դ���ֿ�");
        set ("long", @LONG
�����ϳǵ�һ����Ҫ�Ľֿڣ������������������������У�����������ȥ��
�Ѿ����Կ��������ų�¥�ˣ����������Ǳ��������ֵ������ˣ��򶫺��������Ǵ�
դ���Ķ������֣��������ճ�����ȱ�ٵ��̼Ҷ��������������ϡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"shalan-w1",
		"east" : __DIR__"shalan-e1",
        ]));

        set("objects", 
        ([
        ]));


        set("outdoors", "beijing");
        setup();
	replace_program(ROOM);
}