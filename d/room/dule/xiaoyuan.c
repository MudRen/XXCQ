// xiaoyuan.c ���־ӷ���֮СԺ
// Written by Doing Lu 1998/12/30

// �����ɷ���ʱ��
// /**/��ͷ����佫��ȥ��
// //**��ͷ����佫��ʹ�á�

#include <room.h>
/**/inherit ROOM;
//**inherit PRIVATE_ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
	������³���ʦ���Ĵ�Ķ��־ӵ���ǰСԺ��Ժ����������һЩɢ��
�ŵ���������Ұ�����Ե�������������ȻԺ�Ӳ���ȴ������һ�ְ�������ĸ�
����ʹ����˵�����ĳ��⣬������ʫһ�ף��ԺͼѾ���
        Ժ���ſ���һ��С����(paizi)�� ��������һ��С�ţ���������ͨ����
�ݵġ�����ͷ����³������������յ�СԺ�ӡ�
LONG
	);
        set("outdoors", "ground");
//**	set("valid_startroom", 1);

/**/	set("default_long", "����һ��СС��Ժ�ӣ������˲�֪����С����ɢ���ŵ�����������\n������һ��ľ�ţ��ű�����һ������(paizi)��");

	set("item_desc", ([
/**/		"paizi"   : "���־� - ³��\n",
//**		"paizi"   : "ROOM_NAME - ROOM_OWNER\n",
	]));

	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");

	set("exits", ([
		"out" : "/d/room/xiaoyuan",
		"north" : __DIR__"room1",
	]));

	create_door("north", "ľ��", "south", DOOR_CLOSED);

	setup();
}
