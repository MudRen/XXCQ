// Room: /city/chouduanhang.c
// YZC 1995/12/04 

#include YIZHAN
inherit ROOM;

void create()
{
	set("short", "������վ");
	set("long", @LONG
����һ����ľ��Ӵ�ľ�������һ��С����װ�εĻ��㲻��һ��Ц
�����Ļ��վ��������������æ�����к�����̨������һ�����ţ���
�����ţ����洫�����˻��������������������͹�һ��(gu che)�ɡ�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));

	set("area", "����");

	setup();
}
