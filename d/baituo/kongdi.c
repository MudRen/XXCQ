#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
����һƬ����ǰ�Ŀյأ��Ա߷���Щ�����ܡ�ɳ���Լ�����ľ׮����
��������Ʈ�����Ҷ�͸ɲݡ��Ա���һ��ˮ����һ��ˮư����ˮ�峺��ɢ
�������������������Ǽ���䴢���ҡ�
LONG);
        set("resource/water", 1);
        set("exits", ([
              "southdown" : __DIR__"shanmen",
              "west" : __DIR__"chucang",
              "northup" : __DIR__"tangwu",
        ]));
        set("outdoors", "����ɽ");
        setup(); 
}

void init()
{
        add_action("do_drink", "drink");
        add_action("do_drink", "he");
}
int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"��ˮưҨ��һ�ھ�ˮ�ȡ�\n"
            , environment(me), ({me}) );
            me->improve_skill("force", me->query("int"));
            write("�����һ������ľ�ˮ���������ȵĴ�Į��Ҳ�е�һ˿���⡣\n");
        }
        else write("���Ѿ��Ȳ����ˡ�\n");

        return 1;
}