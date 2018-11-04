// natured.c
#include <ansi.h>
#define TIME_TICK (time()*60)

static int current_day_phase;
static string day_file;
mapping *day_phase;
mapping *read_table(string);
void init_day_phase();

void create()
{
        day_phase = read_table("/adm/etc/nature/day_phase");
        init_day_phase();
}
string query_day_file()
{
	return day_file;
}

void init_day_phase()
{
        mixed *local;
        int i, t;

        // Get minutes of today.
        local = localtime(TIME_TICK);
        t = local[2] * 60 + local[1];           // hour * 60 + minutes

        // Find the day phase for now.
        for( i=0; i < sizeof(day_phase); i++)
                if( t >= day_phase[i]["length"] )
                        t -= (int)day_phase[i]["length"];
                else
                        break;

        current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

        // Since in our time scale, 1 minute == 1 second in RL, so we don't need
        // any conversion before using this number as call_out dalay, if you
        // changed the time scale, be sure to convert it.

        call_out("update_day_phase",
      (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}
//write by JackyBoy@CuteRabbit Studio for CCTX 1999/6/4
string toColor(string arg)
{
	switch(arg)
	{
		case "BLK":arg=BLK;break;
		case "RED":arg=RED;break;
		case "HIR":arg=HIR;break;
		case "GRN":arg=GRN;break;
		case "HIG":arg=HIG;break;
		case "YEL":arg=YEL;break;
		case "HIY":arg=HIY;break;
		case "BLU":arg=BLU;break;
		case "HIB":arg=HIB;break;
		case "MAG":arg=MAG;break;
		case "HIM":arg=HIM;break;
		case "CYN":arg=CYN;break;
		case "HIC":arg=HIC;break;
		case "WHT":arg=WHT;break;
		case "HIW":arg=HIW;break;
		default:
			arg=HIG;break;
	}
	return arg;
}
		
int night()
{
	return (strsrch(CHINESE_D->chinese_date(TIME_TICK), "��ʱ") >= 0) ||
	(strsrch(CHINESE_D->chinese_date(TIME_TICK), "��ʱ") >= 0) ||
	(strsrch(CHINESE_D->chinese_date(TIME_TICK), "��ʱ") >= 0) ||
	(strsrch(CHINESE_D->chinese_date(TIME_TICK), "��ʱ") >= 0);
}
     
void update_day_phase()
{
    object *user=users();
    remove_call_out("update_day_phase");
	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	//day_phase��һ����mapping���ɵ�����

	//�����outdoor:vision�������ﶨ��ģ�
	message("outdoor:vision",HIG"��������"+toColor(day_phase[current_day_phase]["outcolor"])
    	+ day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
    //shout("׼������event_fun��\n");
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
    {
    	//shout("�����¼���"+day_phase[current_day_phase]["event_fun"]+"\n");
        call_other(this_object(), day_phase[current_day_phase]["event_fun"]);
    }
    call_out("update_day_phase", day_phase[current_day_phase]["length"]);
   	if(current_day_phase==2) 
   	{
   		CHANNEL_D->do_channel(this_object(),"sys","ϵͳ�Զ���� " + reclaim_objects() + " ��������\n");
	    remove_call_out("auto_save");
	    call_out("auto_save", 10, user, sizeof(user), 0);
	}
}
void event_midnight()
{
    string get_month, get_day;
    string day_phase_file;
    //shout("enent_midnight��ʼִ��\n");
    get_day = CHINESE_D->chinese_monthday(TIME_TICK);
    get_month = CHINESE_D->chinese_month(TIME_TICK);
    //shout("�·�Ϊ��"+get_month+"\n");
    switch(get_month)
    {
        //spring weather
        case "��":
        case "��":
        case "��":
             switch(random(3))
             {
                case 0:
                   day_phase_file="/adm/etc/nature/spring_rain";
                   break;
                case 1:
                   day_phase_file="/adm/etc/nature/spring_sun";
                   break;
                case 2:
                   day_phase_file="/adm/etc/nature/spring_wind";
                   break;
             }
             break;
        //summer weather
        case "��":
        case "��":
        case "��":
             switch(random(3))
             {
                case 0:
                   day_phase_file="/adm/etc/nature/summer_rain";
                   break;
                case 1:
                   day_phase_file="/adm/etc/nature/summer_sun";
                   break;
                case 2:
                   day_phase_file="/adm/etc/nature/summer_wind";
                   break;
             }
             break;
        //autumn weather
        case "��":
        case "ʮ":
        case "ʮһ":
             switch(random(3))
             {
                case 0:
                   day_phase_file="/adm/etc/nature/autumn_rain";
                   break;
                case 1:
                   day_phase_file="/adm/etc/nature/autumn_sun";
                   break;
                case 2:
                   day_phase_file="/adm/etc/nature/autumn_wind";
                   break;
             }
             break;
        //winter weather
        case "ʮ��":
        case "һ":
        case "��":
             switch(random(3))
             {
                case 0:
                   day_phase_file="/adm/etc/nature/winter_rain";
                   break;
                case 1:
                   day_phase_file="/adm/etc/nature/winter_sun";
                   break;
                case 2:
                   day_phase_file="/adm/etc/nature/winter_wind";
                   break;
             }
             break;
        default:
             day_phase_file="/adm/etc/nature/day_phase";
    }
    //shout("���ļ�"+day_phase_file);
    day_phase=read_table(day_phase_file);
}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

void event_noon()
{
    object *ob;
    int i,con,con1,con2,con3;
    string get_month,ill,msg;
    //shout("envent_noon��ʼִ��\n");
    get_month = CHINESE_D->chinese_month(TIME_TICK);
    //shout("�·�Ϊ��"+get_month+"\n");
    switch(get_month)
    {
        case "��":
        case "��":
        case "��":
             ill = "ill_kesou";
             msg = HIG + "��Ȼ��ͷһ���������о��ƺ�Ҫ�����ˡ�\n" + NOR;
             break;
        case "��":
        case "��":
        case "��":
             ill = "ill_zhongshu";
             msg = HIG+"ͻȻ������֮��һ���ڣ��������ˡ�\n" + NOR;
             break;
        case "��":
        case "ʮ":
        case "ʮһ":
             ill = "ill_shanghan";
             msg = HIG+"��������˸���ս��ͷ������ģ�����˺����ˡ�\n"+NOR;
             break;
        case "ʮ��":
        case "һ":
        case "��":
             ill = "ill_dongshang";
             msg = HIG+"����֫��ֱ�������㱻�����ˡ�\n"+NOR;
             break;
    }
    if(random(2))
    {
		ill = "ill_fashao";msg = HIG+"��ż�з纮����Ȼ����������\n"+NOR;
    }
    ob = users();
    for(i=0; i<sizeof(ob); i++)
    {
        if( !environment(ob[i]) ) continue;
        if( !environment(ob[i])->query("outdoors") ) continue;
        if( ob[i]->query("age")==14 ) continue;
        con1 = ob[i]->query("qi");
        con2 = ob[i]->query("max_qi");
        (int)con = con1/con2*50;//�γɵ�һ�������ж�����
        con3 = ob[i]->query("neili");
        con2 = ob[i]->query("max_neili");
		if( con2 == 0) con2 = 1;
        (int)con1 = con3/con2*50;//�γɵڶ��������ж�����
        if(random(con)+random(50)+random(con1)<25)
        {
                ob[i]->apply_condition(ill, 10);
                tell_object(ob[i], msg);
        }
    }
}

string outdoor_room_description()
{
        return "    " + day_phase[current_day_phase]["desc_msg"] + "��\n";
}
string outdoor_room_outcolor()
{
        return day_phase[current_day_phase]["outcolor"];
}

string game_time()
{
        return CHINESE_D->chinese_date(TIME_TICK);
}

mapping *read_table(string file)
{
    string *line, *field, *format;
    mapping *data;
    int i, rn, fn;
	day_file=file;
    line = explode(read_file(file), "\n");
    data = ({});
    for(i=0; i<sizeof(line); i++) {
        if( line[i]=="" || line[i][0]=='#' ) continue;
        if( !pointerp(field) ) {
                field = explode( line[i], ":" );
                continue;
        }
        if( !pointerp(format) ) {
                format = explode( line[i], ":" );
                continue;
        }
        break;//��ȡ���˺���ж�ѭ����i��ֵ��Ҫ����һ��ѭ�����ã�
    }//ȷ����ȡ�ĸ�ʽ

    for( rn = 0, fn = 0; i<sizeof(line); i++) {
        if( line[i]=="" || line[i][0]=='#' ) continue;
        if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
        sscanf( line[i], format[fn], data[rn][field[fn]] );
        fn = (++fn) % sizeof(field);
        if( !fn ) ++rn;
    }
    return data;
}

mapping *query_day_phase() { return day_phase; }

void auto_save(object *user, int size, int i)
{
    int j;
    
    for(j=i;j<i+5;j++) 
    {
		if(j>=size) return;
		if(!user[j]) continue;
		if(user[j]->save())
		    message("vision", RED"�����̾��顿"NOR+HIY"�Զ�������ϡ�\n"NOR,user[j]);
    }
    call_out("auto_save", 10, user, size, i+5);
}