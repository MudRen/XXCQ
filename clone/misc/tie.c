// tie.c   change by zhm
inherit ITEM;
mapping where_map=([
"gc":"/d/city/guangchang",
"sl":"/d/shaolin/guangchang1",
"tam":"/d/city2/tian_anm",
"wd":"/d/wudang/chaotian",
"xy":"/d/xiaoyao/qingcaop",
"qz":"/d/quanzhou/zhongxin",
]);
void init(){
add_action("do_goto","goto");
}
void create(){
set_name("ʱ�մ�����",({"tie"}));
set("no_get",1);
set_weight(100); set_max_encumbrance(8000);
        if( clonep() )                set_default_object(__FILE__);
 else {     set("long",              "һ��ʱ�մ�������������ħ���������ܴ���(goto)�ĵط����¡�\n
\t����㳡(gc)    ������(sl)    �찲��(tam)   \n  
\t�䵱ɽ(wd)      ��ң��(xy)    Ȫ��(qz)  \n");
set("value", 50000);
set("unit","��");
}
}
int do_goto(string arg){
        object me,obj;string msg,str;str=where_map[arg];
        if( !arg||!stringp(str)) return notify_fail("��Ҫȥ���\n");
me=this_player();
             if (! environment(me)->query("outdoors"))
 return notify_fail("���ⷿ�����޷�ʹ��ħ�����͡�\n");
 if (me->is_fighting())
return notify_fail("ս�����޷�ʹ��ħ�����ͣ�");
str+=".c";
        if(file_size(str)<0) 
return notify_fail("û������ط���\n");
    if( stringp(msg = me->query("env/msg_mout")) )       {if (msg!="") message_vision(msg+"\n", me);} 
       else                message_vision("ֻ��һ��������ᣬ$N����Ӱ�Ѿ������ˡ�\n", me);
me->move(str);
if( stringp(msg = me->query("env/msg_min")) )
       {if (msg!="") message_vision(msg+"\n", me);}
        else                message_vision("$N����ӰͻȻ������һ������֮�С�\n", me);        return 1;}
