// Room: ������
// Date: by godzilla 1999.11.18

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
ֻ���������õƻ�Իͣ������ǽ�Ϲ���һ���̽�ͼ��ǽ�����
���������������˵ļ�λ�����������������ơ������м����һ̳��
����������(jijian)֮�á�
LONG );
        set("exits", ([
                "south" : __DIR__"pianyuan", 
                ]));
        setup();

}
void init()
{
       add_action("do_jijian","jijian");
       add_action("do_fang","fang");
}
int do_jijian()
{
        object me=this_player();
        if(me->query_temp("ji_jian"))
        return notify_fail("�����ڼ�����\n");
        if(!me->query_temp("jijian"))
        return notify_fail("����Ҫ�ѳ��������̳(fang)!\n");
        if(me->query_temp("overjijian"))
        return notify_fail("�������Ѿ������ˡ�\n");
        message_vision(CYN"$N˫ϥ��أ����ֺ�ʮ�����������λ�����ļ�����\n",me);
        me->set_temp("ji_jian",1);
        call_out("jijian_1",3,me);
//      remove_call_out("jijian_1");
        return 1;
}       
int do_fang()
{
        object me=this_player();
        object ob=present("long sword",me);
        if(!present("long sword", me))
        return notify_fail("������û�г������޷��Ž���̳��\n");
        if(ob->query("sword"))
        return notify_fail("��ѽ��Ѿ������ˡ�\n");  
        if(me->query("family/family_name")!="������")
        return notify_fail("�㲻��������Ӳ��ܼ�����\n");  
        message_vision(CYN"$N�����ϵĳ������������ķŽ��˼�̳��\n"NOR,me);
        me->set_temp("jijian",1);
        destruct(ob);
        return 1;
 }
 int jijian_1(object me)
 {
        message_vision(HIR"$N��������������������ɵڰ˴�����"+me->name()+"�ڴ˼�����\n"NOR,me);
        message_vision(HIR"������һ��ҪΪ�����ɷ����󣬴�������Ļ�ҵ������λʦ������֮�飬���ӵ��ӡ�\n"NOR,me);
        message_vision(HIR"ϣ��������ӣ���֮���������ܷ����佣��֮���衣�ش˰ݼ���\n"NOR,me);
        call_out("jijian_2",3,me);
 //     remove_call_out("jijian_2");
        return 1;
 }
 int jijian_2(object me)        
 {
        object obj;
        obj=new(__DIR__"obj/changjian");
        message_vision(HIY"����......��ֻ����̳�н������ƣ�ͻȻ��������һ����һ�ѳ�����̳��Ծ��$N���С�\n"NOR,me);
        obj->move(me);
        obj->set("long","����һ���������������ĳ������������������"+me->name()+"�����֡�\n");
        obj->set("sword",me->query("id"));
        me->set_temp("jijian",0);
        me->set_temp("overjijian",1);
        me->set_temp("ji_jian",0);
        message("channel:chat",HIW"�����š�"+HIC+me->query("name")+"�ڡ������á��������ǰ���������������𽣡�\n"NOR,users());   
        return 1;
}
int valid_leave(object me, string dir)
{
        if (me->query_temp("ji_jian") && dir == "south" )
        {
                   return notify_fail("�����ڼ����������뿪��\n");
        }
        return ::valid_leave(me, dir);
}
