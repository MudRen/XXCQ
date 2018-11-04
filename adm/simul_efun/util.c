// util.c

string process_bar(int n)
{
        string sp;
        int start;

        if (n < 0) n = 0; else
        if (n > 100) n = 100;

        sp = "                                                  " NOR;
        if (n == 100)
        {
                sp[22] = '1';
                sp[23] = '0';
                sp[24] = '0';
                sp[25] = '%';
                start = 22;
        } else
        if (n >= 10)
        {
                sp[23] = (n / 10) + '0';
                sp[24] = (n % 10) + '0';
                sp[25] = '%';
                start = 23;
        } else
        {
                sp[24] = n + '0';
                sp[25] = '%';
                start = 24;
        }

        n /= 2;
        if (start > n)
        {
                sp = sp[0..start-1] + HIY + sp[start..<0];
                sp = sp[0..n - 1] + BBLU + sp[n..<0];
        } else
        {
                sp = sp[0..n - 1] + BBLU + sp[n..<0];
                sp = sp[0..start-1] + HIY + sp[start..<0];
        }

        sp = NOR + BCYN + sp;
        return sp;
}

// sort a chinese string (must be chinese), align the
// string with then len. the prefix is used when the desc
// will be lead by another string or space with length is prefix.
string sort_string(string desc, int len, int prefix)
{
        int i;
        int l;
        int crlen;
        string msg;

        msg = desc;
        l = strlen(desc) + prefix;
        crlen = strlen("\n");
        for (i = len; i < l; i += len)
        {
                switch (msg[i - prefix..i - prefix + 1])
                {
                case "��":
                case "��":
                case "��":
                case "��":
                case "��":
                case "��":
                case "��":
                case "��":
                        i += 2;
                break;
                }

                if (i >= l)
                {
                        msg += "\n";
                        break;
                } else
                {
                        msg = msg[0..i - prefix - 1] + "\n" + msg[i - prefix..<0];
                        l += crlen;
                        i += crlen;
                }
        }

        if (i > l) msg += "\n";
        return msg;
}

object get_object(string name)
{
        object ob;
        if (ob = find_object(name))
                return ob;
        return load_object(name);
}

// calculate the color char in a string
int color_len(string str)
{
        int i;
        int extra;

        extra = 0;
        for (i = 0; i < strlen(str); i++)
        {
                if (str[i] == ESC[0])
                {
                        while((extra++, str[i] != 'm') && i < strlen(str))
                                i++;
                }
        }
        return extra;
}

