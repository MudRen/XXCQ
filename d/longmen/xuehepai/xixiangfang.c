// xixiangfang��c ���᷿
// mlf��ƣ�lks���

inherit ROOM;
#include <room.h>

void create()
{
	set("short","���᷿");
        set("long",@LONG
������Ѫ���ɵ����ᣬ�����ڼ������ӣ�һ�ź�ľ���磬���������
���������ڵ���ƽʱ�ڱ����������ʯ��ݣ��Լ��������Ĺ���Ʒ������
������������Ѫ�������ں�����������������Ϊ�������ģ�ʩչ�Ż���
����������Եø���ɾ���������ԡ�
LONG);
               set("valid_startroom",1);
        set("exits",([
                "east" : __DIR__"zoulang1",
                "north" : __DIR__"zoulang3",
     	]));
     	setup();
     	replace_program(ROOM);
}
