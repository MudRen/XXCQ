// Room: ����ͼ
// Write by phoenix 1999.12.25

#include <ansi.h>
inherit ROOM;
string* dirs = ({
        "��", "��", "��", "Ǭ",
        "��", "��", "��", "��"
        });
void create()
{
        set("short",HIR"����ͼ"NOR);
        set("long", @LONG
��һ̤������ֻ�������ܱ�����ذ�������������˵Ķѷ���
���־�ʯ��ϸ��һ������ÿ��ʯͷ�ڷ�λ��ǡ���ô������ϰ���ԭ��
���ഫ������ʱ����������������󷨣�������ۣ������������
�����¡�
LONG
);
        set("outdoors","tianyu");
        set("exits", ([
                "��" : __DIR__"baguaz0",
                "��" : __DIR__"baguaz0",
                "��" : __DIR__"baguaz0",
                "Ǭ" : __DIR__"baguaz0",
                "��" : __FILE__,
                "��" : __FILE__,
                "��" : __FILE__,
                "��" : __FILE__,
        ]));
        setup();
}
void init()
{
        object ob = this_player();
        int step, temp, count;
        if ( !ob->query_temp("bagua_start"))
        {
                ob->set_temp("bagua_start", 1);
                ob->set_temp("bagua_step", 1);
                ob->set_temp("bagua_temp", 0);
                ob->set_temp("bagua_count", 1);
        }
        temp  = ob->query_temp("bagua_temp");
        count = ob->query_temp("bagua_count");
        temp  = temp * 2+1;
        if (count < 3)
        {
                count++;
        }
        else
        {
                count = 1;
                step = ob->query_temp("bagua_step");
                if (temp == ob->query_temp("bagua_" + step))
                 {
                        if (step == 8)
                         {
                                ob->delete_temp("bagua_start");
                                ob->delete_temp("bagua_step");
                                ob->delete_temp("bagua_temp");
                                ob->delete_temp("bagua_count");
                                write(HIC"�㷴̤����λ���ˡ�Ǭ��λ��ͻȻ��ǰһ����"+HIR+dirs[random(sizeof(dirs))]+HIC+"λ���ֳ���λ�����æ̤�˹�ȥ��\n"NOR);
                                ob->move(__DIR__"treeup", 1);
                                ob->set_temp("bagua_over",1);
                                tell_room(environment(ob), "ͻȻ��ʯ�����ֳ�һ��ȱ�ڣ�" + ob->name() + "�Ͻ����������\n");
                                return;
                        }
                        tell_object(ob,HIY"�㷢�ָղ��߹���·�����ϰ��ԣ�������������\n"NOR);
                        ob->add_temp("bagua_step", 1);
                }
                else {
                        ob->delete_temp("bagua_start");
                        ob->delete_temp("bagua_step");
                        ob->delete_temp("bagua_temp");
                        ob->delete_temp("bagua_count");
                        write(CYN"�㷢���Լ��ȴ��˷�λ������ʯ����ӱ��ĩ���ˣ�ֻ�øϿ�������ʼ�㣡\n");
                        ob->move(__DIR__"qianyuan");
                        tell_room(environment(ob), RED"ֻ��"+ob->name()+"�������Ĵ�ʯ�������˳�����\n"NOR);
                        return;
                }
                temp = 0;
        }
        ob->set_temp("bagua_temp", temp);
        ob->set_temp("bagua_count", count);
}

