// Item yaocai.c
// Created by Zeus 1999.3.28
// Modified by M.A.D. 1999.7.19
// 
// 

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("ҩ��", ({"yao", "yaocai"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ƵĿ������˵�ҩ��\n");
                set("value", 5000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
                if ((int)this_player()->query("eff_jingli") == 
                    (int)this_player()->query("max_jingli"))
                return notify_fail("�����ںܽ���������Ҫ��ҩ�ġ�\n");
        else {
                this_player()->receive_curing("jingli", 100);
                message_vision("$N����һ��ҩ�ģ����������ö��ˡ�\n", this_player());
                destruct(this_object());
                return 1;
        }
}
