// ɽèADX by snow 99-12-4

inherit ROOM;

void create ()
{
	set("short",  "�ٵ�");
	set("long",  @LONG
����һ��������ֱ�Ĺٵ�������·�棬����ݵ���ʮ���ۡ�����ͨ��
��͢�Ļʳǣ�����ͨ�������ǡ�
LONG);
	set("exits",  ([
		"northwest"  :  __DIR__"road3",
		"southeast"  :  __DIR__"road1",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
