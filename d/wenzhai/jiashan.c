// jiashan.c

inherit ROOM;
void create()
{
	set("short","��ɽС��");
	set("long",@LONG
������һ��С԰�ӣ���ͷ�и�С���������ܲ��м�ɽ��������԰����
��������ʱ��ˮ����Ϫ���У�����ˮ���������������̰��ö���ˮ����
����̧ͷ������ֻ��Զ����ɽ���죬�������֣��꾰��Ȥ���
LONG);
	set("exits",([
		"north" : __DIR__"huayuan",
		"south" : __DIR__"zoulang1",
	]));
	set("outdoors", "wenzhai");
        set("valid_startroom",1);
        setup();
	replace_program(ROOM);
}
 
