//qingyunge��c           Ѫ����--���Ƹ�

inherit ROOM;

void create()
{
        set("short", "���Ƹ�");
	set("long", @LONG
������Ѫ���ɵ����Ƹ�ͨ�����Ӷ�ϲ�������ﳩ̸�����еĶ�Թ��
�𣬻���ʱ�������Ե��书�ĵã���������ѧ����һ��¥���������ﾭ
�����������֣���Ѫ��ƽ�յ�������ǲ�ͬ��
LONG);
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("exits", ([	
		"southwest" : __DIR__"xuehuatang",
		"east" : __DIR__"chufang",
	]));
	setup();
}
