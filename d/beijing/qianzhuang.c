// Room: /city/qianzhuang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������ׯ");
	set("long", @LONG
	����һ�����ֺŵ���ׯ���ϰ��Ǿ������������˸߼�Ѫ���ϰ壬��Ϊ����
���ۺ��ʵ�������ǲ�Ϊ��֪�ĺ�̨��û�˻ỳ��Ǯׯ�����������������������
�Ǻܺã������ڸ��ϰ岻�������ѣ����������ﲻ�ܴ�̫���Ǯ�����ÿ��������
ֻ�ܴ�������ƽ����ҡ�(ȡǮ=qu,��Ǯ=cun,����=chazhang,�һ�=duihuan)
LONG
	);
	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"shalan-e1",
	]));

	set("objects", ([
		__DIR__"npc/gao" : 1
	]));

	setup();
	replace_program(ROOM);
}

