//youmingge��c  by baby

#include <room.h>
#include <skill.h>

inherit ROOM;

void create()
{	
	set("short", "��ڤ��");
	set("long", @LONG
������Ѫ�����ܹ��������ס�������������ײУ����ʴ�ӱ���Դ�����
а�ɵľ�ѧ��������˰�ʦѧ��֮��Ҳ�������ˡ���¥�Ľṹ����ϸ�ܣ���
�������������֮�֣����˲���Ϊһ�����ۡ������������Ҳ��ٵ�������
�������������غͻ��ߵģ�����һ����ڤѪ���������ǽ�ϡ�
LONG);	
	set("valid_startroom",1);
	set("objects",([
		"/kungfu/class/xuehepai/xiao" : 1,
	]));
	set("exits",([
		"east" : __DIR__"xueyu",
		"south" : __DIR__"zoulang3",
	]));

        set("area", "����");
        setup();
            replace_program(ROOM);
}
