// poshan-dao.c ÆÆÉ½µ¶

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$NÎÕ½ôÊÖÖÐ$wÒ»ÕÐ¡¸ÆÆÕóÒ»µ¶¡¹µãÏò$nµÄ$l",
        "force" : 50,
        "dodge" : 40,
        "damage" : 20,
        "lvl"    : 0,
        "skill_name" : "ÆÆÕóÒ»µ¶", 
        "damage_type" : "¸îÉË"
]),
([      "action" : "$NÏòÇ°¿çÉÏÒ»²½£¬ÊÖÖÐ$wÊ¹³ö¡¸ÆÆÄ§Ò»µ¶¡¹¿³Ïò$nµÄºí²¿",
        "force" : 90,
        "dodge" : 80,
        "damage" : 50,
        "lvl"    : 20,
        "skill_name" : "ÆÆÄ§Ò»µ¶",
        "damage_type" : "¸îÉË"
]),
([      "action" : "Ö»¼û$NÂÕÆðÊÖÖÐµÄ$w£¬Ê¹³ö¡¸ÆÆÑýÒ»µ¶¡¹Íòµã½ð¹âÖ±Åü$n",
        "force" : 90,
        "dodge" : 70,
        "damage" : 60,
        "lvl"    : 40,
        "skill_name" : "ÆÆÑýÒ»µ¶",
        "damage_type" : "ÅüÉË"
]),
([      "action" : "$NÊ¹³ö¡¸ÆÆÁ¢Ò»µ¶¡¹£¬ÊÖÖÐ$wÈç¹ÎÆð¿ñ·çÒ»°ãÉÁË¸²»¶¨£¬¸îÏò$n",
        "force" : 200,
        "dodge" : 80,
        "damage" : 65,
        "lvl"    : 80,
        "skill_name" : "ÆÆÁ¢Ò»µ¶",
        "damage_type" : "¸îÉË"
]),
([      "action" : "$NËæÊÖÊ¹³öµ¶·¨Ö®°ÂÒå¡¸ÆÆ¾ÉÒ»µ¶¡¹£¬ÊÖÖÐ$wÈç¹í÷ÈÒ»°ãÆÌÌì¸ÇµØµÄ¿³Ïò$n",
        "force" : 300,
        "dodge" : 90,
        "damage" : 90,
        "lvl"    : 100,
        "skill_name" : "¡¸ÆÆ¾ÉÒ»µ¶¡¹",
        "damage_type" : "¸îÉË"
]),
([      "action" : HIY"$NÊ¹³öÆÆÉ½µ¶·¨Ö®×îÖÕ¾ø¼¼[1;36m¡¸ÆÆÊÆÒ»µ¶¡¹[0m,[1;33mÊÖÖÐ$wÓÌÈçòÔÁúÒ»°ãÅüÏò$n[0m"NOR,
        "force" : 400,
        "dodge" : 100,
        "damage" : 350,
        "lvl"    : 150,
        "skill_name" : "HIY¡¸ÆÆÊÆÒ»µ¶¡¹"NOR,
        "damage_type" : "¸îÉË"
]),
});


int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("Äã¶Ôµ÷ÀíÆøÏ¢µÄ»ðºò²»¹»£¬ÎÞ·¨Ñ§¡¸ÆÆÉ½µ¶·¨¡¹¡£\n");
        if ((int)me->query("max_neili") < 300)
                return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·¡¸ÆÆÉ½µ¶·¨¡¹¡£\n");
        if ((int)me->query("shen") < 10000)
        	return notify_fail("ÓÃÆÆÉ½µ¶·¨Ê±ÒªÂúÇ»ÕýÆø£¬·ñÔò»á·´ÊÜÆäº¦¡£\n");
        return 1;
}


string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("poshan-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/4)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·¡¸ÆÆÉ½µ¶·¨¡¹¡£\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·¡¸ÆÆÉ½µ¶·¨¡¹¡£\n");
        me->receive_damage("qi", 15);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"poshan-dao/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;
    if(me->query("douzhi")<1)
      return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
               if ( (( (int)victim->query("shen") - (int)me->query("shen") ) > 50000) && ( (int)me->query("shen") < 0 )  )
			{
				me->add("douzhi",-30);
				message_vision("$Nº§È»·¢ÏÖÊÖÖÐµÄ±øÆ÷¾¹È»ÊÜµ½¶Ô·½ÕýÆøµÄÎüÒý¶ø²»ÌýÊ¹»½ÁË¡£$N¶·Ö¾ÏÂ½µÁË£¡\n",me);              
				return 1;
			}
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                return RED "Ö»¼û$nÒ»¸ö²»ÁôÉñ£¬±»$NµÄµ¶¿³µÄÑªÈâºá·É£¡\n"NOR;
        }
}


