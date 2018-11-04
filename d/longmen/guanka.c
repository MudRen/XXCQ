inherit ROOM;

#include <ansi.h>
void create()
{
      set("short","�ؿ�");
      set("long",@LONG
���ﱻ��ʱ���һ���ؿ���һ����������ָ��Ѫ���ɵ��Ӷ������ο�
���м�飬���տ��Թ���������ʿһ�ɲ���ͨ��������������ʿ�����ں���
�����������ۡ�������Ѫ���ɷ�ɽ�ˣ����ڽ��ϡ�
LONG);
	set("valid_startroom",1);
	set("renshu",0);
	set("objects",([
		"/kungfu/class/xuehepai/huwei" : 1,
	]));
	set("exits",([
		"west"  : __DIR__"xiaolu3",
		"east"  : __DIR__"guanka1",
	]));
	set("outdoors", "����");
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam,party;
	myfam=(mapping)me->query("family");
	party=(mapping)me->query("party");
	if (me->query_temp("shouwei"))
		return notify_fail("�������������������ܵ����߶���\n");
		if (((myfam && myfam["family_name"] != "Ѫ����") || (!myfam && party)) && (dir=="east") )
		{
			if (present("huwei", environment(me)))
				return notify_fail("����������ס��ǫ��˵����Ѫ�����Ѿ������ˣ����ݽ�����ʿ�������ڣ�\n���ǰ�ʦ�Ļ�"
					+ RANK_D->query_respect(me) +"�������ȥ�ɣ��������ûȤ��\n");
		}
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_shouwei","shouwei");
}

int do_shouwei(object me)
{
	object *inv;
	int i,j=0;
	me=this_player();
	inv=all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++)
		if(inv[i]->query_temp("shouwei"))
			j++;
	if (j>=4)
		return notify_fail("�������ֻҪ�������ء�\n");
	if (!(me->query_temp("xhjob_start")))
		return notify_fail("��û�б�ָ�ɵ�������������Ҫ������£�\n");
	if (me->query_temp("shouwei"))
		return notify_fail("����������Ѫ���ɵĹؿ�ͨ����\n");
	message_vision(HIC"$N���Ӿ��񣬿�ʼ������ߵ�ÿһ�����ˡ�\n"NOR, me);
	me->apply_condition("xhquest", 6);
	return 1;
}
