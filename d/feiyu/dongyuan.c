//Room:dongyuan.c
//Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
//

inherit ROOM;

void create ()
{
        set ("short", "��Ժ");
        set ("long", @LONG
�����Ƿ���ɽׯ�Ķ�Ժ��һ����ʯС·���ڽ��£�·��������һ��Բ
�εĹ��ţ��ӹ��ſ��Կ����ܹܷ���·���������һ��С�䣬ת�򱱷���
����,�߹�С��������Ů���ӵ���Ϣ���ˡ�������Լ�����������ߺ��
����
LONG);
	set("valid_startroom", 1);
       set("outdoors", "feiyu");
       set("exits", 
        ([
		"north" : __DIR__"xiaojing",
		"south" : __DIR__"zongguanfang",
	       "west" :__DIR__"eroad",
         ]));

       setup();
	replace_program(ROOM);
}