//zhuang��c  by god

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "����");
	set("long", @LONG
�˴�ΪȨ����Ĵ�������ṹ���һ��,��ͨ�˴ 
����ͨ�����ȣ�����������µ�һ���á�
LONG);	
	set("valid_startroom",1);
	set("objects",([
	]));
	set("exits", ([
		"north" : __DIR__"dati",
		"west" :  __DIR__"zoulang1",
		"south" :  __DIR__"qilingtang",
		"east" :  __DIR__"zoulang2",
	]));
        set("objects",([
          __DIR__"npc/tu" : 1,
          __DIR__"npc/xing" : 1,
          __DIR__"npc/xue" : 1,
      ]));
        set("area", "����");
        setup();
            replace_program(ROOM);
}
