// Item xingshencha.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.3.27
// 
// 

inherit ITEM;

void init();
void do_eat();

void create()
{
        set_name("�����",({"tea", "cha", "xingshen cha"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ������裬���Ƶ�ð����������˵����������¼ҵ���Чҩ���������������塣\n");
                set("unit", "��");
                set("value", 1000);
                set("remaining", 5);
                set("drink_supply", 20);
        }
	
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{

        int recover, qi, e_qi, m_qi;
	
        recover = 20;
	
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");
        if( (int)this_player()->query("water")
                >= (int)this_player()->max_water_capacity() )
                return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0);
        this_player()->add("water", (int)query("drink_supply"));
        qi = (int)this_player()->query("qi");
        e_qi = (int)this_player()->query("eff_qi");
        m_qi = (int)this_player()->query("max_qi");

// No heal effect for �����
/***

       if ( e_qi < m_qi )
       { 	
                if ( (e_qi + heal) >= m_qi )
                {
                        this_player()->set("eff_qi", m_qi);
                } else {	
                        this_player()->set("eff_qi", e_qi+heal);
                }	
       } 
***/

        if (qi < e_qi )
        {
        if ( (qi + recover) >= e_qi )
        {
                this_player()->set("qi", e_qi);
        } else
        {   
               this_player()->set("qi", qi+recover);
        }   
	}

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        add("remaining", -1);
        if ( query("remaining") )
        {
                message_vision("$N��������裬������ζ��Ʒ�˼��ڡ�\n"+
      		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
        } else 
        { 
                message_vision("$N�����С������ʣ�µ������һ��������\n"+
                "һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
		
                destruct(this_object());
        }

        return 1;
}
