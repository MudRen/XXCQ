// Room: xipianting.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.3.26
// 
// 


inherit ROOM;
void create ()
{
        set ("short", "��ƫ��");
        set ("long", @LONG
����İ�����ǰ���Ĳ�ֻ࣬����Ʒ�ĵ�����Ȼ�Ͷ���
û��ǰ���е���ɱ���ա����ǽӴ��μ����͵ĵط������Ϸ���
����ͨ��ǰ���Ķ�������������Ȼ��ͨ���������ġ�
LONG);
        set("area","����");
        set("exits", ([
                "northeast" : __DIR__"yishiting",
                "southeast" : __DIR__"qianting",
        ]));
        setup();
        replace_program(ROOM);
}
