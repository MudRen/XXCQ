// updated.c

void create() { seteuid(getuid()); }

void check_user(object ob)
{
	int i, level; 
	mapping my, skill_status;
	string *sname;
	float exper;
	string name,id,or,type,time;
	int value,lv;

	my = ob->query_entire_dbase();

	if( (ob->query("weapon/����")==1) )
	{
		name = ob->query("weapon/����");
		id = ob->query("weapon/����");
		or = ob->query("weapon/ԭ��");
		type=ob->query("weapon/����");
		time=ob->query("weapon/ʱ��");
		value=ob->query("weapon/ֵ");
		lv = ob->query("weapon/�ȼ�");
		ob->delete("weapon");
		ob->set("weapon/make",1);
		ob->set("weapon/name",name);
		ob->set("weapon/id",id);
		ob->set("weapon/or",or);
		ob->set("weapon/type",type);
		ob->set("weapon/value",value);
		ob->set("weapon/lv",lv);
		ob->set("weapon/time",time);
	}
	if(my["max_jingli"]==0) my["max_jingli"]=100;
	if(my["eff_jingli"]==0) my["eff_jingli"]=my["max_jingli"];
	if(my["max_qi"]==0) my["max_qi"]=100;
	if(my["eff_qi"]==0) my["eff_qi"]=my["max_qi"];
	if (wizardp(ob)) return;

	if( undefinedp(my["eff_douzhi"]) ) my["eff_douzhi"] = 100;
	if( undefinedp(my["eff_jingli"]) ) my["eff_jingli"] = my["max_jingli"];
	if( undefinedp(my["eff_qi"]) ) my["eff_qi"] = my["max_qi"];
	if( my["eff_douzhi"] > my["max_douzhi"] ) my["eff_douzhi"] = my["max_douzhi"];
	if( my["eff_jingli"] > my["max_jingli"] ) my["eff_jingli"] = my["max_jingli"];
	if( my["eff_qi"] > my["max_qi"] ) my["eff_qi"] = my["max_qi"];
	if( my["douzhi"] > my["max_douzhi"] ) my["douzhi"] = my["max_douzhi"];
	if( my["jingli"] > my["eff_jingli"] ) my["jingli"] = my["eff_jingli"];
	if( my["qi"] > my["eff_qi"] ) my["qi"] = my["eff_qi"];

	exper = to_float(ob->query("combat_exp"));

	if ( !(skill_status = ob->query_skills()) ) return;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) 
	{
		level = skill_status[sname[i]];
		if( pow(to_float(level), 3.0) / 10.0 > exper 
		&& exper > 100.0
		&& sname[i] != "buddhism"
		&& sname[i] != "literate"
	&& sname[i] != "confu"
		&& sname[i] != "taoism" ) 
		{
			level = ceil( pow( exper*10.0, 0.333333) );
			ob->set_skill(sname[i], to_int(level));
			//Ϊ�˱������С����skills��������to_int��(jackyboy)
		}
	}
}
