// dongting.c ����
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","����");
	set("long",
	"������Ȼ��ƫ���������Ѿ���������Ϊ�¸����ӵ��������ˣ��¸���
���ŵ��Ӿ�����������ϰ�������ģ������¸��ĸ��֡�����ʮʯ��Ҳ����
������ָ����ӵ��书����������û������֮��İ��衣\n"NOR
     	);
     	set("valid_startroom",1);
	set("exits",([
     		"east"  : __DIR__"dongxiangfang",
     		"west"  : __DIR__"dating",
     		"north" : __DIR__"wuqiku",
     	]));
     	setup();
     	replace_program(ROOM);
}
