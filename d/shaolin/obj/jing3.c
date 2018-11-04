// fojing11.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_discuss","discuss");
}


string* titles = ({
        "Ğé¿Õ²Ø¾­",
        "´ó¿×È¸¾­",
        "±¦Íş¾­",
        "ÕıÂÉÎÄ¾­",
        "Ê×ÀãÑÏ¾­",
});

void create()
{
       set_name(YEL + titles[random(sizeof(titles))] + NOR, ({ "jing", "shu", "book" }));
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "±¾");
                set("long", "ÕâÊÇÒ»²á·ğ¾­£¬ÊéÒ³ÒÑ¾­·º»Æ£¬ÀïÃæ¼ÇÔØÁËÒ»Ğ©³õ¼¶µÄìø×ÚË¼Ïë¡£\n");
//        set("value", 1000);³)
                set("material", "paper");
                set("skill", ([
                        "name": "buddha",
                        "exp_required" : 0,
                        "jingli_cost" : 20,
                        "difficulty" : 10,
                        "min_skill" : 0,
                        "max_skill" : 80,
                ]));
        }
}
int do_discuss(string arg)
{
    object me, obj,ob;
    int mylev , objlev ,myexp,objexp;
    int myint , objint,count,times;

    string book_name = "jing";
    mapping skill = this_object()->query("skill");
      mapping fam;
    me = this_player();
      fam = me->query("family");
       
        if (me->is_busy())
                return notify_fail("ÄãÏÖÔÚÕıÃ¦×ÅÄØ¡£\n");     
         
        if( environment(me)->query("no_fight") )
                return notify_fail("ÕâÀï²»ÒªÌÖÂÛ¡£\n");

        if( !arg )
                return notify_fail("ÄãÏëºÍË­ÑĞÌÖ·ğ¾­£¿\n");
       if (!(fam = me->query("family")) || fam["family_name"] != "ÉÙÁÖÅÉ")
      return notify_fail("Äã²»ÊÇ·ğÃÅµÜ×Ó,ÈçºÎÊ¹µÃ!\n");

        if(!objectp(obj = present(arg, environment(me))))

                return notify_fail("ÕâÀïÃ»ÓĞÕâ¸öÈË¡£\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("¿´Çå³şÒ»µã£¬ÄÇ²¢²»ÊÇ»îÎï¡£\n");

        if(obj == me)
                return notify_fail("Äã²»ÄÜ×ÔÑ§µÄ¡£\n");

        myexp =  me -> query ("combat_exp" ) ;
        objexp = obj -> query ("combat_exp" ) ;
        mylev =  (int)me -> query_skill("buddha",1) ;
        objlev = (int)obj -> query_skill("buddha",1) ;
        myint = (int) me -> query("int" ) ;
        objint = (int)obj -> query("int" ) ;
        times = (int)me->query("MKS")/10+(int)me->query("PKS")/5+random(5)+5;

        if ((int)me->query("shen") < 0  || (int)obj->query("shen") < 0)
                      return notify_fail("·ğ¾­ÊÇÕıÅÉÈËÊ¿ÑĞÌÖÖ®ÓÃµÄ\n");

        if(!objectp(ob = present(book_name, obj)) )
                return notify_fail("¶Ô·½Ã»ÓĞ·ğ¾­ÔõÃ´ÑĞÌÖ°¡!\n");

        if ( (mylev < 20) || (mylev > (skill["max_skill"]+1)*2))
                return notify_fail("ÄãµÄìø×ÚĞÄ·¨Ì«µÍ »ò Õâ±¾·ğ¾­Ì«Ç³ÁË!\n");

        if ( (objlev < 20) || (objlev > (skill["max_skill"]+1)*2))
                            return notify_fail("¶Ô·½µÄìø×ÚĞÄ·¨Ì«µÍ »ò ÄÇ±¾·ğ¾­Ì«Ç³ÁË!\n");
                         if ( (mylev - objlev)*100/objlev > 20 || (objlev - mylev)*100/mylev > 20) 
		 	 return notify_fail("ÄãÃÇµÄìø×ÚĞÄ·¨²î¾àÌ«´óÁË,²»ÄÜ¹²Í¬ÑĞÌÖ!\n");

		 if ( (me->query("int") - obj->query("int")) > 10 || (obj->query("int") - me->query("int")) > 10)
				 return notify_fail("ÄãÃÇµÄÌì×Ê²î¾àÌ«´óÁË,²»ÄÜ¹²Í¬ÑĞÌÖ!\n");
          if ( me->query("jingli") < 20 || me->query("qi") < 20 || obj->query("qi") < 20 || obj->query("jingli") <20)
				 return notify_fail("ÄãÃÇµÄÆøÑªÒÑ¾­²»ÄÜÔÙÑĞÌÖÁË!\n");



                         if (me->query_temp("qinjiao") > 0)
				 return notify_fail("Äã¶Ôìø×ÚĞÄ·¨µÄÀí½âĞèÒª¸ßÈËµÄÖ¸Òı!\n");

              if (me->query_temp("mcount") > times )  {
                            me->set_temp("qinjiao",1);
                       obj->set_temp("qinjiao",1);
                        return notify_fail("ÄãÃÇË«·½¶¼Áì»áÁËìø×ÚĞÄ·¨ĞÂµÄÒªÁìÁË!\n");}

              message_vision(HIY "\n$N·­¿ª·ğ¾­ºÍ$nÒ»Æğ²ÎÎòÆäÖĞµÄ°ÂÃØ.\n"NOR, me, obj);
              count = me->query_temp("mcount");
//                         score = me->query("score");
             me->set_temp("mcount",count+1);
//               if (times < 20)  me->set("score",score+100-times*5);
//                        else me->set("score",score+100-times*3);

          me->improve_skill("buddha", (int)me->query_skill("literate", 1)/5+5);
          obj->improve_skill("buddha", (int)obj->query_skill("literate", 1)/5+5);
         me -> receive_damage ("jingli", 30 - random(5));
         me -> receive_damage ("qi", 30 -  random(5));
         obj -> receive_damage ("jingli", 30 - random(5));
         obj -> receive_damage ("qi",30 - random(5));
	 obj -> start_busy (1) ;
         me -> start_busy (1) ;
         return 1;
}
