// Room: /d/shaolin/twdian1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����Ƕ����������������Ŵ�Ħ��ʦ��������ʿ�Ļ����Լ�һ
Щ����Ԫ�ϵ��ֻ�������ɢ�ҵط���������ţ�ľ��ȡ������˴��Ǳ���
���Ӵ�������֮������λ��������ֳ����飬���������
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"west" : __DIR__"twdian",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

