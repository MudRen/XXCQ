// Room: xipianting.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "��ƫ��");
        set ("long", @LONG
����İ���Ͷ�ƫ��һģһ����Ҳ�Ƿ�����������ͷ�ӡ������ĵ�
�������Ϸ�������ͨ��ǰ���ģ�������������Ҳ��ͨ������ׯ���õġ���
����������Ů���ӵ�����Ժ�ˡ�
LONG);
        set("area"," ����");
        set("valid_startroom", 1);

        set("exits", ([
                "northeast" : __DIR__"neitang",
                "southeast" : __DIR__"qianting",
                "northwest" : __DIR__"xiwuyuan",   
        ]));

        setup();
        replace_program(ROOM);
}
