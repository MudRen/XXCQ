// Room: /d/shaolin/fanting1.c
// Date: YZC 96/01/19

inherit ROOM;
int do_serve(string arg);

string* names = ({
	__DIR__"obj/mizhi-tianou",
	__DIR__"obj/jiaxin-biji",
	__DIR__"obj/basi-shanyao",
	__DIR__"obj/furong-huagu",
});

void create()
{
	set("short", "ի��");
	set("long", @LONG
�����������ȫ����ɮ��ի�ĵط���ի���������������ǧ��ͬʱ
���š��Ӷ�����һ���Ű����˳����Ĳ����ͳ��ʣ���λС����������æµ
�Ų�����ի�����ϰ��˼��趹��������������Լ���Ѽ����ζ��ʳ������
�Ǹ�������
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"fanting",
		"north" : __DIR__"chufang",
	]));
	set("objects",([
        	__DIR__"obj/qinghulu" : 1,
		names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,		
	]));
	setup();
}

void init()
{
        add_action("do_serve", "yell");
}

int do_serve(string arg)
{
 object obj;

 if(!arg || arg !="������")
    return notify_fail("����ʲô,��!\n");
 obj = new(names[random(sizeof(names))]);

 if (!present("huagu tang",environment(this_player())))
   {
    obj->move(__DIR__"fanting1");
    return notify_fail("�и�ɮ�˴����������,˵��:Ӵ,�Ե�û��!�ȵȰ�!\n");
   }
    else return notify_fail("�Ѿ�������yellҲû����!\n");
}
