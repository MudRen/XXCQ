#include <ansi.h>
static string *text;
static int f,line;
void more(string cmd)
{
	int i;

	switch(cmd)
	{
		case "b":
			line = line - 46;
			if(line < 0) line=0;
			write(ESC+"[1A"+ESC+"[200D"+ESC+"[K\n\n");
			for(i=line + 23; line < i;line++)
			{
				f?printf("%3d ",line+1):write("");
				write(text[line]+"\n");
			}
			break;
		case "q":
			write(ESC+"[1A"+ESC+"[200D"+ESC+"[K\n\n");
			return;
		case "n":
			f=!f;
			line=line-23;
		default:
			write(ESC+"[1A"+ESC+"[200D"+ESC+"[K");
			if(cmd&&sscanf(cmd,"%d",i))
				line=i;
			if(cmd == "$" )
				line=sizeof(text);
			if(line>=sizeof(text))
				line-=24;
			if(line < 0) line = 0;
			for(i=line + 23; line<sizeof(text) && line<i; line++)
			{
				f?printf("%3d ",line+1):write("");
				write(text[line] + "\n");
			}
			if( line>=sizeof(text) ) return;
			break;
	}
	printf("==δ�����"HIY"%d%%"NOR"==("+HIC+"q"+NOR+"�뿪��"+HIC+"b"+NOR+"ǰҳ"+
		HIC+"n"+NOR+"��ʾ�кţ����кţ�������ҳ)",
	(line*100/sizeof(text)) );
	input_to("more");
}
void start_more(string msg)
{
	write("\n");
	if(!(wizardp(this_object())&&this_object()->query("env/no_more_check"))&&(!msg||msg==""))
		msg="������Ϊ�գ��뱨����ʦ���һ�¡�\n";
	text=explode(msg,"\n");
	f=0,line=0;
	more("");
}

