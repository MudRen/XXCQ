// room3.c �ʺ�ӷ���֮����3
// Written by Doing Lu 1998/1/6

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
	������³���ʦ���Ĵ�Ĳʺ�ӵĲ��ң������ﲻ�Ǻܴ����ڻ���
�տյģ�ʲôҲû�С�
LONG
	);

	set("no_fight", 1);
//**	set("sleep_room", 1);

/**/	set("default_long", "������ǲ��ң������ÿ��˳�ס�ĵط����ݽ���һ�Ŵ���");
	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");

	set("exits", ([
		"west" : __DIR__"room1",
	]));

	setup();
}
