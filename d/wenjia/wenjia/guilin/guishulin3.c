// Room: guishulin.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
ï�ܵĹ����֣�������ֲ��һƬï�ܵĹ����֣������ﱻ��Ϊ���ֵ�
ԭ�������Ϊ������Χ�зǳ���Ĺ����֡����ϱ���ȥ��佻���·������
�ϱߵ�·��ȥ���ɽ�ġ�
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "southeast" : __DIR__"xiangbi",
                "southwest" : __DIR__"working",
                "northeast" : __DIR__"zhongxin",
        ]));
        setup();
        replace_program(ROOM);
}

