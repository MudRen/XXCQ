// Room: jiangdi.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "����");
        set ("long", @LONG
һ�������ĵ̰����Աߵ��콭��ˮ���������ţ���Χ��ֲ�ź�Щ������
�羰������ѽ�����̲�ס��̾�����ܲ����������ﲻ��ѽ�����ϱ�һ����
ȥ��һƬ�����֣������ϱ��ڽ�����һ���ţ����������š���������ȥ��
���ĵıؾ�֮·��
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northeast" : __DIR__"lingqu",
                "southeast" : __DIR__"guishulin1",
                "southwest" : __DIR__"jiangdi1",
        ]));
        setup();
        replace_program(ROOM);
}

