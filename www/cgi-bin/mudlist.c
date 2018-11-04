// author: ken@XAJH2
 
#include <net/daemons.h>
#include <net/macros.h>
 
inherit F_CLEAN_UP;
 
private string get_mudlib(string s)
{
        switch (s[0..3])
        {
        case "Lima":
                return "<a href=http://lima.mudlib.org>Lima</a>";
        case "Nigh":
                return sprintf("<a href=http://www.imaginary.com/LPC/Nightmare/>%s</a>", s);
        case "Disc":
                return sprintf("<a href=http://www.imaginary.com:5678/>%s</a>", s);
        case "Tmi-":
                return sprintf("<a href=http://130.89.226.53:5550/>%s</a>", s);
        case "East":
                return sprintf("<a href=http://muds.net/>%s</a>", s);
        case "Xiao":
                return sprintf("<a href=http://www.chinesemud.net/>%s</a>", s);
        default:
                return "��";
        }
}

private string get_driver(string s)
{
        if( sizeof(s) < 4 )             s="unknow";
        switch (s[0..4])
        {
                case "MudOS":
                        return "<a href=http://imaginary.com/~beek/mudos>" + s + "</a>";
                default:
                        return "��";
        }
}

private string mail_link(string s)
{
        if( sizeof(s) < 3 )     return "��";
        return sprintf("<a href=mailto:%s>%s</a>", s, s);
}

private string web_link(string s)
{
        if( sizeof(s) < 4 )     return "��";
        return sprintf("<a href=%s>%s</a>", s, s);
}

string gateway(string pattern) 
{
        string  ret = "<body background=/images/body_bg.jpg><HEAD><TITLE>ͨ�� InterMud ��"MUD_NAME"���ߵ� Mud �б�</TITLE></HEAD>";
        mapping mudlist = DNS_MASTER->query_muds();
        int     i=0,nummuds = sizeof(mudlist);
        string  *muds = keys( mudlist );
        string  *matches;

        muds = sort_array(muds, 1);

        if ( !pattern )
                matches = muds;
        else
        {
                if( !mapp(mudlist[pattern]) )
                        return "<h3>û���ҵ���</h3>";

                matches = mudlist[pattern];
                ret += sprintf("<center><TABLE BORDER=5><caption><h2><a href="
                                "telnet://%s:%s>%s</a></h2></caption>"
                                "<TR><TH>Current Mudlib</TH><TD>%s</TD></TR>"
                                "<TR><TH>Base Mudlib</TH><TD>%s</TD></TR>"
                                "<TR><TH>Server</TH><TD>%s</TD></TR>"
                                "<TR><TH>Language</TH><TD>%s</TD></TR>"
                                "<TR><TH>Admin Email</TH><TD>%s</TD></TR>"
                                "<TR><TH>Mudlib web</TH><TD>%s</TD></TR>"
                                "<TR><TH>Online user</TH><TD>%s</TD></TR>"
                                "<TR><TH>Local Time</TH><TD>%s</TD></TR>"
                                "</TABLE></center>",
                                mudlist[pattern]["HOSTADDRESS"],
                                mudlist[pattern]["PORT"],
                                undefinedp( mudlist[pattern]["MUDNAME"] ) ? pattern : mudlist[pattern]["MUDNAME"],
                                mudlist[pattern]["VERSION"],
                                get_mudlib( mudlist[pattern]["MUDLIB"] ),
                                get_driver( mudlist[pattern]["DRIVER"] ),
                                undefinedp(mudlist[pattern]["ENCODING"])? "default": 
                                        (mudlist[pattern]["ENCODING"]=="GB"?"���庺��":"���庺��"),
                                mail_link( mudlist[pattern]["ADM_EMAIL"] ),
                                web_link( mudlist[pattern]["MUDLIB_WEB"] ),
                                undefinedp( mudlist[pattern]["USERS"] ) ? "��" :        mudlist[pattern]["USERS"],
                                undefinedp( mudlist[pattern]["TIME"] ) ? "��" : mudlist[pattern]["TIME"],
                                );
                        return ret;
        }
  
        matches = filter_array(matches, (: $(mudlist)[$1]["_dns_no_contact"] == 0 :));

        ret += sprintf("<h3 align=center><font face='��Բ' color=#ff0000>%s"
                                "<font face='��Բ'color=#000000>��������б�</font>"
                                "</h3><hr>",CHINESE_MUD_NAME);

        ret += "<center><TABLE BORDER=1><br><font size=3 face=����>";

        foreach ( string mudname in sort_array(matches, 1) )
        {
                ret += sprintf("<td><font size=3 face='��Բ'>"
                                "<a href=mudlist.c?%s <em>%s</em></a></font>",
                                mudname,
                                undefinedp( mudlist[mudname]["MUDNAME"] ) ? mudname : mudlist[mudname]["MUDNAME"]
                                );

                if( i%3 == 2 )
                        ret += "<tr>";
                i++;
        }
        ret += "</TABLE></center>";

        ret += sprintf("<p><hr></p><p><font size=2 face='��Բ' color=#000000>���� "+
                        sizeof(mudlist)+ " �� Mud ������ InterMud������ "+
                        sizeof(matches)+" �� Mud �� <font size=2 face='��Բ' color=#FF0000>"
                        "%s</font> ���ߡ�</font></p></body>",
                        CHINESE_MUD_NAME
                        );


        return ret;
}
