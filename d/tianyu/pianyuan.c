// Room: ƫԺ
// Date: by godzilla 1999.11.18

inherit ROOM;

void create()
{
	set("short", "ƫԺ");
	set("long", @LONG
���ǿ����ߵ�һ��СԺ�֡���Χ��Χǽ���������٣�ǽ�ߵĻ�̳
�Ӳݴ���������ʢ����Ұ����Ҳ���£�ʱ��ʱ������������������
��һƬ�������ϱ���һ��񷿡�
LONG );
        set("outdoors", "tianyu");
	set("exits", ([
	        "east" : __DIR__"qianyuan", 
		"south"  : __DIR__"chaifang",
        "north"  : __DIR__"jijian",

		]));
	setup();
	replace_program(ROOM);
}
