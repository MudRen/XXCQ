//changan city

#include <ansi.h>
#include <room.h>
inherit MATOU;

void create ()
{
        set ("short", "������ͷ");
        set ("long", @LONG
�������������ͷ�ˣ����Ҳ�����ͷ�����񴬶����������ҡ������
Ҫ�ʹ��ͺ�һ�´���(gu chuan)�����鱳����ɽ�����ٳ�������ɫ׳����
������ԭ�������ÿ�����³��壬�������֣������������ϡ��������
�������Ŀ��¶���ȥ�����۵��ˡ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"jiangpan1",
		"west" : __DIR__"jiangpan4",
		"south" : __DIR__"guandao1",
        ]));

        set("outdoors", "zigui");
        setup();
}