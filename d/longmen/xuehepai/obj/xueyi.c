
#include <ansi.h>

inherit F_AUTOLOAD;
inherit F_UNIQUE;
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIR"Ѫ��"NOR, ({ "xueyi","yi" }) );
        set("long",@LONG
��������������Գ����ı��
LONG );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                  set("armor_prop/armor", 20);
                  set("value",100000);
                  set("armor_prop/dodge", 20);
        }
        setup();
}


/*
void init()
{
        add_action( "do_fly", "fly" );
}

int query_autoload(object me)
{
        if (wizardp(me=this_player())) return 1;
        else return 0;
}

int do_fly(string arg)
{
        string home;
        object mme;
        object obj;
        string msg;
        mme=this_player();
        if (mme->is_fighting())
          return notify_fail("�㻹��ר��ս���ɣ�\n");
        if( !arg ) return notify_fail("��Ҫȥ���\n");
        obj = find_player(arg);
        if(!obj) return notify_fail("û��������ѽ��\n");
         if (mme->query("max_qi")<=200)
         mme->add("qi",-1*(mme->query("max_qi")-1));
         else  mme->add("qi",-200);
         this_player()->add("qi",-200);
         this_player()->add("jingli",-50);
        tell_object(mme,HIM"�㴩��Ѫ��,���ھ�����ȫ��\n"NOR);
        tell_object(mme,HIM"ֻ��Ѫ���ǵ������ģ�����һ�ѻ���ɡ!�������Ṧ����"+obj->query("name")+"��ȥ��\n"NOR);
        mme->move(environment(obj));
        tell_object(mme,HIM"�㻺���½�,��һ��ء�Ȼ������Ѫ��\n"NOR);
        return 1;
}
*/
