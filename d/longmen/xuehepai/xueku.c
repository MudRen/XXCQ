//xueku��c  by baby

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "Ѫ��");
	set("long", @LONG
�˴�ΪѪ���ɵ�Ѫ�ߡ���ṹ���һ�����ƹ�ǣ���ͨ�˴����
ǽ�����в���������ʦ����������ѧ��Ҫ��ϸϸ��Ħ���ƺ�����������
�á�����������ԼԼ�·�����������������Ѫ�ӳ��İ�ƥ�񿥵͵͵�˻
�������뵽�⣬���������ӿ죬����Ŀ��һ��Ѫ�ӳ��Ļֺ����ơ�
LONG);	
	set("valid_startroom",1);
	set("objects",([
		"/kungfu/class/xuehepai/cao" : 1,
	]));
	set("exits", ([
		"down" : __DIR__"xueheting",
		"north" : __DIR__"shandao1",
		"west" :  __DIR__"xueyu",
		"south" :  __DIR__"qixuetang",
		"east" :  __DIR__"xuezhutang",
	]));
        set("area", "����");
        setup();
            replace_program(ROOM);
}
