// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�˷�");
	set("long", @LONG
�����ǽ�®���˷���佻��������²�ҵ���࣬ÿ�յ���ĿҲ�Ƿ��࣬
�����Ҷ��ֱ�ſ����������֮ǰ�ϵļ���˶��ţ�һ����׳�ĺ���������
�߲�ʱ��Ѳ���š����������ҵĹܼҡ������ա�����Ҳ����������ÿ��
������ѵĵط�������㵽����Ǯ��ʱ�򣬲�������ܼ�Ҫһ�¡�
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
	set("exits", ([
		"west" : __DIR__"wuroad2",
	]));
        set("objects", ([
                 "/kungfu/class/huanhua/jingzhong" : 1,
	]));

	setup();
	replace_program(ROOM);
}