// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "é����");
	set("long", @LONG
����һ����ͨ��é�ݷ������Ӽ�ͽ�ıڣ������ǳ������ң�����û��
���ţ���Ϊ������ʵ����û��ʲô������͵�ģ�������û���ˣ�Ҳ���ǳ�
ȥ�μ��������ˡ�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"tulu5",
	]));

        set("objects",([
          "/d/quanli/npc/wang" : 1
         ]));
	setup();
	replace_program(ROOM);
}
