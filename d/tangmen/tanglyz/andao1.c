//andao1.c		�Ĵ����š��ص�

inherit ROOM;

void create()
{
	set("short","�ص�");
	set("long", @LONG
����һ���ص���һ������������ͻȻ������һ�ţ���ʲô����
�����������������ܾ���������˫�۾��ڶ����㿴�����������ֺ���
��Ϣ���������һ���붼��������������������һ˿����������
LONG);
	set("exits",([
		"south" : __DIR__"andao2",
		"north" : __DIR__"didao4",
	]));
	setup();
	replace_program(ROOM);
}