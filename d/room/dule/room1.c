// room1.c ���־ӷ���֮����1
// Written by Doing Lu 1998/12/30

// �����ɷ���ʱ��
// /**/��ͷ����佫��ȥ��
// //**��ͷ����佫��ʹ�á�

#include <room.h>
/**/inherit ROOM;
//**inherit PRIVATE_ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
	������³���ʦ���Ĵ�Ķ��־ӵ�С�ݣ��Ӿ��»�ľ�񴰻�����ϡ��
�Կ���Ժ�ӵľ��ۣ���������һ����ľ�������ݽ���һ�����������ɨ��һ����
Ⱦ��������С��ȴ���˸о�����ܰ������
LONG
	);

	set("no_fight", 1);
//**	set("sleep_room", 1);

/**/	set("default_long", "����һ�䲻������ӣ�͸�����µĻ�ľ�񴰻���ϡ���Կ���Ժ�ӵľ��ۡ��ݽǷ���һ�Ŵ�������ȥ�ǳ����ʡ�");

	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");

	set("exits", ([
		"south" : __DIR__"xiaoyuan",
	]));

	create_door("south", "ľ��", "north", DOOR_CLOSED);

	setup();
}
