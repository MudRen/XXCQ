// zoulang2.c ����2
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
        set("long",
"����ͨ���������õĵ�·��������һ��Բ�εĹ��ţ��������������
����ʹ���������ﶼ�����ŵ����㡣�����ֺ�������͸��һ��ɱ�����㲻
�����˸����䡣����\n"
	);
	set("valid_startroom",1);
	set("outdoors","huafu");
	set("exits",([
		"north" : __DIR__"huazhen1",
		"southwest" : __DIR__"dating",
	]));
	setup();
	replace_program(ROOM);
}
