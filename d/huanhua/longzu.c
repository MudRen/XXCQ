// Room: /city/chouduanhang.c
// YZC 1998/12/04 

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ����Ĵ��ã����ڲ��õ���Ϊ���£����������á����Ҷ���
�������⣬�󲿷ֵ�װ�ξ��Ժڰ�Ϊ������������վ�����е��ӣ�����һ
����¶̴��Եú��Ǹ�����һ�����ڲ�ͬ�ĺ���������վ���õ����룬
��ͣ��������ȥ�������������Ա����Ϣ�ҡ�
LONG
        );

        set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"northyuan",
        ]));

        set("objects", ([
                "/kungfu/class/huanhua/zhang" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

