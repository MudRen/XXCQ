//changan city

#include <ansi.h>
#include <room.h>
inherit MATOU;

void create ()
{
        set ("short", "佻���ͷ");
        set ("long", @LONG
�������佻���ͷ�ˣ���ϪС·Ҳ����Ϊֹ�ˣ��߼�̨��һֱ���쵽
ˮ�У�һ�����񴬿�����ͷ�ߣ����������ң��������ڴ�����ץ��ʱ��Ъ
Ϣ�������Ҫ���ͺ��������Ұ�(gu chuan)��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"hhxroad2",
        ]));
        set("objects", ([
                 "/d/huanhua/npc/yiren.c": 1,
        ]));

        set("outdoors", "xiao");
        setup();
}
