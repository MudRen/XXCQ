//Write by godzilla
//Date 1999.12.23
#include <ansi.h>
int do_dujiang()
{
        object me=this_player();
        object obj=find_object("/d/bianliang/duchuan");
        int dge=me->query_skill("dodge");
        if(me->query("neili")<500)
        return notify_fail("��������������޷�Խ���԰���\n");
         if(me->is_busy())
        return notify_fail("����æ���ء�\n");
        
        if(dge>=260)
        {
                if(me->query("family/family_name")=="������")
                {
                        if(present("tianyu sword",me))
                        {
                                message_vision(HIY"ֻ��$N������"HIC"����"HIY"������һ�ף����ŷ�Ծ�Ͻ����������У����԰���ȥ��\n"NOR,me);
                                tell_room(obj,HIY"��Ȼ�������������Ȼ����"+me->name()+"����"HIC"����"HIY"���԰���ȥ��\n"NOR);
                                me->move("/d/bianliang/yelle");
                                write(HIY"������"HIC"����"HIY"���ȵ����µ��档\n"NOR);
                                me->start_busy(3);
                                me->add("neili",-500);
                                return 1;
                        }
                        else
                        {
                                 message_vision(HIC"$N��Ȼ����һ������˫��Ĺ����磬�������һ�����԰�Ծȥ��\n"NOR,me);
                                 tell_room(obj,HIC"ֻ��"+me->name()+"�ڴ�����һ�㣬��������԰���ȥ��\n"NOR);
                                 me->move("/d/bianliang/yelle");
                                 write(HIC"��Ӷ԰�Ծ�������ȵ����µ��档\n"NOR); 
                                 me->start_busy(3);
                                 me->add("neili",-500);
                                 return 1;
                        }         
                        
                }
                else
                {
                        message_vision(HIC"$N��Ȼ����һ������˫��Ĺ����磬�������һ�����԰�Ծȥ��\n"NOR,me);
                        tell_room(obj,HIC"ֻ��"+me->name()+"�ڴ�����һ�㣬��������԰���ȥ��\n"NOR);
                        me->move("/d/bianliang/yelle");
                        write(HIC"��Ӷ԰�Ծ�������ȵ����µ��档\n"NOR); 
                        me->start_busy(3);
                        me->add("neili",-500);
                        return 1; 
                }       
        }
        tell_object(me,"�����������������޷�Խ���ƺӣ������Ӳ��������(tiao)��\n");
        me->set_temp("try_tiao",1);
        return 1;                       
}
int do_jump()
{
        object me=this_player();
        object obj=find_object("/d/bianliang/duchuan");
        if(!me->query_temp("try_tiao"))
        return 0;
        message_vision(HIC"$N��Ȼ����һ������ʹ��ȫ������԰�Լȥ��\n"NOR,me);
        tell_room(obj,HIC"ֻ��"+me->name()+"�Ӷ԰������˹��������ǵ�һ��ʱ����ͨһ��������ˮ���Ȼ������������\n"NOR);
        message("channel:chat", HIW"����ȡ�һ��̶��ġ�H��E��L��P�������ӻƺ�ˮ�ﴫ����ԭ����"+me->query("title")+me->name()+"\n�Բ�������ɻƺӣ���������˻ƺ�ˮ��Լ��ֲ�ʶˮ��ֻ�øߺ���ȡ�\n"NOR, users() );
        me->set_temp("try_tiao",0);
        write(CYN"����һ�����ʱ�������㣬���ڰ������������\n"NOR,me);
        tell_object(me,"��о�ͷ�����ͣ�һ��ʧȥ��ֻ����\n");
        me->set("water",500);
        me->unconcious();
        return 1;
}        
    
