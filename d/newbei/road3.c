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
		"north"  :  __DIR__"road4",
		"south"  :  __DIR__"road2",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
