// wuqiku.c ������
// mlf���,lks���

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","������");
	set("long",
	"�������¸��������ֿ⣬�������ֻ����������ȫ����������ǽ�ı�
�����ϰڷŵĶ��ǳ�������ǹ��ì��ꪣ����������棬�ң�鳵ȡ������
���Լ�ϲ������������ʦ����̡���Ȼ��Ҳ�����Ȱ�ʦ����������Ӧ����
����\n"NOR
     	);
     	set("valid_startroom",1);
	set("exits",([
     		"south" : __DIR__"dongting",
     	]));
     	set("objects",([
     		"/clone/weapon/dandao" : 1,
     		"/clone/weapon/changjian" : 1,
     		"/clone/weapon/changqiang" : 1,
     	]));
     	setup();
     	replace_program(ROOM);
}
     
