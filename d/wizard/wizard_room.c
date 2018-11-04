// Room: /d/wizard/wizard_room.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIW "��ʦ����" NOR);
	set("long", @LONG
������Сѩ�������ʦ����칫������ʮ�ֿ�������ʯ�ĵ�������
���£���׵�ǽ�棬һյ�����Ĵ���ƽ������յ�ʮ����������ʦ������
�ｻ�������ۡ�
    �����ǻ����ҡ�
    ��������ʦ�������ȱ����ҡ�
    ������һ��ͨ����ص�ͨ����
    �ϱ���Сѩ��������ŷ������ġ�
�Ӹߴ����ش�����ȥ��ֻ��������һƬ��ɫ�Ĳݵأ�Զ���Ǳ̲�������
��ˮ��
LONG );

	set("exits", ([
  	"north" : __DIR__"huiyishi",
	"east"  : __DIR__"lpcroom",
	"south" : __DIR__"newsroom",
	"west"  : __DIR__"exitroom",	
 ]));

	set("valid_startroom", 1);
	set("no_clean_up", 0); 
	set("objects",([
                "/clone/food/jitui":1,
	]));
        set("sleep_room", 1);
        set("no_fight", 1);
	setup();
	call_other("/clone/board/wiz_b", "???");
}

