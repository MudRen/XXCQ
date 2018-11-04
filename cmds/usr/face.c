//face.c /cmds/usr/face.c �鿴emote,�Ǿ�ǧʥ��1999.12.2.
#include <ansi.h>
inherit F_CLEAN_UP;
int help();

void input_number(string arg);
void print_emote(mapping emote);
void show_emote(string * s,string st);

int main(object ob,string arg)
{
    //��Ҫ����ֱ��list emote�ġ���
    mapping emote;
    if(arg)
    {
        emote = EMOTE_D->query_emote(arg);
        if(sizeof(emote)>0)
            print_emote(emote);
        else{
            input_number(arg[0..0]);
            return 1;
        }
    }
    write("�����һ����ĸ��");
    input_to( (: input_number :));
    return 1;
}

void input_number(string arg)
{
    string * emotes, * selected;

    int i;
    if(arg=="") return;
    selected=({});
    emotes=EMOTE_D->query_all_emote();
    for(i=0;i<sizeof(emotes);i++)
    {
        if(emotes[i][0..0]==arg)
            selected += ({emotes[i]});
    }
    if(sizeof(selected)==0)
    {
        printf("û����%s��ͷ��emote.\n�����һ����ĸ��",arg);
        input_to((: input_number :));
        return ;
    }
    for(i=0;i<sizeof(selected);i++)
    {
        printf("%2d.%-15s",i+1,selected[i]);
        if(i%4==3)
            printf("\n");
    }
    write("\n");
    printf("����һ���أ�");
    input_to( (: show_emote,selected :) );
}

void show_emote(string * selected,string arg)
{
    mapping emote;
    string x;
    int i,index;
    if(arg=="")
    {
        write("\n�����һ����ĸ��");
        input_to( (: input_number :));
        return;
    }
    if(sscanf(arg,"%d",index)==1){
        if(index <= sizeof(selected) && index > 0)
        arg = selected [index-1];}
    else if(member_array(arg,selected)==-1)
    {
        write("û�����emote�������ĸ��أ�");
        input_to((: show_emote,selected :));
        return;
    }
    emote = EMOTE_D->query_emote(arg);
    if(sizeof(emote)>0)
        print_emote(emote);
         write ("\n�����һ����ĸ�����˳�ֱ���ûس�)");
    input_to( (: input_number :));
}

void print_emote(mapping emote)
{    
    int i;
    string x;
    string * key = ({ "myself","others","myself_self","others_self",
        "myself_target","target","others_target", });
    write(RED"����������п�����Щ���ԡ�����\n\n"NOR);
    for(i=0;i<sizeof(key);i++)
    {
        x=emote[key[i]];
        if(!x)
        {
            write("---\n");
            continue;
        }
        x = replace_string(x,"$N",HIR"�Ǿ�ǧʥ"NOR);
        x = replace_string(x, "$P", "��");
        x = replace_string(x, "$z", "����");
        x = replace_string(x, "$F", "����");
        x = replace_string(x, "$f", "����");
        x = replace_string(x, "$n", HIY"ɽè"NOR);
        x = replace_string(x, "$p", "��");
        write(x);
    }
}

int help()
{
        write(HIY @TEXT

ָ���ʽ��face ���ָ�����鿴emote��
               �˳�ʱֱ���ûس����ɡ�

TEXT NOR
        );
        return 1;
}

