// marry_card.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("���֤��", ({"marrycard",}) );
        set_weight(10);
        set("no_get",1);
        set("no_drop","��Ľ��֤���ܶ���,ֻ��ȥ���ð���顣\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
        }
}
void autoload(string arg)
{
        int i;
        object couple_ob;
        object me;
        string tmpstr, tmpstr1;
        me = this_player();
        couple_ob = find_player(arg);
        if (couple_ob){
                if ((string)couple_ob->query("gender") != "Ů��"){
                        tmpstr1 = "�Ϲ�"; 
                        tmpstr = "����";
                } else {
                        tmpstr1 = "����";
                        tmpstr = "�Ϲ�";
                }
                
         write(sprintf( HIR "���%sҲ�������ȥ����...\n"NOR,tmpstr1));
                tell_object(couple_ob ,
                sprintf( HIR "���%s����,��ȥ��...\n" NOR, tmpstr));

//me->name(1)+"("+me->query("id")+")",environment(me))->query("name") ); 
                
                
        }
        set("name","���"+arg+"�Ľ��֤");

}

string query_autoload()
{
        object *list, me;
        object couple_ob;
        string target,cardname;
        int i;

        me = this_player();
        list = all_inventory(this_player());
        i = sizeof(list);
        while (i--) {
              if (((string)list[i]->query("id")) == "marrycard")
                cardname = list[i]->query("name");
        }

        sscanf(cardname,"���%s�Ľ��֤" ,target);
        return target;
}


