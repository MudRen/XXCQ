//qixuetang��c           Ѫ����--��Ѫ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��Ѫ��");
	set("long", @LONG
��������Ѫ�ã�����Ѫ���ɵ������صء�Ϊ��ֹ�����Ϯ��Ҫ���˵�
�ؿ����ء�������һ��ׯ�أ��ֺܵ��ŵĽ����������ú�ᣰ������Եü�
Ϊɭ�ϣ���������ʮ����������ÿ������������ʮ�������������ķ����
����������һЩ�������ޡ������ϵ��������緢�ġ�Ѫ�����¡��ĸ�����
��ʹ�˲��Ͷ�Ѫ������Ȼ�𾴣��˴�ΪѪ���ɵ���ÿ��ѡ���ἰ���ڴ�
С�����������ڵء���ˣ�������ʱ������䣬�ɼ��ɷ��Ͻ���
LONG);
	set("exits", ([	
        	"eastdown" : __DIR__"zoulang5",
        	"north" : __DIR__"xueku",
        	"northwest" : __DIR__"yanwuchang",
        	"south" : __DIR__"xuehuatang",
	]));
	setup();
          "/clone/board/xuehe_b"->foo();
	replace_program(ROOM);
}
