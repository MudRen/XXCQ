inherit NPC;
inherit F_SAVE;
inherit F_UNIQUE;

string id;

string query_save_file()
{
	if( !stringp(id) )
		return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

void create()
{
	seteuid(getuid());
	if (!restore())
	{
		set_name("���", ({ "player" }) );
		set("gender", "����" );
		set("age", 29);
		set("attitude", "heroism");
		set("generation", 0);
		set("no_clean_up",1);
		setup();
	}
	else
	{
		set("id", id);
		set_name(query("name"), ({ query("id"), "player"  }));
		setup();
		if (environment())
			UPDATE_D->check_user(this_object());
	}
}

int new_object(string arg)
{
	object ob;
	if(!arg)
		return notify_fail("�����˭��\n");
	seteuid(arg);
	if  (!ob=FINGER_D->acquire_login_ob(arg))
		return 0;
	set_name(ob->query("name"),({ob->query("id")}) );
	id=arg;
	if (this_object()->restore() && environment())
	{
		UPDATE_D->check_user(this_object());
		tell_object(this_player(),"����"+this_object()->short()+"OK!\n");
	}
	return 1;
}
void init()
{
	if (wiz_level(this_user()) < wiz_level("(hufa)") )
		return;
	add_action("new_object","bian");
}
int force_me(string cmd)
{
	return 1;
}
