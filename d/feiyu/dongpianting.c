// Room: dongpianting.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "��ƫ��");
        set ("long", @LONG
����İ���ʮ�����أ������Ƿ�����������ͷ�ӡ������ĵط�����
�Ϸ�������ͨ��ǰ���Ķ�������������ͨ������ׯ���õġ�������������
�е��ӵĶ���Ժ�ˡ�
LONG);
        set("area"," ����");
        set("valid_startroom", 1);

        set("exits", ([
                "northwest" : __DIR__"neitang",
                "southwest" : __DIR__"qianting",
                "northeast" : __DIR__"dongwuyuan",   
        ]));

        setup();
        replace_program(ROOM);
}
