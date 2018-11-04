// modify by mulan

inherit NPC;

int ask_book();
int ask_teach();
int do_qingjiao(string arg);


void create()
{

        set_name("��ͥ", ({"tie ting","tie","ting",}));
        set("long",
                "����һλ�����Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
                "���ýݣ������ƺ�ѧ��һ���书��\n"
        );

        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 20);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 35);
        set("dex", 20);
        set("max_qi", 450);
        set("qi", 450);
        set("max_jingli", 400);
        set("jingli", 400);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 20);
        set("combat_exp", 15000);
        
        set_skill("force", 40);
        set_skill("banruo-changong", 40);
        set_skill("dodge", 40);
        set_skill("shaolin-shenfa", 40);
        set_skill("cuff", 50);
        set_skill("luohan-quan", 50);
        set_skill("parry", 40);

        map_skill("force", "banruo-changong");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("parry", "luohan-quan");

        prepare_skill("cuff", "luohan-quan");

        create_family("������", 37, "����");

        set("inquiry", ([
                "study" : (: ask_teach :),
                "����" : (: ask_teach :),
                "ѧϰ" : (: ask_teach :),
                "literate" : (: ask_teach :),
                "book" : (: ask_book :),
                "��" : (: ask_book :),
                "����" : (: ask_book :),
        ]) );

        setup();

        carry_object(__DIR__"obj/huijiasha")->wear();
        carry_object(__DIR__"obj/sengxie")->wear();
        carry_object("/d/shaolin/obj/jing2");
        carry_object("/d/shaolin/obj/jing3");
        carry_object("/d/shaolin/obj/jing4");
}

void init()
{
        add_action("do_qingjiao", "qingjiao");
}

int ask_book()
{
        object me, *inv, ob;
        mapping myfam, skill;
        int i;
        me = this_player();
        ob = this_object();
        myfam = (mapping)me->query("family");
        inv = all_inventory(ob);

        if (!myfam || myfam["family_name"] != "������")
        {
                command("hmm " + me->query("id"));
                command("say �㲻�����ֵ��ӣ���ôҲ��Ҫ�飬������ȥ��");
                return 1;
        }

        if (me->query_temp("ask_book", 1))
        {
                command("say ����ǰ����黹û������ô�����裡");
                return 1;
        }

        for(i=sizeof(inv)-1; i>=0; i--)
        if (inv[i]->query("id") == "jing")
        {
                skill = (mapping)inv[i]->query("skill");
                if (skill["name"] == "buddha")
                {
                        command("give jing to " + me->query("id"));
                        message_vision("���Զ�������С�ľ��飬��Ҫ���˻���Ū���ˡ�\n", me);
                        me->set_temp("ask_book", 1);
                        return 1;
                }
        }

        command("say ���Ѿ����������ӽ���ˣ���ȥ������ҪҪ���ɡ�");

        return 1;
}



int ask_teach()
{
        object me,ob;
        me = this_player();
        ob = this_object();

        if (!me->query("family") || me->query("family/family_name")!="������")
        {
                command("say �����ֵ��Ӳ����ڴ˶��飡");
                return 1;
        }

        if ( me->query_temp("xuet"))
        {
                tell_object(me,"�㲻������ѧϰ��?\n ");
                return 1;
        }

        message_vision("��ͥ��ʮ������"+RANK_D->query_respect(me)+"������ѧϰ�ģ�\n\n", me);
        command("look "+me->query("id"));

        if ((int)me->query_skill("literate", 1) > 41)
        {
                message_vision("\n��ͥ��ʮ������λ"+RANK_D->query_respect(me)+"����ѧʶ�����������ҽ̡�\n\n", me);
                return 1;
        }

        else
        {
                message_vision("\n��ͥ˵���úã������á�\n\n", me);
                message_vision("$N�ߵ�һ������ǰ����������\n\n", me);
                me->apply_condition("xuetang", 10);
                me->set_temp("xuet", 1);
                return 1;
        }
}

 int do_qingjiao(string arg)
{
       object me = this_player();
 	int myexp,daoxue,mypo;

	myexp = (int)me->query("combat_exp");
	daoxue = (int)me->query_skill("buddha",1);
	mypo = (int)me->query("potential");

      if( !arg || !arg = "tie")
          return notify_fail("����˭������ڷ�����\n");
     
      if( me->query_temp("qinjiao") < 1)
          return notify_fail("������ڷ�������ỹ��������!\n");

      command ("say ����,���Ѿ�����������ķ���İ���,��Ҫ����Ŭ��\n");
      command ("pat " + me->query("id"));
           me->set("combat_exp",myexp+daoxue+random(20));
//         if ( mypo < (int)me->query("learned_points"))
           me->set("potential",mypo+daoxue/2+random(10));
           me->set_temp("qinjiao",0);
	   me->set_temp("mcount",0);
                 
           return 1;
}