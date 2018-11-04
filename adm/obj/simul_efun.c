//#pragma optimize all

#include "/adm/simul_efun/atoi.c"
#include "/adm/simul_efun/chinese.c"
#include "/adm/simul_efun/file.c"
#include "/adm/simul_efun/gender.c"
#include "/adm/simul_efun/object.c"
#include "/adm/simul_efun/path.c"
#include "/adm/simul_efun/user.c"
#include "/adm/simul_efun/wizard.c"
// This must be after gender.c
#include "/adm/simul_efun/message.c"
#include "/adm/simul_efun/sleeps.c"
#include "/adm/simul_efun/util.c"

void create()
{
	seteuid(getuid());
	write("simul_efun loaded successfully.\n");
}

void destruct(object ob)
{
	if (ob) {
		if( previous_object() ) ob->remove( geteuid(previous_object()) );
		else ob->remove(0);
	}
	efun::destruct(ob);
}
