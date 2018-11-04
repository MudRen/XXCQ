// Room: /city/huichuntang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�ش���");
	set("long", @LONG
���Ǿ�����������һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�
ҩ���ϵļ��ٸ�С������ɢ�������ġ�����������ҽ����̫ʦ���ڲ輸��
�����Ժ��Ų裬��Ҳ������һ�ۡ�һ��С���վ�ڹ�̨���к��Ź˿͡�
LONG
	);

	set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/huoji" : 1,
		__DIR__"npc/shang" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));

	set("area", "����");

	setup();
	replace_program(ROOM);
}

