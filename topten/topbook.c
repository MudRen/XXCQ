// topten.c ¹�������а� 
// by mop


#include <ansi.h>
inherit ITEM;


void setup()
{}

void init()
{
        add_action("do_read", "read");
        add_action("do_ntopten", "ntopten");
}

void create()
{
          set_name(""+HIW"Сѩ�������а�"+NOR"", ({ "topten" }));
                  set("unit", "��");
                  set("no_get", "1");
                set("long", "����һ��Сѩ�������а�\n
                p0   (ʹ��˵��)
                p1   ʮ�����
                p2   ʮ����
                p3   ʮ��PKER
                p4   ʮ�󽣿�
                p5   ʮ��ȭ��
                p6   ʮ������
                p7   ʮ���Ṧ
                p8   ʮ��ǹ��
                p9   ʮ����
\n");
                
                set("value", 10000);
        setup();
}

int do_read(string page)
{
     string str,stri;
     string kind;
     switch(page)
     {
            case  "p0":
              write("���Ƿ���,д��\n\n"+HIW+"    
              Сѩ�������а�\n\n"+NOR);
            write("����������topten,������ntopten\n");
            return 1;


            case "p1":
                        kind="exp";
                        stri="ʮ�����";
                        break;
            case "p2":
                        kind="rich";
                        stri="ʮ����";
                        break;
            case "p3":
                        kind="pker";
                          stri="ʮ��PKER";
                        break;
            case "p4":
                        kind="sword";
                        stri="ʮ�󽣿�";
                        break;
            case "p5":
                        kind="unarmed";
                        stri="ʮ��ȭ��";
                        break;
            case "p6":
                        kind="literate";
                        stri="ʮ������";
                        break;
            case "p7":
                        kind="dodge";
                        stri="ʮ���Ṧ";
                        break;
            case "p8":
                        kind="spear";
                        stri="ʮ��ǹ��";
                        break;
            case "p9":
                        kind="blade";
                        stri="ʮ����";
                        break;
            default:
                        return notify_fail("�������ҳ?\n");
     }
        str=HIG+"Сѩ����";
        str+=HIR+stri+"\n";
        str+=TOPTEN_D->topten_query(kind);
        write(str+"\n");
        return 1;
}

int do_ntopten()
{
// ��Ϊ������Ҹ���
object *list;
int j; 
       list=users();
        j = sizeof(list);
           while( j-- )
             TOPTEN_D->topten_checkplayer(list[j]); 
        write ("TOPTEN�Ѿ���������\n");
        return 1;

}


