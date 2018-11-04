// Room: /d/shaolin/qfdian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�о���");
	set("long", @LONG
���Ǿ����о��á������ں����ؽ࣬���õ����й��лƽ����ֵġ���
����ɫ��ɫ���ǿա��͡��ຣ�ޱߣ���ͷ�ǰ����������֡����ڰ��ж�ʮ
��������ţ���ɮ���ڴ˹����о�(songjing)�������¸�ɮľ����ʦ�ڴ�
������
LONG );
	set("valid_startroom", 1);

	set("exits", ([
		"southdown" : __DIR__"wuchang",
	]));

	set("objects",([
		"/kungfu/class/shaolin/mudie" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_songjing", "songjing");
}

int do_songjing()
{
	object me, *inv;
	int i;
	mapping skill, myfam;

	me = this_player();
	myfam = (mapping)me->query("family");
	inv = all_inventory(me);

	if (myfam["family_name"] != "������")
		return notify_fail("�㲻�����ֵ��ӣ������������о���\n");

	for(i=sizeof(inv)-1; i>=0; i--)
	if (inv[i]->query("id") == "jing")
	{
		skill = (mapping)inv[i]->query("skill");
		if (skill["name"] == "buddha"
		&& skill["max_skill"] == 80
		&& skill["min_skill"] == 41)
		{
			if (me->query_skill("buddha",1) < 80)
				return notify_fail("��������ķ��ȼ�������û�ʸ��������о���\n");
			if (me->query_skill("buddha",1) > 150)
				return notify_fail("��������ķ��Ѿ������൱��������������о��Ѿ��ò�������ˡ�\n");
			if (me->query("jingli") < (70 - me->query("bac")))
				return notify_fail("���Ѿ��޷����о����о��ˣ�����ЪЪ�ɡ�\n");
			if (!objectp(present("mudie dashi", environment(me))))
				return notify_fail("ľ����ʦ���ڣ�û������ָ�����о���\n");

			tell_object(me, "���ų��������������ľ����ʦ��ָ���¿�ʼ�о���\n");
			tell_object(me, "��������ķ���������˽�һ���ļ��\n");
			me->add("jingli", me->query("bac") - 70);
			me->improve_skill("buddha", me->query("bac"));

			return 1;
		}

		return notify_fail("�Ȿ���鲻�������������о���\n");
	}

	return notify_fail("û�о�����ô�о����㲻�ǿ���Ц�ɡ�\n");
}