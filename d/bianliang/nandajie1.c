//changan city

inherit ROOM;

void create ()
{
        set ("short", "�ϴ��");
        set ("long", @LONG
��վ�ĵط��Ѿ����ǵ����϶ˣ����������ľ���Ρ����ϳ����ˣ���
�����ǻʵ۳����ߵ�·�����ԱȾ��������ֵ���Ϊ�����ֵ������Ǿ���
�����ġ������ջ������������һ����վ��������ֱ������ͨ������֡�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
                "west" : __DIR__"guangming",
		"east" : __DIR__"blyizhan",
		"north" : __DIR__"nandajie2",
		"south" : __DIR__"nanchengmen",
        ]));

	set("area", "����");

        set("outdoors", "bianliang");
        setup();
	replace_program(ROOM);
}
