// zhuangmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",GRN"ׯ��"NOR);
        set("long",
"��ת��һ��ï�ܵĻ���, ��Ȼ��, ֻ��һ����������, С�������ׯԺ��\n"
"���ڲ����Ļ����С�ׯ�Ŵ����Ϻ�Ȼд�š�"BLINK HIY"����ɽׯ"NOR"���ĸ���������Ĵ��֡�\n"
);
       set("outdoors","����Ľ��");
       set("exits",([
        "west" : __DIR__"ab",
	"south" : __DIR__"qianyuan",
	"north" : __DIR__"hc",
]));
        setup();                                                   
        replace_program(ROOM);
}
