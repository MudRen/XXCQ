//changan city

inherit ROOM;

void create ()
{
        set ("short", "��դ������");
        set ("long", @LONG
������������������ԱȽϰ�����һ�Σ�������Ϊ���˵������ջס�������
�����������Ǻ����ߵ�����ġ�����·�Ͼ��Ǿ�������˵Ŀ͵ꡰ�����ջ����·
�����������ھ��ǵ��ֻ��ꡰ��ʯի���������Ѿ�û��·�ˣ������������ס���
�����ֻ�����ô��ֻ���򶫱ߵ���·�߻�ȥ�ˡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
                "north" : __DIR__"choushizhai",
		"east" : __DIR__"shalan-w1",
                "south" : __DIR__"kedian",
        ]));

        set("objects", 
        ([
        ]));


        set("outdoors", "beijing");
        setup();
	replace_program(ROOM);
}