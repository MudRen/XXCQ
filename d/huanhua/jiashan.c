//changan city

inherit ROOM;

void create ()
{
        set ("short", "��ɽ");
        set ("long", @LONG
�����������Ⱥ;����Ƚ���ĵط��������������һ��һ�˶�ߵļ�
ɽ����ɽ�ϳ�������ɫ����ɽ����·���ɽʯ�����죬һֱͨ��佻���®
�صء������춴��
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"jiantian",
		"north" : __DIR__"qqlang_3",
		"south" : __DIR__"jqlang_3",
	]));

        set("outdoors", "xiao");
        setup();
}