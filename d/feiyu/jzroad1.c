// Room: jzroad1.c

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����һƬ�����֡��м�һ��С·�����߶��Ǻ�ɭɭ�ļ��ɸߵ�������
���Ͻ��Ų����ɹ��������Ұ�������ζ����������Ͼ������䳡��
LONG );
	set("exits", ([
		"south" : __DIR__"wroad",
		"north"      : __DIR__"jzroad2",
	]));
//     set("objects", ([
//         "/d/feiyu/npc/yetu": 2,
//     ]));
	set("outdoors", "feiyu");

	setup();
	replace_program(ROOM);
}

