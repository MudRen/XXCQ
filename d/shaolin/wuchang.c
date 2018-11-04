// Room: /d/shaolin/wuchang.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡���ǧ���
��̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����߽��ϻ���������ɳ�ӣ�ʮ
����ɮ��������ϰ���ա������������һ���䳡��
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"wuchang4",
		"east" : __DIR__"wuchang2",
		"west" : __DIR__"wuchang1",
		"north" : __DIR__"wuchang5",
		"northup" : __DIR__"sjtang",
	]));
	set("outdoors", "shaolin");
	set("objects",([
		__DIR__"npc/mu-ren" : 2,
	]));
	setup();
}

void init()
{
	object me;
	mapping skill_status;
	string *sname;
	int i, level; 
	float exper;

	me = this_player();

	exper = to_float(me->query("combat_exp"));

	if ( !(skill_status = me->query_skills()) ) return;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
		if( pow(to_float(level), 3.0) / 10.0 > exper 
		&& exper > 100.0
		&& sname[i] != "buddhism"
		&& sname[i] != "literate"
		&& sname[i] != "taoism" ) 
		{
			level = ceil( pow( exper*10.0, 0.333333) );
			me->set_skill(sname[i], level);
		}
	}
}



