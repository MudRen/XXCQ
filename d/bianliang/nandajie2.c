//changan city

inherit ROOM;

void create ()
{
        set ("short", "�ϴ��");
        set ("long", @LONG
�ߵ�������ŵ���һ��Ũ�ҵ���ҩζ��ԭ�����������Ǿ���Ψһ
��ҩ�̡����ش��ã�����������һ���ӻ��̣������������壬�ƺ����ⲻ
�Ǻܺá����洫��������˻���ƺ��м���վ����������Ǿ��ǹ㳡�ˡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
        "west" : "/d/yaowang/huichun",
		"east" : __DIR__"zahuopu",
		"north" : __DIR__"guangchang",
		"south" : __DIR__"nandajie1",
        ]));

	set("area", "����");

        set("outdoors", "bianliang");
        setup();
}
