// Room: С��
// Date: by godzilla 1999.11.18

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һ�����������ö���ʯ�̳ɵ�С����·��������������һ����ɽ
ʯ��ľ��׺�����С�������ʯ���ϣ�ž�žવķ�������������С
�������������졣
LONG );
        set("outdoors", "tianyu");
	set("exits", ([
	        "southeast" : __DIR__"xiaojing", 
		"north"  : __DIR__"neitang",
                "south"  : __DIR__"tianxinb1",
                "west"  : __DIR__"xiaojing10",
	]));
	setup();
	replace_program(ROOM);
}
