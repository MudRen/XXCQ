//shiwu.c		�Ĵ����š�ʯ��

inherit ROOM;

void create()
{
	set("short", "ʯ��");
        set("long",@LONG
����һ���ô����ɵ�С��, һ����, ���ŵ�һ��Ũ�ҵĻ��㣬
���й���һ����Ůͼ, ���������廨����, ������һ����, ������
��һ��ĵ���Ľ�������. �ѵ�����˭�ҹ���Ĺ뷿��
LONG);
        set("exits", ([
                "north" :__DIR__"huayuan",   
           ]));
	set("objects", ([__DIR__"npc/tanglyz" : 1 ]));
        setup();
        replace_program(ROOM);
}