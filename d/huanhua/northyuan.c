//changan city

inherit ROOM;

void create ()
{
        set ("short", "����Ժ");
        set ("long", @LONG
һ̤�뱱��Ժ��һ������֮����Ȼ��������ΪȨ�����ٹ���®��
�����������ӣ�ÿ��佻����ӵ���ͷ���ǳ����ġ���®�������ӥ���
��æ�ò��ɿ���������������Ů������Ҳʧȥ�����յ�Ц����ÿ���˶�
ֻ��һ����ͷ����������®��
LONG);
	set("valid_startroom", 1);

        set("objects", ([
	]));

        set("exits", 
        ([
		"north" : __DIR__"longzu",
		"east" : __DIR__"yingzu",
		"west" : __DIR__"fengzu",
		"south" : __DIR__"northlang",
	]));

        set("outdoors", "xiao");

        setup();

	replace_program(ROOM);
}