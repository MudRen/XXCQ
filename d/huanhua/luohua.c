//changan city

inherit ROOM;

void create ()
{
        set ("short", "�仨��Ժ");
        set ("long", @LONG
�仨��Ժ������Ϊ�佨���仨���ϣ�����ΪԺ�ڵ�ÿ��������Ժ��
������ü��ͽ���Ժ�У������������ż����˵�������������ס������
�����ص��ˣ��������������ţ����ŷ��˸���ÿ�������ٴ˰��ء�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"qqlang_2",
		"north" : __DIR__"zhenmei",
	]));

        set("objects", ([
		"/kungfu/class/huanhua/huishan" : 1,
	]));

        set("outdoors", "xiao");
        setup();
	replace_program(ROOM);
}