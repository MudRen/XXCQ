//changan city

inherit ROOM;

void create ()
{
        set ("short", "Ӱ��");
        set ("long", @LONG
�߽���®��ӭ���������߸ߵ�Ӱ�ڣ�����ɫ��Ӱ��������������һ
��������������裬�ǿ�ʼ�߲���ǽ���Գ����Ĺ��ϡ��ƹ�������������
��®�ˣ�վ����������ȫ������Ӱ��������龰��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"out" : __DIR__"gate",
		"west" : __DIR__"qianroad2",
	]));

        setup();
	replace_program(ROOM);
}