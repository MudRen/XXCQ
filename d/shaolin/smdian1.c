// Room: /d/shaolin/smdian1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����Ƕ����������������Ŵ�Ħ��ʦ��������ʿ�Ļ����Լ�һ
Щ����Ԫ�ϵ��ֻ�������ɢ�ҵط���������ţ�ľ��ȡ������˴��Ǳ���
���Ӵ�������֮������λ����ɮ���������붨���������ĵ�����������
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"west" : __DIR__"smdian",
	]));
	set("objects",([
		__DIR__"obj/muchui" : 1,
	]));
	setup();
	replace_program(ROOM);
}

