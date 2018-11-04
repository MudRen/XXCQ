// score.c
 
#include <ansi.h>
#include <combat.h>
 
inherit F_CLEAN_UP;
 
string bar_string = "��������������������������������������������������";
string blank_string = "��������������������������������������������������";
 
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);
 
void create() { seteuid(ROOT_UID); }
 
int main(object me, string arg)
{
 object ob;
 mapping my;
 
 seteuid(getuid(me));
 
 if(!arg)
  ob = me;
 else if (wizardp(me)) {
  ob = present(arg, environment(me));
  if (!ob) ob = find_player(arg);
  if (!ob) ob = find_living(arg);
  if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
 } else
  return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
 
 my = ob->query_entire_dbase();
 

    printf("����������"HIM"��˽�˵�����"HIG"��������������\n"NOR);
    printf("��ͷ    �Σ�%-38s"HIG"��  ������[%s]  ���ԣ�[%s]\n",RANK_D->query_rank(ob),display_attr(my["str"], ob->query_str()), display_attr(my["int"], ob->query_int()),);
    printf("������������%-22s��  ���ǣ�[%s]  ����[%s]\n",ob->query("name"),display_attr(my["con"], ob->query_con()),display_attr(my["dex"], ob->query_dex()) );
    printf("��Ӣ�ģɣģ�%-22s��\n",ob->query("id") );
    printf("����    ��%-22s��\n",ob->query("gender") );
    printf("����ͨ��ν��%-22s��\n",ob->query("title") );
    printf("������������������������������������\n"NOR);
/*
 
 line = sprintf( "%s%s\n", RANK_D->query_rank(ob), ob->short(1) );
        line +=sprintf( HIY"��������������������������������������������������������������������\n"NOR);
     if (userp(ob))
 line += sprintf(HIM" ��    �䣺"NOR"%s��%s����"HIM" ��    ��"NOR"%s%s\n"HIM" �������֣�"NOR"%s\n",
  chinese_number(ob->query("age")), 
  chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200 + 1 ), 
  ob->query("gender"),
  ob->query("race"),
  CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
 else
 line += sprintf(HIM" ��    �䣺"NOR"%s��%s����"HIM" ��    ��"NOR"%s%s\n"HIM" �������֣�"NOR"%s\n",
  chinese_number(ob->query("age")), 
  ob->query("gender"),
  ob->query("race"),
  CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
        line +=sprintf( HIY"��������������������������������������������������������������������\n"NOR);
 
 if( 1 || wizardp(me) || (int)ob->query("age") >= 13 ) {
  line += sprintf(
   " ������[%s]  ���ԣ�[%s]  ���ǣ�[%s]  ����[%s]\n", 
   display_attr(my["str"], ob->query_str()),
   display_attr(my["int"], ob->query_int()),
   display_attr(my["con"], ob->query_con()),
   display_attr(my["dex"], ob->query_dex()));
 }
 
 if (userp(ob))
 {
  if( mapp(my["family"]) ) {
   if( my["family"]["master_name"] )
    line = sprintf("���ʦ����%s��",
     my["family"]["master_name"] );
  }
  if (!ob->query("couple/couple_name"))
  {
   if (ob->query("gender")=="Ů��")
    if (ob->query("age")<30) line += " �����ڴ��ֹ��С�\n";
    else line += " �����ڻ��Ǹ�������塣\n";
   else
   line += " �㻹�Ǹ������\n";
  }
  else
   line += " ��İ����� "+ob->query("couple/couple_name")+"��\n";
 }
 

 if( objectp(weapon = ob->query_temp("weapon")) )
  skill_type = weapon->query("skill_type");
 else
  skill_type = "unarmed";
 
 attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
 parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
 dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
 
    //if (wizardp(me))
 line += sprintf("\n ս�������� " HIW "%8d" NOR "\t\tս�������� " HIW "%8d\n" NOR,
  attack_points/100 + 1, (dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1,);
 line += sprintf(" ս���˺��� " HIW "%8d" NOR "\t\tս�������� " HIW "%8d\n\n" NOR,
  ob->query_temp("apply/damage"), ob->query_temp("apply/armor"));
    //else line += "\n";
 
 line += " <��>  " + tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], GRN) + "\n";
 line += " <��>  " + tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR) + "\n";
 line += " ʳ�" + tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\n";
 line += " ��ˮ��" + tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN) + "\n";
 
 line += sprintf("\n �㵽ĿǰΪֹ�ܹ�ɱ�� %d ���ˣ������� %d ����������ҡ�\n",
  my["MKS"] + my["PKS"], my["PKS"]);
 line += sprintf(" �㵽ĿǰΪֹ�ܹ����� %d ���ˣ������� %d ���Ƿ�����������\n\n",
  my["dietimes"] + my["normal_die"], my["dietimes"]);
 
 if (ob->query("shen") >=0)
  line += sprintf(" ��    ���� " RED "%8d\t" NOR, ob->query("shen") );
 else
  line += sprintf(" ��    ���� " RED "%8d\t" NOR, ob->query("shen") );
 
 line += sprintf(" Ǳ    �ܣ� " HIY "%3d (%3d%%)\n" NOR,
  (int)ob->query("potential") - (int)ob->query("learned_points"),
  (1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential")) );
 line += sprintf(" ʵս���飺 " HIM "%8d\t" NOR, ob->query("combat_exp") );
 line += sprintf(" ��    ���� " HIC "%8d\n" NOR, ob->query("meili") );
 line += sprintf(" ���������� " HIC "%8d\t" NOR, ob->query("score") );
 line += sprintf(" ���������� " HIC "%8d\n" NOR, ob->query("weiwang") );
  if ((int)ob->query("balance") > 0)
   line += " ��ӵ�д�" + MONEY_D->money_str((int)ob->query("balance")) + "��\n";
  else
   line += " ��û�д�\n";
 
 write(line);
*/
 return 1;
}
 
string display_attr(int gift, int value)
{
 if( value > gift ) return sprintf( HIY "%3d" NOR, value );
 else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
 else return sprintf("%3d", value);
}
 
string status_color(int current, int max)
{
 int percent;
 
 if( max ) percent = current * 100 / max;
 else percent = 100;
 
 if( percent > 100 ) return HIC;
 if( percent >= 90 ) return HIG;
 if( percent >= 60 ) return HIY;
 if( percent >= 30 ) return YEL;
 if( percent >= 10 ) return HIR;
 return RED;
}
 
string tribar_graph(int val, int eff, int max, string color)
{
 return color + bar_string[0..(val*25/max)*2-1]
  + ((eff > val) ? blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "") + NOR;
}
 
int help(object me)
{
 write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)
 
���ָ�������ʾ��(��)��ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help setup'��
 
see also : hp
HELP
);
return 1;
}
