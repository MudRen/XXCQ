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
         "north"  :  "/adm/npc/pet/roupu",
		"south"  :  __DIR__"guandao7",
		"northeast"  :  __DIR__"guandao5",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
