// Room: ����
// Date: by godzilla 1999.11.18


inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����С���������ó���ֻ���������õƻ�Իͣ������ǽ�Ϲ���
һ���̽�ͼ���������������Ļ��ż���С�����������ƣ����а���һ
��̫ʦ��һ���������������档���԰��������ţ�����ǽ�Ϲ�����
��������Э����
LONG );
	set("exits", ([
	        "south" : __DIR__"xiaojing1", 
            "west" : __DIR__"qingxinge", 
		"east" :__DIR__"lgsw",
	]));
	set("objects",([
	        __DIR__"npc/songzixue" : 1,
	        ]));
	setup();
	replace_program(ROOM);
}
