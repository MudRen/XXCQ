// Room: yishiting.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.3.26
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "������");
        set ("long", @LONG
�������һȦ���ӣ�����Ȼ�����������������µ������İ�
���Ϸ������Ϸ����������Ǻ���Ȼ�Ǵ�ǰ�������������ƫ����
LONG);
        set("area","����");
	set("valid_startroom", 1);
        set("objects", ([
                "/kungfu/class/wenjia/wenxinlaoxie" : 1,
                "/kungfu/class/wenjia/wennuansan" : 1,
                "/kungfu/class/wenjia/wenyuehong" : 1,
                "/kungfu/class/wenjia/wenliangyu" : 1,
                "/kungfu/class/wenjia/wensijuan" : 1,
                "/kungfu/class/wenjia/wenlazi" : 1,
                "/kungfu/class/wenjia/wendi" : 1,
                "/kungfu/class/wenjia/wenshagong" : 1,
        ]));

        set("exits", ([
                "southwest" : __DIR__"xipianting",
                "southeast" : __DIR__"dongpianting",
        ]));
        setup();
        replace_program(ROOM);
}
