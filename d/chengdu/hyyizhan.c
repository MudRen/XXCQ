// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit YIZHAN;

void create()
{
	set("short", "������վ");
	set("long", @LONG
����һ������Ӹ�������һ��С���ӣ������ǰ��һ���ƾɵ�ľ�ƹ�
̨����̨�϶���һЩ���ӣ�ȴû���ˣ���̨������һ�����ţ��������ţ�
���洫�����˻��������������������͹�һ��(gu che)�ɡ�
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"hyroad2",
	]));

	setup();
}