// room2.c �ʺ�ӷ���֮����2
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
	������³���ʦ���Ĵ�Ĳʺ�ӵ�������������ܴ󣬵������ڻ���
�տյģ�ʲôҲû�С�
LONG
	);

	set("no_fight", 1);
//**	set("sleep_room", 1);

/**/	set("default_long", "���������������������Ϣ�ĵط����Ҳ���һ�Ŵ󴲣�����ȥ˯��һ���������" +
/**/			    "��Զ������һ���¹񡣴����������ROOM_POSITION��������" +
/**/			    "�������ڶ��࣬�����ǻ�����˵ĵط���");
	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");

	set("exits", ([
		"east" : __DIR__"room1",
	]));

	create_door("east",  "����", "west",  DOOR_CLOSED);

	setup();
}