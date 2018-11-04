// xiongzhang.c ����

inherit ITEM;

void create()
{
        set_name("��ϯ", ({"table"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "��������(xiongzhang)    ��    ��(baoyu)      ��    ��(yanwo)\n"+
                            "��    ��(yuchi)         ��    ��(haishen)    �� �� ��(tang)\n"+
                            "Ů�����(nverhong)      ���껨��(huadiao)    ��������(zhouzi)\n"+
                            "�� �� ��(gao)           �� �� ��(ruzhu)      ��    ��(hounao)\n");
                set("unit", "��");
                set("value", 500);
                set("no_get", "���ڸ��磬����������ɡ�\n");    
                set("fd_count", 300);
                set("wt_count", 150);
        }
}

void init()
{
        add_action("do_jia", "jia");
        add_action("do_drink", "drink");
        add_action("do_sit", "sit");
}

int do_sit(string arg)
{       object me;
        me = this_player();
         if( !arg || arg=="" ) {
                return notify_fail("��Ҫ�������ָ���ʽ��sid chair\n");
                }
        if (me->query_temp("marks/��"))return notify_fail("���Ѿ������ˡ�\n");
         if( arg=="chair"
		&&( (me->query_temp("marks/����"))
		|| (me->query_temp("marks/����")) )){
                message_vision("$N���˸��Ƚ��������λ����������\n", this_player());
                me->set_temp("marks/��",1);
                return 1;}
                 else{
                 message_vision("$N���Ҹ���λ�������Զ�����ȴ�����Լ�û�б����븰�����ᣬ��ʱ�ߵ�����ͨ�졣\n", this_player());return 1;
                }
}

int do_jia(string arg)
{       object me;
        me = this_player();
        
        if (me->query_temp("marks/��")){
         if( !arg || arg=="" ) 
                message_vision("$N����������ҿ������Ÿ�Юʲô�Բźá�\n", this_player());
         if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
                return notify_fail("���Ѿ��ȵ�̫���ˡ�\n");
         if(query("fd_count") < 1){
         message_vision("$N�������ӵ�������Ю�����ԣ�ȴ����������Ĳ��Ѿ����Թ��ˡ�\n", this_player());return 1;}
         if( arg=="xiongzhang")
                message_vision("$NЮ���������������ζ�ؽ��˼��ڣ������޵������㣡���㣡\n", this_player());
         if( arg=="baoyu")
                message_vision("$NЮ��һ�鱫��������ζ�ؽ��˼��ڡ�\n", this_player());
         if( arg=="yanwo")
                message_vision("$NЮ��һ������������ζ�ؽ��˼��ڡ�\n", this_player());
         if( arg=="yuchi")
                message_vision("$NЮ��һ�����������ζ�ؽ��˼��ڣ��Ұ��˼����죬˵�����ţ���������\n", this_player());
         if( arg=="haishen")
                message_vision("$NЮ��һƬ����������ζ�ؽ��˼��ڡ�\n", this_player());
         if( arg=="zhouzi")
                message_vision("$Nץ��������������ζ�ؿ��˼��ڣ��޵������������壬��������\n", this_player());
         if( arg=="gao")
                message_vision("$NЮ��һ�������������ζ�س��˼��ڡ�\n", this_player());
         if( arg=="ruzhu")
                message_vision("$N˺��һ��鿾�������˼��ڣ�Ū�����춼���͡�\n", this_player()); 
         if( arg=="hounao")
                message_vision("$N��������С������Ҩ��һ�׺��Գ��˳�������˵������ζ����\n", this_player());
         me->add("food", 5);
         add("fd_count", -1);
         return 1;}
                 else return notify_fail("�㻹û��������\n");
}

int do_drink(string arg)
{       object me;
        me = this_player();
        
        if (me->query_temp("marks/��")){
         if( !arg || arg=="" ) 
                message_vision("$N���ҿ������Ÿúȵ�ʲô�źá�\n", this_player());
         if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
                return notify_fail("���Ѿ��ȵ�̫���ˡ�\n");
         if(query("wt_count") < 1){
         message_vision("$N����ƺ�׼�����Լ��屭�ƣ����ֺ���ľ��Ѿ����Թ��ˡ�\n", this_player());
                return 1;}
         if( arg=="tang")
                message_vision("$N��������Ҩ��һ�����������˼��ڡ�\n", this_player());
         if( arg=="yuchi")
                message_vision("$N��������Ҩ��һ�������������ζ�غ��˼��ڣ��Ұ��˼����죬˵�����ţ���������\n", this_player());
         if( arg=="nverhong")
                message_vision("$N����Ʊ�����˵�����������������Һȸ����ˣ�������Ϊ����˵��һ�����Ӱѱ��е�Ů����ƹ��������ȥ��\n", this_player());
         if( arg=="huadiao")
                message_vision("$N����Ʊ�����˵�����������������Һȸ����ˣ�������Ϊ����˵��һ�����Ӱѱ��еĳ��껨��ƹ�ཾ�������ȥ��\n", this_player());
         this_player()->add("water",10);
         add("wt_count", -1);
         return 1;}
                else return notify_fail("�㻹û��������\n");

}
