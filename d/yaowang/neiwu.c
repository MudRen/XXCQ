// Room: ����ҩ��
// By ɽèadx @ ����Сѩ 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǻش���ר�ų���ҩ��ׯ���Ӿ������Ƶĳ�ҩ�ĵط���
ҩ��������༼�ո߳��ĵ��ӣ�������ʱ������һЩ��ҩ
�ͷ���������ۣ���Ч��һ���ҩ��Ч�����ѡ�
LONG );
	set("area", "������");
	set("areb", "�ش���");
	set("no_clean_up", 1);
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"nanting",
	]));
	set("objects", ([
		__DIR__"npc/huoji2" : 1,
	]));
	setup();
	replace_program(ROOM);
}
