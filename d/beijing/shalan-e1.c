//changan city

inherit ROOM;

void create ()
{
        set ("short", "��դ������");
        set ("long", @LONG
��ν��������������Ҷ԰���������Ϊ��Ҫ�ĵ��̣�����·��һ���Ǳ������
���ӻ��̣��������е�������Ʒ�������������򵽣�·�����Ǿ�������Ǯׯ֮һ��
��Ȼ�����ﲻ�ܴ�ܶ�Ǯ�����������ﲻ�������ѣ�������ͨ�˼ҵ�Ǯ���Ǵ浽��
��ġ����ƺ��м�С���̣��������Ǵ�դ���ֿڣ����������ͨ����ϵĸ�����
����
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"shalan-e2",
		"west" : __DIR__"shalan",
		"north" : __DIR__"qianzhuang",
		"south" : __DIR__"zahuopu",
        ]));

        set("objects", 
        ([
        ]));


        set("outdoors", "beijing");
        setup();
	replace_program(ROOM);
}