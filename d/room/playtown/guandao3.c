// by ɽèADX @ snow 99-12-4

inherit ROOM;

void create ()
{
	set("short",  "�ٵ�");
	set("long",  @LONG
����һ��������ֱ�Ĺٵ�������·�棬����ݵ���ʮ���ۡ�����ͨ��
�����ǣ�������һ����Ҵ塣
LONG);
	set("exits",  ([
		"west"  :  __DIR__"guandao4",
		"east"  :  __DIR__"guandao2",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
