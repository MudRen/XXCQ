// Room: /city/yideju.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "һ�þ�");
	set("long", @LONG
	һ�þ���һ�Ҳ���ľ��̣����ڵ���ԭ���ּ��ϼ۸���ˣ��������ﳣ
�ۼ�����µһ��������ǣ�һ���ƣ�һ�������������̸��˵�أ����ȹ�һ�����
�ֵ�ʱ�⡣����Ļ����Ƚϲ������㲻���⣬�����ﵹ��һ��������Ϣ����ĥ
ʱ��ĺõط���
LONG
	);
	set("resource/water", 1);

	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"shalan-e2",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer3" : 1,
	]));

	setup();
	replace_program(ROOM);
}

