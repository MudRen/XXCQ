// tanglyz

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ÌÆÀÏÒ¯×Ó", ({ "tanglyz", "tang", "yezi"}));
//	set("nickname", "Ğ¡Ê¦ÃÃ");
	set("long", 
"ÌÆ·½Éí²Ä½¿Ğ¡£¬³¤µÄ¼«ÎªÇåĞã£¬ÓÖ´ø¼¸·ÖÓ¢Æø£¬Çå¾¢¶àÓÚÈáÈõ¡£\n"
"ËıÊÇÌÆÃÅ³¤·¿×ÚÖ÷ÌÆÒ¢Ë´Ö®Å®£¬ºóÓÖµÃÌÆÀÏÌ«Ì«Ç×ÊÚÒÂ²§£¬ÔÚÌÆÃÅµØÎ»ÆÄ¸ß¡£\n");
	set("gender", "ÄĞĞÔ");
	set("age", 91);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 18);
	set("int", 25);
	set("con", 24);
	set("dex", 28);

	set("max_qi", 5000);
	set("max_jingli", 2000);
	set("max_douzhi", 1000);
	set("douzhi", 1000);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 50);
	set("combat_exp", 2500000);
	set("score", 10000);

	set_skill("force", 300);
//	set_skill("zixia-shengong", 30);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("blade", 300);
	set_skill("strike", 300);
/*	set_skill("hunyuan-zhang", 50);
	set_skill("huashan-jianfa", 50);
	set_skill("huashan-shenfa", 50);
	set_skill("fanliangyi-dao", 30);

	map_skill("force", "zixia-shengong");
	map_skill("blade", "fanliangyi-dao");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");
*/
	create_family("ËÄ´¨ÌÆÃÅ", 2, "ÕÆÃÅ");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query ("family/family_name") == "ËÄ´¨ÌÆÃÅ" && (int)ob->query ("combat_exp") > 1000000 )
	{
		message_vision("ÌÆÀÏÒ¯×ÓÎ¢Î¢Ò»Ğ¦£¬¶Ô$NËµµÀ:¡°Ïë°İÊ¦µÄ»°È¥ÕÒÀÏÌ«Ì«°É£¬ÎÒÒÑ¾­²»ÊÕÍ½µÜÁË£¡¡±",ob);
		message_vision("ÌÆÀÏÒ¯×ÓÎ¢Î¢Ò»¶Ù£¬ÓÖµÀ:¡°²»¹ı£¬¼ÈÈ»ÄãÒÑ¾­ÕÒµ½ÎÒÕâÀïÁË£¬ÎÒ¾ÍÖ¸µãÄã¼¸ÕĞ°É£¡¡±",ob);
/*
	´Ë¶ÎÓÃÀ´Ìí¼ÓÌÆÀÏÒ¯×ÓµÄËùÖ¸µãµÄ¹¦·ò·!!!!

*/
	}
	else
		if ( (string)ob->query ("family/family_name") != "ËÄ´¨ÌÆÃÅ" )
		{
			message_vision("\nÌÆÀÏÒ¯×ÓÎ¢Î¢Ò»Ğ¦£¬¶Ô$NËµµÀ:¡°Äã²»ÖªÎÒÌÆÃÅÄËÊÇÊÀ¼Ò£¬²»ÊÕÍâĞÕµÜ×ÓÂï£¡¡±\n",ob);
			message_vision("ÌÆÀÏÒ¯×ÓÎ¢Î¢Ò»¶Ù£¬ÓÖµÀ:¡°²»¹ı£¬¼ÈÈ»ÄãÒÑ¾­ÕÒµ½ÎÒÕâÀïÁË£¬¾ÍºÈ±­²èÔÙ×ß°É£¡¡±\n",ob);
			tell_object(ob, "ÌÆÀÏÒ¯×Ó¼ûÄãÓĞĞ©ÓÌÔ¥£¬ËµµÀ:¡°Õâ²è¿ÉÊÇ¼«ÆäÕä¹ó£¬ºÈÁË¿ÉÒÔ¹Ì±¾ÅàÔª£¬¶ÔÏ°ÎäÖ®ÈË¿ÉÊÇ´ó´óµÄÓĞÒæ°¡£¡¡±\n\n");
			write(YEL"ÄãÒªºÈÂğ£¿ÇëÊäÈëÑ¡Ôñ£¨y)/n £º"NOR);
			input_to("accept_cha", 1, ob, 1);
		}
		else
			tell_object(ob, "ÌÆÀÏÒ¯×ÓÍïÏ§µÄ¶ÔÄãËµ:¡°¿ÉÏ§ÄãµÄ¹¦·ò»¹²»µ½¼Ò£¬²»ÄÜÊ¹ÓÃÎÒµÄ¾ø¼¼£¡ÄãÒÔºóÔÙÀ´°É£¡¡±\n");
	return;
}

void accept_cha(string want, object ob, int forever)
{
	if ( want == "" || want == "y" || want == "Y" )
	{
		message_vision("ÌÆÀÏÒ¯×ÓÎ¢Ò»Ì§ÊÖ£¬±ãÓĞÒ»¼Ò¶¡¸ø$N·îÉÏÁËÒ»±­Ïã²è£¡\n",ob);
		tell_object(ob, "Ö»¼û²èË®·¢³öµ­µ­µÄÂÌÉ«£¬ÕıÃ°×ÅÈÈÆø£¬¼¸Æ¬²»ÖªÃûµÄÒ¶Æ¬Æ¯ÔÚ±­ÖĞ£¬ÎÅÆğÀ´ÇåÏãÆË±Ç¡£\n");
		message_vision("$N½«²è±­¶ËÆğ£¬ÃÀÃÀµÄºÈÁËÒ»¿Ú¡£\n", ob);
		call_out("dead", 120, ob);
	}
	else
	{
		message_vision("\nÌÆÀÏÒ¯×Ó²ªÈ»´óÅ­£¬¶Ô$NºÈµÀ:¡°ÈÃÄãºÃËÀÄã²»Òª£¬·ÇÒªÎÒ¶¯ÊÖÂğ£¡ÎÒÕâÀïÊÇ²»ÄÜ±»ÍâÈËÖªµÀµÄ£¡¡±\n",ob);
		this_object()->kill_ob(ob);
		ob->fight_ob(this_object());
	}
}

int dead(object ob)
{
	tell_object(ob,HIR"Äã¸¹ÖĞÍ»È»Èçµ¶½ÊÒ»°ãÌÛÍ´£¬Ô­À´²èÖĞ¾¹ÊÇ¾ç¶¾......\nÄãÑÛÇ°Ò»ºÚ£¬Ò»Í·ÔÔµ¹ÔÚµØÉÏ......"NOR);
	tell_room( environment(ob), HIR + ob->query("name") + "Í»È»Ò»Í·ÔÔµ¹ÔÚµØÉÏ£¡"NOR, ob);
	ob->die();
	tell_room( environment(this_object()), "ÌÆÀÏÒ¯×Ó³¤Ì¾Ò»Éù:¡°°¦£¡ÍâÈËÔõÃ´»á´³½øÀ´ÁËÄØ£¡¡±");
}