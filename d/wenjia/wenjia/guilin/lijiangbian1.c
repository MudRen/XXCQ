// Room: lijiangbian1.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "�콭��");
        set ("long", @LONG
�콭��ˮ���Աߵ������·ɱ��������ﶫ�ϱ���һ�������ţ��߹���
���ſ��Ե�����֡�������������������Ĵ�����ĵط�����������һ��
���������ͨ���Ĵ���
LONG);
        set("area","����");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "west" : __DIR__"yidao1",
                "southeast" : __DIR__"tiesuo",
        ]));
        setup();
        replace_program(ROOM);
}

