// Room: �ʷ�
// Date: by godzilla 1999.11.18


inherit ROOM;

void create()
{
        set("short", "�ʷ�");
        set("long", @LONG
�����������ŵ��ʷ���ÿ��������Ӷ�������������ȡ���ͣ�
���Ӱ���򵥣�ֻ��һ�����ӣ������Ϸ���һ�����̣�һ��������
��ͣ�Ĵ������̡�
LONG );
        set("exits", ([
               "south" : __DIR__"dating", 
        ]));
        set("objects",([
                __DIR__"npc/guanshi" : 1,
                ]));
        setup();
        replace_program(ROOM);
}

