// ɽèADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create ()
{
	set("short",  "��ѩɽ��");
	set("long",
"��������ѩɽ��ɽ�ţ�һ���ó���ʯ�̳ɵ�̧��ʰ�����ϡ�������Լ\n"
"����ɽ����һ��ɽׯ���ɫ���ݶ���ӳ���������С�\n"
"̧ͷ�Ϳ��Կ����߸ߵ���ѩ��: \n"
);
	set("exits",  ([
		"westup"  :  __DIR__"shanyao",
		"eastdown"  :  __DIR__"road8",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
