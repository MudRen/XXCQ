// Room: С��
// Date: by godzilla 1999.11.18
#include <ansi.h>
inherit ROOM;
string *skill_msg = ({
         "�ϱ�ǽ�Ͽ������µ�һ���С���ʯ��١�����������������������һ��!\n\n",
         "����ǽ�Ͽ������µ�һ���С����羪�硹����������������������һ��!\n\n",
         "����ǽ�Ͽ������µ�һ���С�����һ�ߡ�����������������������һ��!\n\n",
         "����ǽ�Ͽ������µ�һ���С���ţ�Ƴ�������������������������һ��!\n\n",
         "һ���㹦������������������������\n\n",
});

void create()
{
        set("short", "����");
        set("long", @LONG
û�뵽���Ȼ����һ�����ң�����ǽ��(wall)���������֣�����
�����ĸ������¼�˲�ͬ�����У�����һ����������ˮ���������µ�
һ�����졢�ء������ֲ�ͬ���С�
LONG );
        set("no_fight",1);
        setup();
}
void init()
{
         add_action("do_kan","look");
}
int do_kan(string arg)
{
        object me=this_player();
        int stage;
        if(!arg||arg=="")
        return 0;
        if(me->query_temp("start_lingwu"))
        return 0;
        if(me->query("lingwu_perform"))
        { 
                tell_object(me,HIW"���Ѿ���������Ĵ���У����������Ѿ������������ˡ����ǻ�ȥ��\n"NOR);
                me->move(__DIR__"xiaojing10");
                return 1;
        }       
        if(arg=="wall")
        {
                write("�㿪ʼ������ĥǽ�ϵĽ��У�\n");
                me->set_temp("start_lingwu",1);
                remove_call_out("do_yanxi");
                call_out("do_yanxi",5,me,stage);
                return 1;
        }       
}       
int do_yanxi(object me,int stage)
{
                        
        tell_object(me, skill_msg[stage]);
        if( ++stage < sizeof(skill_msg) )
        {
                call_out( "do_yanxi", 5, me, stage );
                return 1;
        }       
        else
        me->move(__DIR__"xiaojing10");
        me->set("lingwu_perform",1);
        tell_object(me,HIW"�Ĵ�������Ѿ�ȫ��ѧ�ᣬʹ��perfrom gong��kuai��shou��man�������У�\n"NOR);
        message("channel:chat",HIM"��������"+HIC+me->query("name")+"��ʯ�������������µ�һ��,��,��,���ľ��С�\n"NOR,users());   
        me->set_temp("start_lingwu",0);
}
        


