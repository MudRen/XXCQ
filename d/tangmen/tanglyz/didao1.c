//didao1.c		�Ĵ����š��ص�

inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ���ص���������ȴ������һ����ͨ�ĵص������Ｋ��
������м�ʮ������������Ϸʨ������������磬������ȴ�޷���
�����������Դ���ص���ǰ���첻֪ͨ��δ��������������һ��
Ī���Ŀ־壬�����뿪�ĺá�
LONG);
	set("exits", ([
			"southdown" : __DIR__"didao2",
	]));
	set("area", "����");
	setup();
}

void init()
{
	object me, killer;
	me = this_player();

	if ( wizardp(me) )
		return;

	if ( ( (string)me->query("family/family_name") == "�Ĵ�����" )  && me->query_temp("tanglyz"))
		return;
	else
	{
		if ( userp(me) )
		{
			message_vision("ͻȻ��ʯ���д���һ�����:���ô������ߣ���������\n", me);
			message_vision("�⻬��ʯ���ϳ�����һ��ʯ�ţ�һ��������ʿԾ�˳�������$N��������������\n", me);
			killer = new(__DIR__"npc/killer");
			killer->move(environment(me));
			killer->kill_ob(me);
			me->fight_ob(killer);
		}
	}
	return;
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if (  ( dir == "southdown") && objectp(present("killer", environment(me))) )
	{
	 message_vision("��ʿһ�������������������ߣ�û��ô���ף�����", me);
	 return notify_fail("\n");
	}
	return ::valid_leave(me, dir);
}