// by mulan

inherit ROOM;

void create ()
{
        set ("short", "�ƺ�С����ǰ");
        set ("long", @LONG
�ƺ�С����ǰ��Ҳ��һ���ڵ���ͷ������������ɨ�ŵأ���С�ĺ�С��
����ɨ�ŵأ�����ɨ����һ����ΰ���רע�Ĺ���һ�㣬���¼�˭Ҳ��
�ܾ�����ȥ�������.
LONG);

        set("exits", 
        ([
                "north" : __DIR__"huanghe",
         "south" : __DIR__"qqlang_1",
        ]));
        set("objects", ([
                "/d/huanhua/npc/guang" : 1,
       ]));

        setup();
}
