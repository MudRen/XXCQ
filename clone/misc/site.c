// transite.c   write by fan
inherit ITEM;
mapping where_map=([
"gc":"/d/city/guangchang",
"sl":"/d/shaolin/guangchang1",
"bt":"/d/baituo/dating",
"tam":"/d/city2/tian_anm",
"hmy":"/d/heimuya/up1",
"hs":"/d/huashan/zhenyue",
"wd":"/d/wudang/chaotian",
"ts":"/d/taishan/nantian",
"xy":"/d/xiaoyao/qingcaop",
"xx":"/d/xingxiu/xxh1",
"xs":"/d/xueshan/dadian",
"shl":"/d/shenlong/dating",
"qz":"/d/quanzhou/zhongxin",
"lj":"/d/lingjiu/dating",
]);
void init(){
add_action("do_trans","trans");
}
void create(){
set_name("ħ��������",({"trans site","site"}));
set_weight(100); set_max_encumbrance(8000);
set("no_drop", "�������������뿪�㡣\n");
        if( clonep() )                set_default_object(__FILE__);
 else {     set("long",              "һ��ħ����������������ħ���������ܵ���(trans)�ĵط����¡�\n
\t����㳡(gc)    ������(sl)  ����ɽ(bt)  �찲��(tam) \n
\t��ľ��(hmy)     ��ɽ(hs)    �䵱ɽ(wd)  ̩ɽ(ts)    \n
\t��ң��(xy)      ���޺�(xx)  ѩɽ��(xs)  ������(shl) \n
\tȪ��(qz)        ���չ�(lj)\n");
set("unit","��");
}
}
int do_trans(string arg){
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
