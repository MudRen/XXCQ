// zoulang1.c
// made by lks

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
����һ�����������ȣ�ͨ���¸�������������������ëձ��ëձ�Ѿ�
���ɴ��ף�����ľ���ϻ���л�����棬�����Щ��ʱ�˵��ֻ���ÿ����
�˲�������һ����¯���������̴�ͭ�������γ�����֮����һ��
LONG);
	set("valid_startroom",1);
	set("outdoors","wenzhai");
	set("exits",([
	    "north"      : __DIR__"jiashan",
	    "east"      : __DIR__"zoulang2",
	]));
	setup();
	replace_program(ROOM);
}
