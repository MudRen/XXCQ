// Room: ����
// Date: by godzilla 1999.11.18


inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ּ򵥣�ֻ�м��ż�ª�����Σ�ǽ��ȴ�������ֻ�������
�����Ǹ�ϲ���黭֮�ˡ����е���̴ľ�Ĳ輸�ϰڷ��Ų���������
��ð��������
LONG );
	set("exits", ([
	        "south" : __DIR__"qianyuan", 
		"west" : __DIR__"qixuant",
		"east" :__DIR__"xiuxishi",
        "north" :__DIR__"zhangfang",
	]));
	set("objects",([
                 __DIR__"npc/zhuyou" : 1,
	        ]));
	setup();
	replace_program(ROOM);
}
