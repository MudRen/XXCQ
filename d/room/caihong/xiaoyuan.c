// xiaoyuan.c �ʺ�ӷ���֮СԺ
// Written by Doing Lu 1998/1/6

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
	������³���ʦ���Ĵ�Ĳʺ�ӵ���ǰСԺ��Ժ����������һЩɢ��
�ŵ���������Ұ�����Ե�������������໹��һ�Ŵ�����֦Ҷïʢ��ʹԺ���淢
�Ե�������ֻ��żȻ�����������ϵ����ߴߴ�����Ľ��š�
        Ժ���ſ���һ��С����(paizi)�� ��������һ��С�ţ���������ͨ����
�ݵġ�����ͷ����³������������յ�СԺ�ӡ�
LONG
	);
        set("outdoors", "ground");
//**	set("valid_startroom", 1);

/**/	set("default_long", "����һ�䲻��Ժ�ӣ����ܵ�ǽ�����ģ�ǽ�ǵ�һ�ô���������ס��" +
/**/			    "���Ժ�ӣ�ʱ���������������ЪϢ���ñߵ�С�������Ŀ��ţ���" +
/**/			    "�����������὿�ޡ�\n������һ��ľ�ţ��ű�����һ������(paizi)��");

	set("item_desc", ([
/**/		"paizi"   : "�ʺ�� - ³��\n",
//**		"paizi"   : "ROOM_NAME - ROOM_OWNER\n",
	]));

	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");

	set("exits", ([
		"out" : "/d/room/xiaoyuan",
		"north" : __DIR__"room1",
	]));

	create_door("north", "����", "south", DOOR_CLOSED);

	setup();
}
