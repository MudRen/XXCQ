// room1.c �ʺ�ӷ���֮����1
// Written by Doing Lu 1998/12/30

// �����ɷ���ʱ��
// /**/��ͷ����佫��ȥ��
// //**��ͷ����佫��ʹ�á�

#include <room.h>
/**/inherit ROOM;
//**inherit PRIVATE_ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	������³���ʦ���Ĵ�Ĳʺ�ӵ�������͸����������ԼԼ���Կ���
Ժ�ӵ�ȫò����������İ��ż������ӣ�����һ�ź�ľ���ӣ��������һ����ĥ
��ϸ���塣Ҳ������������Ժ��������̸��˵�أ���Ъ�ﻹ������ɱ���֡���
������ͨ���������ӡ�
LONG
	);

	set("no_fight", 1);

/**/	set("default_long", "���Ǵ�����͸��������������ԼԼ�Ŀ���Ժ�ӵ�ȫò����������İ��ż������ӣ�" +
/**/			    "����һ�ź�ľ���ӡ����˳�������Ϳ�����̸�۽������𣬸п��˼����飬��Ъ" +
/**/			    "������С�ã�������������������˵ķ��䣬�ұ���һ��С�䡣");

	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");

	set("exits", ([
		"south" : __DIR__"xiaoyuan",
		"west"  : __DIR__"room2",
		"east"  : __DIR__"room3",
	]));

	create_door("south", "����", "north", DOOR_CLOSED);
	create_door("west",  "����", "east",  DOOR_CLOSED);

	setup();
}
