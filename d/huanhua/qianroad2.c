//changan city

inherit ROOM;

void create ()
{
        set ("short", "��̳");
        set ("long", @LONG
ת��Ӱ�ڣ���һ�����Ļ�̳����̳�еĻ��а��˸ߣ�ĵ����õ�塢
�¼���ɫ���������ܲ����У�ɷ����������̳��������һ����ɫ����ߵ�
��¥�������ҵ���������Ե���®�������ط���
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"qianroad1",
		"south" : __DIR__"southlang",
		"west" : __DIR__"tingyudoor",
		"north" : __DIR__"northlang",
	]));

        set("objects", ([
                 "/kungfu/class/huanhua/baiyun": 1,
	]));

        set("outdoors", "xiao");
        setup();
	replace_program(ROOM);
}