#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","������");
        set("long",@LONG
Ѫ�����Կ������������������������˸������Ŷ������ڴˣ�
�Ӵˣ��������ӽ����ﵱ��Ѫ��ʥ�أ������������鱣�ӣ������в�
�ٵ���ǰ���˴�����������ѧ���������°빦����Ч����Ȼ�似һ;
ֻ��ͨ����ѧ�������������ɡ�
LONG);
        set("valid_startroom",1);
        set("exits",([
                "west" : __DIR__"zoulang5",
        ]));
        setup();
        replace_program(ROOM);
}