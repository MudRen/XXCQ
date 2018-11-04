//ÑªºÓ³µÄÚ

#include <room.h>
inherit ROOM;
void create ()
{
  set ("short", "ÑªºÓ³µÄÚ");
  set ("long", @LONG
ºöÈ»°ËÂíÆëË»£¬ÓÌÈçÉñ±øÌì½µ£¬Ñª¹â´óÏÖ£¬Å­¹Ä½ğ±ø£¬·­Ó¿¶ø½üÑªºÓ
³µ¡£¿ÉÒÔ¸Ğ¾õµ½Ñª³µÖ®ÖĞ£¬ÓĞÒ»¹É±ÆÈËµÄ¿Ö²À£¬Ò»¹É±ÆÈËµÄÒõº®Ö®Æø£¬ÆÕ
Í¨ÈË¸ù±¾ÊÜ²»ÁË¡£¶øÑª³µÍâµÄÏÊºìÉ«ïÎµñ£¬Ó³ÔÚÑ©µØÉÏ£¬¸üÓĞÒ»ÖÖÍÌÈËµÄ
ÆøÊÆ³µÍâÑª¹âÒş¶¯£¬³µÄÚ÷í°µÒ»Æ¬£¬½è×ÅÒÀÏ¡µÄ¹âÁÁ£¬Äã·¢ÏÖ³µ±ÚÉÏËÆºõ
ÓĞ×Ö(zi)¡
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "zi" : "ÕâÊÇÇ§°ÙÄêÀ´ÑªºÓÅÉÎäÑ§µÄ¾«»ª£¬Äã²»ÓÉÒ»Õó¿ñÏ²£¬¸ÏÃ¦ÄıÉñ¾²Æø¿ªÊ¼¿àË¼(think)ÆğÀ´.\n",        
]));
  
  setup();
}

void init()
{
        add_action("do_study", "think");
        add_action("do_jump", "tiao");
}

int do_study(string arg)
{   
   object me=this_player();
   int jingli_cost, qi_cost;
   if( !arg || (arg != "zi"))
     return notify_fail("ÄãÒªÑ§Ê²Ã´£¿\n");
   if( me->is_busy() )
     return notify_fail("ÄãÃ¦µÄºÜ£¬ÄÄÓĞ¹¦·òÈ¥Ñ§Ï°£¡\n");
   if( me->is_fighting() )
     return notify_fail("ÏÖÑ§ÏÖÂôÒÑÀ´²»¼°ÁË£¡\n");
   if( (int)me->query_skill("literate", 1) < 100)
     return notify_fail("Äã¿´ÁË°ëÌìÒ²¿´²»¶®ÉÏÃæ¿ÌµÄÊÇÊ²Ã´£¡\n");
   if( (int)me->query_skill("yiqiguan-riyue", 1) < 150)
     return notify_fail("ÄãµÄÄÚ¹¦ĞÄ·¨»¹Ì«µÍ£¬²»ÄÜ×êÑĞÉÏÃæµÄÎäÑ§£¡\n");
if( ((int)me->query_skill("yiqiguan-riyue", 1) >= 250) && (me->query_skill("tao",1)>=250))
     return notify_fail("Äã¶¨¾¦¿´ÁË»á£¬ÄãÒÑ¾­È«²¿ÁìÎòµ½ÁË¡£\n");
   
   jingli_cost = 80 - (int)me->query_int();
   if( (int)me->query("jingli") < jingli_cost )
     return notify_fail("ÄãÏÖÔÚÍ·ÔÎÄÔÕÍ£¬¸ÃĞİÏ¢ĞİÏ¢ÁË¡£\n");

   qi_cost = 80 - (int)me->query_con();
   if( (int)me->query("qi") < qi_cost )
     return notify_fail("ÄãÏÖÔÚ»ëÉíÎŞÁ¦£¬¸ÃĞİÏ¢ĞİÏ¢ÁË¡£\n");

   
   me->receive_damage("jingli", jingli_cost);
   me->receive_damage("qi", qi_cost);
   
        if( (int)me->query_skill("yiqiguan-riyue", 1) < 250)
   me->improve_skill("yiqiguan-riyue", 50);
      if ((random(10)<3) && (me->query_skill("tao",1)<250)) {
   me->improve_skill("tao",50);
    write("ÄãµÄµÀÑ§ĞÄ·¨½ø²½ÁË£¡\n");
    }

   write("ÄãÚ¤Ë¼¿àÏë£¬ÍêÈ«ÌÕ×íÓÚ³µÉÏµÄÎŞÉÏÎäÑ§Ö®ÖĞ£¬ÄãµÄÒ»Æø¹áÈÕÔÂ½ø²½ÁË¡£\n");

   tell_room( environment(me), me->name() + "Ë«ÊÖ»ÓÀ´»ÓÈ¥£¬²»ÖªÔÚ±È»®Ê²Ã´¡£\n", ({me}));

   return 1;
}


int do_jump(string arg)
{
          object me;
           object *obb;
           int i;

          me=this_player();
          if (!arg || arg!="out")
              return notify_fail("ÄãÒªÌøµ½ÄÄÀïÈ¥£¿\n");
          message_vision("Ö»¼û$NÌøÁË³öÈ¥£¡\n",me);
        obb=users();
        for(i=0; i<sizeof(obb); i++) {
        if (obb[i]->query_temp("xueheche"))
        {
                me->move(environment(obb[i]));
            message_vision("Ö»¼û$N´ÓÑªºÓ³µÉÏÌøÁËÏÂÀ´£¡\n",me);
            return 1;
        }
        }
                 me->move("/d/longmen/xuehepai/xueheting");

          message_vision("Ö»¼û$N´ÓÑªºÓ³µÉÏÌøÁËÏÂÀ´£¡\n",me);
          return 1;
}

