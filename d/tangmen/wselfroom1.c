//wselfroom1.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "����");
	set("long", @LONG
����һ����ů�����ҡ�����������XXXX��ס�ĵط��������������
ǽ�ڷ�ˢ��ѩ�ף����߰ڷ���һ�ſ���������ͷ��һ�ű����õ�һ
����Ⱦ�ĺ�ľ�������ſڴ���վ����һ���̴ӣ���ʱ׼���������˵ķ�
����
LONG);	
	set("valid_startroom",1);
	set("no_steal", "1");
	set("no_fight", "1");
	set("sleep_room",1);
	set("exits", ([	"south" : __DIR__"wzlang1",]));
	setup();
	replace_program(ROOM);
}