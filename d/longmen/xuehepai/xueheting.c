//xueheting��c  by baby

#include <room.h>

inherit ROOM;

void create()
{	
	seteuid(getuid());
	set("short", "Ѫ����");
	set("long", @LONG
�������Ѫ���ɵĲر����ˣ�����ǽ�ڹ������ˣ����в�����������
���黭��Ʒ�����������б����������ǣ��������ֵ�Ѫ�ӳ�(�˿�����)��
�����������������Ŷ���������ѧ�ľ����ĵã������֮��ѧ����°빦
�������ǡ��Ƶ�������˭���������˿�Ѫ������Х���¡���
LONG);	
	set("valid_startroom",1);

	set("objects",([
		"/kungfu/class/xuehepai/ren" : 1,
                "/d/longmen/xuehepai/obj/che" : 1,
	]));

	set("exits", ([ "up" : __DIR__"xueku",]));

        set("area", "����");

        setup();
}
