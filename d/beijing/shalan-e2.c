//changan city

inherit ROOM;

void create ()
{
        set ("short", "��դ������");
        set ("long", @LONG
���Ǵ�դ�����ֵľ�ͷ�������Ѿ�û��·�ˣ�����ʹ�Ƚ�ƫƧ����������˵�
�����Ϊ�����·���Ǿ���Ψһ��һ��ҩ�̣�������ʲô��������Ҫ��������ץ
ҩ��·������һ��С�ƹݣ�������һ������Ǿ������������������Ǽ�������
Щ��ٹ��˺�����ӵܵ���Ӱ�ġ�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"shalan-e1",
		"north" : __DIR__"yaopu",
		"south" : __DIR__"yideju",
        ]));

        set("outdoors", "beijing");
        setup();
	replace_program(ROOM);
}