// topten.c 鹿鼎记排行榜 
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
          set_name(""+HIW"小雪初晴排行榜"+NOR"", ({ "topten" }));
                  set("unit", "本");
                  set("no_get", "1");
                set("long", "这是一本小雪初晴排行榜。\n
                p0   (使用说明)
                p1   十大高手
                p2   十大富翁
                p3   十大PKER
                p4   十大剑客
                p5   十大拳王
                p6   十大文人
                p7   十大轻功
                p8   十大枪神
                p9   十大刀王
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
              write("这是封面,写着\n\n"+HIW+"    
              小雪初晴排行榜\n\n"+NOR);
            write("如果你想更新topten,请输入ntopten\n");
            return 1;


            case "p1":
                        kind="exp";
                        stri="十大高手";
                        break;
            case "p2":
                        kind="rich";
                        stri="十大富翁";
                        break;
            case "p3":
                        kind="pker";
                          stri="十大PKER";
                        break;
            case "p4":
                        kind="sword";
                        stri="十大剑客";
                        break;
            case "p5":
                        kind="unarmed";
                        stri="十大拳王";
                        break;
            case "p6":
                        kind="literate";
                        stri="十大文人";
                        break;
            case "p7":
                        kind="dodge";
                        stri="十大轻功";
                        break;
            case "p8":
                        kind="spear";
                        stri="十大枪神";
                        break;
            case "p9":
                        kind="blade";
                        stri="十大刀王";
                        break;
            default:
                        return notify_fail("你想读哪页?\n");
     }
        str=HIG+"小雪初晴";
        str+=HIR+stri+"\n";
        str+=TOPTEN_D->topten_query(kind);
        write(str+"\n");
        return 1;
}

int do_ntopten()
{
// 仅为在线玩家更新
object *list;
int j; 
       list=users();
        j = sizeof(list);
           while( j-- )
             TOPTEN_D->topten_checkplayer(list[j]); 
        write ("TOPTEN已经重新排名\n");
        return 1;

}


