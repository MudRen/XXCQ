
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name( "����", ({ "ling" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
               seteuid(geteuid());
                set("long","����һ��ӵ������Ȩ�������ơ�\n");
                set("value", 0);
                set("fam","���ζ���");
                set("par",HIG"���ζ���"NOR);
                set("material", "iron");
              }
}

void init()
{
        add_action("do_buzhi","buzhi");
        add_action("do_cancel","cancel");
        add_action("do_zhiyuan","zhiyuan");
        add_action("do_zhanling","zhanling");
}

int do_buzhi(string arg)
{
        object ob,me;
        string dest,place;
        mapping fam,party;
        me=this_player();
        
        if (!arg || arg=="") return notify_fail("ָ���ʽ��buzhi ��һ�npc to λ��\n");
       if( sscanf(arg, "%s to %s", dest, place)==2 || sscanf(arg, "%s %s", dest,place)==2 );
         else return notify_fail("ָ���ʽ��buzhi ��һ�npc to λ��\n"); 
                ob=find_living(dest);
                if(!objectp(ob))
                {
                        tell_object(me,"�Ҳ�������ˡ�\n");
                        return 0;
                }
                fam=(mapping)ob->query("family");
                party=(mapping)ob->query("party");
                if (( !fam || fam["family_name"]!="���ζ���") && (!party || party["party_name"]!=HIG"���ζ���"NOR) )
                return notify_fail("�㲻��ָ������ˡ�\n");
//              arg=resolve_path("/d/huafu",arg);
//              if ( file_size(arg+".c")==-1)
//              return notify_fail("û������ط���\n");

//              if (!(ob->query_temp("compaign_start")))
//              {
                tell_object(ob,HIC"���ζ���������Ϯ�������ٵ�"+place+"������ˡ�\n");
                ob->set_temp("buzhile",1);
//              }
                return 1;
}

int do_zhiyuan(string arg)
{
        object ob,me;
        string dest;
        mapping fam,party;
        me=this_player();
        
        if( !arg ) return notify_fail("ָ���ʽ��zhiyuan ��һ�npc λ��\n");    
        if(sscanf(arg,"%s %s",dest,arg)==2)
        {
                ob=find_living(dest);
                if(!objectp(ob))
                {
                        tell_object(me,"�Ҳ�������ˡ�\n");
                        return 0;
                }
                fam=(mapping)ob->query("family");
                party=(mapping)ob->query("party");
                if (( !fam || fam["family_name"]!="���ζ���") && (!party || party["party_name"]!=HIG"���ζ���"NOR) )
                return notify_fail("�㲻��ָ������ˡ�\n");
//              arg=resolve_path("/d/huafu",arg);
//              if ( file_size(arg+".c")==-1)
//              return notify_fail("û������ط���\n");

//              if (!(ob->query_temp("compaign_start")))
//              {
                tell_object(ob,HIC"���ζ���������Ϯ�������ٵ�"+arg+"֧Ԯ��\n");
//              if (file_name(environment(me))=="/d/huafu/dating")
//              {
                ob->set_temp("buzhile",1);
//              }
//              }
                return 1;
        }
        return notify_fail("ָ���ʽ��zhiyuan ��һ�npc λ��\n");       
}

int do_zhanling(object me)
{
         int i;
         mapping fam,party;
         object *obb;
        object where;
        me=this_player();
        where=environment(me);
        
                        obb=all_inventory(where);
                        for(i=0; i<sizeof(obb); i++) {
                                if (obb[i]->is_character() )
                                {
                                  if (obb[i]==me) continue;
                                fam=(mapping)obb[i]->query("family");
                                party=(mapping)obb[i]->query("party");
                                if ((fam && fam["family_name"]=="���ζ���") || (party && party["party_name"]==HIG"���ζ���"NOR ))
				return notify_fail("��ط�����"+fam["family_name"]+"�������ţ��Ȱ��������˵��\n");
                                }
                        }

        if (where->query("class")==this_object()->query("fam"))
        return notify_fail("��ط��Ѿ�����ĵ����ˡ�\n");
        
        where->set("class",query("fam"));
        where->set("long","�����Ѿ���"+query("fam")+"ռ�졣\n");
	message("channel:chat",			HIY"���԰ס�"HIC+query("fam")+"�Ѿ�ռ����"+where->query("short")+"��\n"NOR,users());
        return 1;
}


int do_cancel(object me)
{
           object *obb;

           int i;
           me=this_player();

       obb=users();
        for(i=0; i<sizeof(obb); i++) {
          obb[i]->delete_temp("killwei");
          obb[i]->delete_temp("compaign_start");
        }
     return 1;
}
