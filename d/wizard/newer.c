inherit NPC;
#include <ansi.h>

#define NEWS_OB "/feature/news"

string do_say();
int do_news(string);

string *rnd_say = ({
	"�Һ�Ȼ����ȥ����.",
	"������û����bbs���к�����Ӵ!",
	"Ϊʲô��Ҷ�������?��",
	"�ɲ����Ը�����������ɱ�ˣ�",
	"���������鲻���, ��ҿ�ҪС����.",
	"��������������?",
	"˭�뽲�����£�",
	"���ڼ����ˣ�",
	"Ϊʲô��˵����?",
	"Ϊʲô����ȥ˯����?",
	"˭��ȥ����Ӱ?",
	"�ҿ��Գ�ȥɱ����?",
	"�Ҷ�MUD����ûʲô�ø�.",
	"�Ҷ��������ûʲô��Ȥ.",
	"�Һ���ܱ�Ү.",
	"�������������?",
	});

void create()
{
	set_name("Сѩ����", ({"snow"}));
	set("nickname", HIM "���ŷ�����" NOR);
	set("gender", "Ů��");
	set("age", 21);
	set("rank_info/respect", "С����");
	set("max_qi", 10000);
	set("max_jing", 10000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("inmortal",1);
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("no_get_from", 1);

	set("chat_chance", 3);
	set("chat_msg", ({
		(: do_say :),
	}) );
	set("combat_exp", 3000000);
	set("shen_type", 1);
	set("score", 5000000);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

void init()
{
	if(wizardp(this_player()))
		add_action("do_news","news");
}

void die()
{
	message_vision("��Ǹ�����ǲ������ġ�\n",this_object());
	return ;
}

string do_say()
{
	int i=random(sizeof(rnd_say));
	if(random(5)>4)
		do_news("random");
	return rnd_say[i];
}

void relay_channel(object ob, string channel, string)
{
	if( !userp(ob) || (channel != "chat") ) return;

	if( ob==this_object() ) return;

	if(random(11)>10)
		do_news("random");
}

int do_news(string num)
{
	object newob,*alluser;
	string msg;
	int i;
	newob=new(NEWS_OB);
	if(num&&num!="random"&&sscanf(num,"%*d")==1)
		msg=HIG+"�����š�Сѩ����(CCTX)��"+HIY+newob->query_news(num)+NOR;
	else
		msg=HIG+"�����š�Сѩ����(CCTX)��"+HIY+newob->query_news()+NOR;
	alluser=users();
	if(pointerp(alluser))
	{
		for(i=0;i<sizeof(alluser);i++)
		{
			if(alluser[i]->query("env/nonews")==0)
				tell_object(alluser[i],msg);
		}
	}
	return 1;
}
