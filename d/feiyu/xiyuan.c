//Room:xiyuan.c
//Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
//

inherit ROOM;

void create ()
{
        set ("short", "��Ժ");
        set ("long", @LONG
�����Ƿ���ɽׯ����Ժ������ȥ�Ͷ�Ժ��һ���ģ�·��������һ��խ
·��ԶԶ���Կ���һ�Ƚ��յ�ľ�ţ�·���������һ���䣬ת�򱱷�����
�򱱾����е��ӵ���Ϣ���ˡ���������䳡��Լ�����������ߺ������
LONG);
	set("valid_startroom", 1);
       set("outdoors", "feiyu");
       set("exits", 
        ([
		"north" : __DIR__"wxiaojing",
		"south" : __DIR__"zhailu",
	       "east" :__DIR__"xiwuchang",
         ]));

       setup();
	replace_program(ROOM);
}