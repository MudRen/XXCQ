// gate��c  ����
// mlf��ƣ�lks���

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short","Ѫ���ɴ���");
	set("long",@LONG
������Ѫ���ɵĴ��ţ������Ϸ������ĽǷ��ܣ����������ĸ�����ʯ
������������ͼ�ڵװ�����������������һ����ң����С�Ѫ�����¡���
��Ѫ����֣������پ���Ϊ��ɽ��ʦʢ�������顣���ص��������϶�����
������һ���ǡ��󽭶�����������������ͩһҹ���䡱��һ���ǡ�������
ȥ�����ǽ�Я�齭�����Ρ�����������������׳־����Ȼ������
LONG);
	set("valid_startroom",1);
	set("outdoors","����");
	set("exits",([
        	"north" : __DIR__"xuehuatang",
        	"south" : "/d/longmen/shanlu5",
	]));
	setup();
              replace_program(ROOM);
}
