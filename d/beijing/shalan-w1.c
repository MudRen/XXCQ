//changan city

inherit ROOM;

void create ()
{
        set ("short", "��դ������");
        set ("long", @LONG
������Բ��Ǵ�դ��һ�������ֵĵط�����������������ȴ���Բ��٣���Ϊ��
��Ψһ��һ�ҵ��̾������ڽֵı��棬��Ȼ�����˼ҵ�����㲻������һʱ��
�ݶ����ٵ��̾����ǲ��ܱ���ģ�������ӵ�Ҳ����͵����Ķ����������������
���̵�������·�ϵĳ��ׯ����Ҳ�������������ƺ��Ƚ��徲�����������Ǵ�դ
����·���ˣ��ڳ�������Ҫȥ���Ｘ����Ҫ�������
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
                "north" : __DIR__"dangpu",
		"west" : __DIR__"shalan-w2",
		"east" : __DIR__"shalan",
                "south" : __DIR__"chouduan",
        ]));

        set("objects", 
        ([
        ]));


        set("outdoors", "beijing");
        setup();
	replace_program(ROOM);
}