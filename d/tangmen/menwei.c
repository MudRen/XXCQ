//menwei.c		�Ĵ����š��

inherit ROOM;

void create()
{
	set("short", "�");
	set("long", @LONG
��������źС���Ĳ��ƽ�����ŵ������Ƕ�ϲ����������Ƚ�
�������˵��书�ߵͣ������ɲ�ҪС����Щ���ˣ�����Ҳ�������֡�
����������ͤ�ˮ��
LONG);
	set("exits", ([	"east" : __DIR__"shuige1",]));
	set("objects", ([__DIR__"npc/menwei" : 2,]));
	set("area", "����");
	setup();
	replace_program(ROOM);
}