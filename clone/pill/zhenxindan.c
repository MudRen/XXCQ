// poison_dust.c
//Date: godzilla@cctx /1999/06/01
inherit ITEM;
#include <ansi.h>
void create()
{

        set_name(RED"����������"NOR, ({ "zhenxin dan", "dan" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                        "���ǡ�ɱ����ҽ��ƽһָ���������Ƶĵ�ҩ,���ھ��﷽�Թ�Ч\n" );
                set("value", 5000);
                set("unit", "��");
                set("weight", 30);
        }

}

void init()
{
        add_action("do_pour", "pour");
}

int do_pour(string arg)
{
        string me, what;
        object ob;

        if( !arg
        ||      sscanf(arg, "%s into %s", me, what)!=2
        ||      !id(me) )
                return notify_fail("�����ʽ: pour <ҩ> into <��Ʒ>��\n");

        ob = present(what, this_player());
        if( !ob )
                return notify_fail("������û��" + what + "����������\n");
        if( !ob->query("liquid/remaining") )
        return notify_fail(ob->name() + "��ʲôҲû�У���װЩ�Ʋ����ܻ�"+RED+"����������"+NOR+"��\n");
        if( ob->query("liquid/type")=="water")
        return notify_fail(RED"����������"+NOR+"ֻ�ܷŵ����\n"); 
        message_vision("$N��һ��" + name() + "����" + ob->name() 
                + "ҡ���˼��¡�\n", this_player());
        ob->set("liquid/type","yaojiu");
        destruct(this_object());
        return 1;
}

