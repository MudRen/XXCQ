// Room: /d/shaolin/wuchang3.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ���
��̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡�м������Ų���ľ�˺�
�ݰС����߽��ϻ���������ɳ�ӣ�ʮ����ɮ��������ϰ���ա����������
�����µ����ֽ���Ժ��
LONG
	);
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"wuchang",
		"north" : __DIR__"fzlou",
	]));

	set("outdoors", "shaolin");

	set("objects",([
		"/kungfu/class/shaolin/tiewen" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if( !me->query("luohan_winner") && !wizardp(me))
	{
		if (dir == "northup")
		{
			return notify_fail("�㼶�𲻹������ܽ����ĦԺ��\n");
		}
	}
	return ::valid_leave(me, dir);
}

