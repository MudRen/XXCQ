// Room: /welcome/qianzhuang.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"��ѩǮׯ"NOR);
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ�����ض��зֵꡣ����
�е���Ʊ�����ǳ��ã�ͨ��ȫ����
    �ڶ����ǽ�Ϲ��˿�����(paizi)��
LONG );
	set("exits", ([
		"east" : __DIR__"beilang2",
	]));
	set("item_desc", ([
		"paizi" : @TEXT
     ��Ǯׯ�ṩ���·���
      ��Ǯ        deposit����cun
      ȡǮ        withdraw����qu
      Ǯ�Ҷһ�    convert����duihuan
      ����        check����chazhang
TEXT
	]) );

	set("objects", ([
		__DIR__"npc/qian" : 1
	]));
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("no_beg", 1);
	setup();
	replace_program(ROOM);
}
