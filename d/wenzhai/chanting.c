//chanting.c
inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
����һ�����µĴ��������ϰ��ż�����̴ľ�������������Ʋ;�һӦ
��ȫ������һ���绨ľ�Ρ���ʦ����չʾ���Ե���⿾��������������
�����˴������εĲ��㡣
LONG );
        set("exits",([
            "west" : __DIR__"caodi",
        ]));
        set("objects",([
             __DIR__"npc/nanpu" : 1,
        ]));
	set("valid_startroom",1);
        setup();
        replace_program(ROOM);
}
