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
		"southwest"  :  __DIR__"guandao6",
		"east"  :  __DIR__"guandao4",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
